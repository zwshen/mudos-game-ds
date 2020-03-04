#include <ansi.h>
inherit NPC;
int service();
int service1(object,int);
int service2(object,int,int);
int service3(object,int,int);
void create()
{
        set_name(HIW"瑞希"NOR , ({"reihi"}));
        set("long",@LONG
    在你面前的是「凡琴斯島」旅社的老闆娘，米黃色的長髮挽在腦後梳
成一個髻，親切的笑容及動聽的聲音讓人忘卻疲勞，她給人的感覺就是悠
閒以及緩慢，但是從來沒人抱怨她的服務，事實上面對如此多的客人，她
也總是應付的來。在她沒有事情的時候，她總是一邊看著牆上的壁畫出神
，一邊哼著一首不知名的曲子。

    你可以用"lodge 價錢"來向瑞希訂房。
LONG
);
       set("gender","女性");
       set("age", 31);
       set("level", 10);

       set("chat_chance", 3);
       set("chat_msg", ({
            "瑞希輕輕哼著曲子:「啦∼啦啦∼啦∼∼∼啦啦∼∼∼∼」\n",
	    "瑞希從廚房端出剛做好的料理。嗯∼好香喔！\n",
            "瑞希輕巧的遊走在客人之間。\n"
             }));
        set("inquiry",([
  "價錢" : "嗯...我們有三種價錢的服務...讓我看看...分別是100元、500元以及1000元。",
  "訂房" : "請輸入lodge加上您所要付的價錢...謝謝！(瑞希給你一個親切的微笑。)",
  "曲子" : "啊！這曲子...這曲子是....嗯...一個...朋友...寫給我的....",
  "凡琴斯島" : "這個傳說很美吧！我們店裡正好有吟遊詩人，您可以聽聽她唱這個傳說。",
  "服務" : "100元的服務是一份豐盛的餐\點，500元可以在房內充分的休息，過夜則是1000元，謝謝。",
]));
        setup();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                command("say 啊...歡迎光臨...");
                command("smile");
        }
        add_action("do_lodge","lodge");
}

int do_lodge(int arg)
{
        object ob=this_player();
        int num;
         if(!arg) return notify_fail("你未輸入你想付的價錢。\n");
        if(sscanf(arg, "%d", num)==1) {
        if (num < 100) return notify_fail("瑞希:「啊....最低消費額是100元整...」\n");
                if( !ob->can_afford(num) )  return notify_fail("你沒帶那麼多錢！\n");

                ob->set_temp("lodge_level",num );
                ob->receive_money(-(ob->query_temp("lodge_level")));
                tell_object(ob,"瑞希:「我們會根據您所付的價錢來提供合適的服務。」\n");
                service();
                return 1;
        }
        return 0;
}
int service()
{
        object ob;
        int x,b;
        ob=this_player();
        x = ob->query_temp("lodge_level");
        if (x > 1000) x = 1000;
        ob->set_temp("lodge_level",x );
        b = (x/100);
        tell_object(ob,"瑞希將你帶到一個空位坐下。\n");
        ob->set_temp("is_busy/lodge","你的大餐\還沒來，再等等吧！");
        call_out("service1",b,ob,b);
} 
int service1(object ob,int b)
{
        tell_object(ob,"服務生將餐\點端了出來，嗯∼好香喔！\n");
        if(b > 5) b= 5;
 if(b!=0) {
        tell_object(ob,HIM"你在舒適的環境下津津有味吃著豐盛的餐\點。\n"NOR);
        ob->set_temp("is_busy/lodge","你正在吃飯。");
        ob->receive_heal("hp",(ob->query_con()/2));
        b--;
        call_out("survice1",2,ob,b);
        }
 else { 
        if(ob->query_temp("lodge_level")>499)
        {
                call_out("service2",2,ob,(ob->query_temp("lodge_level")),5);
                return 1;
        }
        else{
                tell_object(ob,"嗯∼∼吃的真飽。\n");

                ob->delete_temp("is_busy/sleeping");
                ob->delete_temp("lodge_level");
                ob->receive_heal("hp",20);
                tell_object(ob,"瑞希微笑著:「謝謝光臨。」\n");
                return 1;
        }
      }

}
int service2(object ob,int b,int t)
{
        tell_object(ob,HIB"服務生看你吃完了，便帶你到二樓的房間中\n"NOR);
        ob->set_temp("is_busy/lodge","別急，慢慢休息。");
        ob->move(__DIR__"npc/obj/hotel_room");
        
         if(b!=0) {
                switch(random(7))
                {
                case 1: tell_object(ob,YEL"你躺在舒適的床上滾來滾去。\n"NOR );break;
                case 2: tell_object(ob,CYN"你聽著外面傳來的優美歌聲。\n"NOR );break;
                case 3: tell_object(ob,HIB"你正欣賞這房間內的擺\飾。\n"NOR );break;
                case 4: tell_object(ob,GRN"你斜躺在床上看著小說。\n"NOR );break;
                case 5: tell_object(ob,HIG"你站起來伸了伸懶腰。\n"NOR );break;
                case 6: tell_object(ob,HIY"你放鬆全身的肌肉，開始發呆。\n"NOR );break;
		case 0: tell_object(ob,HIC"你靠在窗邊，看著來來往往的人群。\n"NOR );break;
                }
        t--;
        call_out("survice2",5,ob,b,t);
                }
         else { 
                if(ob->query_temp("lodge_level")>999)
                {
                        call_out("service3",2,ob,(ob->query_temp("lodge_level")),10);
                        return 1;
                }
                else{
                        tell_object(ob,"你經過休息後，精神飽滿。\n");
                        tell_object(ob,"你到櫃檯辦理退房。\n");
                        ob->move(__DIR__"port_24");
                        ob->delete_temp("is_busy/sleeping");
                        ob->delete_temp("lodge_level");
                        ob->receive_heal("hp",(b+50));
                        ob->receive_heal("ap",(b+30));
                        ob->receive_heal("mp",(b+20));
                        tell_object(ob,"瑞希微笑著:「謝謝光臨。」\n");
                        return 1;
                }
        }

}
int service3(object ob,int b,int t)
{       
         tell_object(ob,BLU"你倒在床上沒多久，就進入了甜蜜的夢鄉。\n"NOR);
         ob->set_temp("is_busy/lodge","別鬧了，你正在睡覺。");
        
         if(b!=0) {
                switch(random(7))
                {
                case 1: tell_object(ob,CYN"羊跳過了柵欄.....。\n"NOR );break;
                case 2: tell_object(ob,HIW"鴿子飛過了煙囪.....。\n"NOR );break;
                case 3: tell_object(ob,YEL"咖哩飯從腳邊跑了過去.....。\n"NOR );break;
                case 4: tell_object(ob,GRN"史萊姆從腦中不斷湧出.....。\n"NOR );break;
                case 5: tell_object(ob,HIM"一位美麗的公主....正在跳脫衣舞....。\n"NOR );break;
                case 6: tell_object(ob,MAG"一個英俊的王子....正表演猛男秀....。\n"NOR );break;
		case 0: tell_object(ob,RED"你夢見DS的豬頭們以及他們說的冷笑話.....\n"NOR );break;
                }
        t--;
        call_out("survice3",10,ob,b,t);
                }
         else { 
                        tell_object(ob,"睡了一覺，你覺得全身充滿了活力。\n");
                        tell_object(ob,"你到櫃檯辦理退房。\n");
                        ob->move(__DIR__"port_24");
                        ob->delete_temp("is_busy/sleeping");
                        ob->delete_temp("lodge_level");
                        ob->receive_heal("hp",(b+200));
                        ob->receive_heal("ap",(b+150));
                        ob->receive_heal("mp",(b+150));
                        tell_object(ob,"瑞希微笑著:「謝謝光臨。」\n");
                        return 1;
                }
        

}
