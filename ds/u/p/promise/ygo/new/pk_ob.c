// this is a ob wrote by saveob
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("決鬥石碑",({ "stele", "ste","s"}));
        set_max_encumbrance(1000000);
        set_weight(1);
        set("lock",1);
        if(clonep())
           set_default_object(__FILE__);
        else{
        
           set("long","
遊戲怪獸卡決鬥使用流程：

1 .決鬥限定兩名玩家，可以用 <blist> 指令來顯示目前是否有玩家參與決鬥
2 .若無人在決鬥，可使用 <addin> 指令開新決鬥
3 .使用 <view> 或快速鍵 <v> 指令瀏覽戰場
4 .使用 <view hand> 或快速鍵 <v hand> 指令瀏覽手牌和編號
        <view die> 查看墳場裡有哪些卡
5 .使用 <dump> 來出牌，指令格式 dump <手牌編號> (defend)
6 .使用 <cpk> 指令命令自己的戰鬥怪獸攻擊對方怪獸或直接玩家本人
   <cpk 我方怪物編號 敵方怪物編號>  <pk 我方怪編號 10>
7 .使用 <magic> 可以打出魔法卡 magic <手牌編號> <怪物編號>
8 .使用 <tactic 怪物編號> 指令可以切換場上戰鬥怪獸的攻擊守備狀態
9 .使用 <add> 指令來補充丟出的手牌，第一回合亦先使用此指令抽牌
   注意：抽牌後便不能再做任何行動，只能 <over> 換下一位玩家行動
10.使用 <over> 指令結束回合，換下一位玩家行動
11.當你覺得你毫無勝算後，你可以使用覆牌 <cover> 的動作來認輸
12.使用 <history> 指令可以查詢自重新啟動到現在的戰績表
");
           set("unit","個");
           set("unit","個");
           set("value",1);
           set("no_get",1);
        }
}

void init()
{
        add_action("do_list","blist");
        add_action("do_cover","cover");
        add_action("do_addin","addin");
        add_action("do_view","view");
        add_action("do_dump","dump");
        add_action("do_magic","magic");
        add_action("do_tactic","tactic");
        add_action("do_add","add");
        add_action("do_over","over");
        add_action("do_pk","cpk");
        add_action("do_go","go");
        add_action("do_view","v");
        add_action("do_history","history");
}

int game_over(object me)
{
   object *inv;
   int i;
        message_vision("尤於其中一名玩家離開了決鬥區,因此決鬥取消了...\n",me);

        delete("1p"); delete("2p");
        delete("1p_hp"); delete("2p_hp");
        delete("1p_mhand"); delete("2p_mhand");
        delete("1p_mpk"); delete("2p_mpk");
        delete("player"); delete("earth");
        delete("round"); delete("check_round"); 
        delete("hcards");  delete("cards"); 

        inv = all_inventory();
        for(i=0;i<sizeof(inv);i++) {
           destruct(inv[i]);
        }

        message_vision(HIR"\n場上所有戰鬥怪獸不一會全部消失了。\n"NOR, this_player());

        return 1;
}

object *query_cards(string kind)
{
   object *cards;
   int i;
   object *m_cards=({}),*t_cards=({}),*p_cards=({}),*d_cards=({});
          //m_cards:使用中的魔法卡,t_cards:使用中的陷阱卡,p_cards:怪物卡,d_cards:墳場的卡

        cards=all_inventory();//取得所有場上卡片資料(包含活著或死去的怪物,魔法卡,陷阱卡)
        for(i=0;i<sizeof(cards);i++){
          if(cards[i]->query("die")){ //送入墳場的怪物
            d_cards+=({cards[i]});  continue; }
          if(cards[i]->query("attrib")){//怪獸卡
            p_cards+=({cards[i]});  continue; }
          if(cards[i]->query("magic")){//魔法卡使用中
            m_cards+=({cards[i]});  continue; }
          if(cards[i]->query("trap")){//陷阱卡使用中
            t_cards+=({cards[i]});  continue; }
        }
        if(kind=="magic") cards=m_cards;
        if(kind=="die") cards=d_cards;
        if(kind=="trap") cards=t_cards;
        if(kind=="pk") cards=p_cards;
        return cards;
}


int do_list(string arg)
{
   object p1,p2;

        p1=query("1p");
        p2=query("2p");
        if(!p1) return notify_fail("目前決鬥場上沒有玩家。\n");
        else if(p1 && !p2) 
           return notify_fail("目前決鬥場上有一位玩家"+HIY+p1->name()+NOR+"正在等待對手。\n");
        else return notify_fail("目前決鬥場上有一位玩家"+HIY+p1->name()+
                NOR+"和另一位玩家"+HIY+p2->name()+NOR+"正在互相較勁。\n\n"+
                HIY+p1->name()+NOR+"的牌組裡還有"+HIR+chinese_number(sizeof(query("cards/1p")))
                +NOR+"張牌，而"+HIY+p2->name()+NOR+"的牌組裡還有"+HIR+
                chinese_number(sizeof(query("cards/2p")))+NOR+"張牌\n");
        return 1;
}

int do_addin(string arg)
{
   object env,me,p1,p2,book_1,book_2;
   string *earth_name = ({ "荒野","草原","沼澤","山谷","森林","沙漠","墳場","洞穴","海洋" });
   string earth = earth_name[random(sizeof(earth_name))];
   int i;
   mapping datas,cards=(["1p":([]),"2p":([])]);
   string *card;

        me = this_player();
        env=environment(this_object());

        p1=query("1p");
        p2=query("2p");
        if(!present("card book",me)) return notify_fail("你先去弄一套牌組再來決鬥吧！\n");
        if(!p1){
           set("1p",me);
           set(me->query("id"),"1p");
           message_vision(HIY"\n$N"HIY"站上決鬥台，大喊：有沒有人敢跟我"+me->name()+"來一盤決鬥啊！\n"NOR, me);
        } else if(p1 && !p2) {
           if(me == p1) return notify_fail("你已經參與決鬥了呀！\n");
           set("2p",me);
           set(me->query("id"),"2p");
           message_vision(HIY"\n$N"HIY"站上決鬥台，叫囂道："+p1->name()+"！我"+me->name()+"來跟你玩！\n"NOR,me);
           p1 = present(query("1p"),env);
           p2 = present(query("2p"),env);
           if(!p1 || !p2) return notify_fail("有一位決鬥者不知跑哪裡去了...=.=\n");
           message_vision(HIG"\n$N"HIG"說道："NOR"決鬥！\n", p1);
           message_vision(HIG"\n$N"HIG"說道："NOR"決鬥！\n", p2);
           tell_object(p1,HIC"\n你將你的牌組放置在機器上，電腦瞬間將你的牌組資料記錄下來。\n"NOR);
           tell_object(p2,HIC"\n你將你的牌組放置在機器上，電腦瞬間將你的牌組資料記錄下來。\n"NOR);

           book_1=present("card book",p1);//取得戰鬥牌組資料
           book_2=present("card book",p2);

           datas=book_1->query_fcards();//將戰鬥牌組資料記入此物件中
           card=keys(datas);
           for(i=0; i<sizeof(card); i++) {
             cards["1p"][card[i]]=1;
           }
//         set("1p_num",sizeof(card));
           datas=book_2->query_fcards();//將戰鬥牌組資料記入此物件中
           card=keys(datas);
           for(i=0; i<sizeof(card); i++) {
             cards["2p"][card[i]]=1;
           }
           set("cards",cards);
           set("hcards",(["1p":([]),"2p":([])]));

           if(random(2) == 1) {
                message_vision(HIW"\n本次決鬥由 "+HIG+"$N"+HIW" 開始抽牌"NOR,p1);
                tell_object(p1,"(add)");
                set("player",p1);
           } else {
                message_vision(HIW"\n本次決鬥由 "+HIG+"$N"+HIW" 開始抽牌"NOR,p2);
                tell_object(p2,"(add)");
                set("player",p2);
           }
           set("earth",earth);
           message_vision(HIW"，而決鬥的場地為隨機抽樣的 「"+earth+"」！！\n"NOR,me);
           set("1p_mhand",5);//最大手牌數量
           set("2p_mhand",5);
           set("1p_mpk",5);//最大場上怪獸數量
           set("2p_mpk",5);
           set("die_cards",([]));
           set("magic",({}));
           set("1p_hp",8000);
           set("2p_hp",8000);
//         set("check_round",1);
        } else {
           if(me == query("1p") || me == query("2p"))
                return notify_fail("你已經身處決鬥台上了。\n");
           write("目前已有兩位玩家在使用決鬥場。");
           message_vision(HIR"\n$N"HIR"哭哭啼啼的喊道：我也要玩啦∼∼\n"NOR,me);
        }
        return 1;
}




string list_hcard(object ob)
{
   mapping data;
   string *card;
   string str="",who;
   int i;

        who=query(ob->query("id"));
        data=query("hcards/"+who);
        if(sizeof(data)<1) return "";
        card=keys(data);
        for(i=0;i<sizeof(card);i++){
          str+="\t"+"("+i+") "+card[i]->name()+"\n\t\t\t";
          if(card[i]->query("attrib"))
            str+=card[i]->query("attrib")+HIR" 攻擊力；"+card[i]->query("ap")+NOR
               +"，"+HIB"守備力；"+card[i]->query("dp")+NOR""+
               (card[i]->query("doc")?("\n\t\t\t"+card[i]->query("doc")):"")+"\n";
          else str+=card[i]->query("doc")+"\n";
        }
        return str;
}

string list_card(object card,string p,string owner,int i)
{
//卡片的顯示 傳入:卡片物件 && 文字("1p"或"2p")

   string str="";

//      if(card->query("magic")) return "";
        if(card->query("owner")==owner){
           if(card->query("owner")==p){
             str+="("+i+")";
             str+=card->query("defend")?HIG"<守>":"    ";//防守
             str+=card->query("attrib")+card->short();
             str+="\t"HIR"攻擊力："+card->query("ap")+HIB"\t守備力："+card->query("dp")+NOR;
             str+=card->query("hide")?HIM"(覆蓋\著)"NOR:"";
             str+="\n";
           }else return "";
        }else{
           if(card->query("owner")==p){
             str+="("+i+")";
             str+=(card->query("defend")?HIG"<守>":"    ");//防守
             if(card->query("hide"))
                str+=BLK"[？]"NOR+"覆蓋\的守備怪獸卡(Unknow card)\n";
             else{
               str+=card->query("attrib")+card->short();
               str+="\t"HIR"攻擊力："+card->query("ap")+HIB"\t守備力："+card->query("dp")+NOR;
               str+="\n";
             }
           }else return "";
        }
        return str;
}

int get_amount(string user,object *cards)//取得戰鬥場上的怪物數量;user="1p" or "2p"
{
   int i,count=0;

        for(i;i<sizeof(cards);i++){
           if(cards[i]->query("owner")!=user) continue;
//         if(cards[i]->query("magic")) continue;//正在使用魔法當中
           count++;
        }
        return count;
}

int do_view(string arg)
{
   object env,me,a,b,*cards;
   int i;
   string str="",str2="",round,p;

        me = this_player();
        env = environment(me);

        if(!query("1p") || !query("2p")) return notify_fail("目前決鬥台上沒有決鬥。\n");

        a = present(query("1p"),env);
        b = present(query("2p"),env);

//      if(me!=a && me!=b) return 0;

        if(!a||!b) return game_over(me);

        if(arg=="hand") {
           write("你手中的卡有：\n");
           write(list_hcard(me));
           return 1;
        }
        if(arg=="die"){
           write("在墳場的卡有：\n");
           cards=query_cards("die");
           if(sizeof(cards)<1) return 1;
           for(i=0;i<sizeof(cards);i++){
             write("\t("+i+") "+cards[i]->name()+"\n");
           }
           return 1;
        }

        p=query(me->query("id"));
//      cards = all_inventory();
        cards=query_cards("pk");
        if(sizeof(cards)>0){//玩家所看到的狀況
           for(i=0;i<sizeof(cards);i++){
//           str+="("+i+")"+list_card(cards[i],query(a->query("id")),p);
//           str2+="("+i+")"+list_card(cards[i],query(b->query("id")),p);
             str+=list_card(cards[i],query(a->query("id")),p,i);
             str2+=list_card(cards[i],query(b->query("id")),p,i);
           }
        }

        if(me!=a && me!=b){
          str="";
          str2="";
          if(sizeof(cards)>0){//旁觀者所看到的狀況
             for(i=0;i<sizeof(cards);i++){
               str+=list_card(cards[i],query(a->query("id")),"3p",i);
               str2+=list_card(cards[i],query(b->query("id")),"3p",i);
             }
          }
        }

        write(str);
        write("□�����������������������������������������������������������������������龤� \n");
        if(strlen( a->query("id") ) < 8)
                write("�齱@　　決鬥者："+a->query("id")+"\t\t生命值："HIB+query("1p_hp")+NOR" 分");
        else
                write("�齱@　　決鬥者："+a->query("id")+"\t生命值："HIB+query("1p_hp")+NOR" 分");

        if(query("player") == a)
                write("　　"HIR"● 攻擊"NOR"　　"BLU"○ 等待"NOR"     �鱋n");
        else
                write("　　"RED"○ 攻擊"NOR"　　"HIC"● 等待"NOR"     �鱋n");

        if(!query("round")) round = " "HIC"雙方抽牌"NOR" ";
        else if(strlen(chinese_number(query("round"))) == 2)
                round = "　　"+HIM+chinese_number(query("round"))+NOR+"　　";
        else if(strlen(chinese_number(query("round"))) == 4)
                round = "　 "+HIM+chinese_number(query("round"))+NOR+" 　";
        else if(strlen(chinese_number(query("round"))) == 6)
                round = "　"+HIM+chinese_number(query("round"))+NOR+"　";
        else if(strlen(chinese_number(query("round"))) == 8)
                round = " "+HIM+chinese_number(query("round"))+NOR+" ";
        else if(strlen(chinese_number(query("round"))) == 10)
                round = ""+HIM+chinese_number(query("round"))+NOR+"";

write("□�����������������������稙������������������������稙��������������������龤� \n");
write("�齱@　"HIY"１Ｐ魔法陷阱卡"NOR"　　�齱@　　　　　　　　　　　�齱@　　　　　　　　　　��
�僓����������������������潳c▂▂▂▂▂▂▂▂▂▂▂�僓�����������������������
�齱@　　　　　　　　　　�齱耦哄@　　　　　　　◥■�齱@　　　　　　　　　　��
�僓����������������������漶翩@　　　　　　　　　■�僓�����������������������
�齱@　　　　　　　　　　�齱翩@　 場地："+query("earth")+" 　　■�齱@　　　　　　　　　　��
�僓����������������������漶翩@　　　　　　　　　■�僓�����������������������
�齱@　　　　　　　　　　�齱翩@回合："+round+"　■�齱@　　　　　　　　　　��
�僓����������������������漶翩@　　　　　　　　　■�僓�����������������������
�齱@　　　　　　　　　　�齱耦岷c▂▂▂▂▂▂▂◢■�齱@　　　　　　　　　　��
�僓����������������������漶@　　　　　　　　　　　�僓�����������������������
�齱@　　　　　　　　　　�齱@　　　　　　　　　　　�齱@　"HIW"２Ｐ魔法陷阱卡"NOR"　　��
");

        write("□�����������������������嘵������������������������嘵��������������������龤� \n");
        if(strlen( b->query("id") ) < 8)
                write("�齱@　　決鬥者："+b->query("id")+"\t\t生命值："HIB+query("2p_hp")+NOR" 分");
        else
                write("�齱@　　決鬥者："+b->query("id")+"\t生命值："HIB+query("2p_hp")+NOR" 分");

        if(query("player") == b)
                write("　　"HIR"● 攻擊"NOR"　　"BLU"○ 等待"NOR"     �鱋n");
        else
                write("　　"RED"○ 攻擊"NOR"　　"HIC"● 等待"NOR"     �鱋n");

        write("□�����������������������������������������������������������������������龤墦n");
        str = "";
        write(str2);
        return 1;
}

int do_over(object me)
{
   string *saying_name = ({ "我這一回合已經結束了！","換你出牌！放馬過來吧！",
                            "我這回合牌出完了！換你！","我這回合到此為止，該你！" });
   string saying = saying_name[random(sizeof(saying_name))];
   string p;
   object next;
   object *magic;
   int i;
   object *cards;

        if(!me) me=this_player();
//      write(query("player")->name());
        if(me != query("player")) return notify_fail("現在不是輪到你說話。\n");

        message_vision(HIW"\n$N"HIW"大喊："+NOR+saying+"\n", me);

        p=query(me->query("id"));
        if(p=="1p") next=query("2p");
        else next=query("1p");
        tell_object(next,HIG"輪到你的回合開始了。\n"NOR);
        set("player",next);

        if(query("check_round")>0){
          set("check_round",0);
          add("round",1);
        }else add("check_round",1);
        delete("dump");
// ***************************** 卡片特殊功能(start) *****************************
        if(magic=query("magic")){//共通魔法
            for(i=0;i<sizeof(magic);i++){
//            magic[i]->check_magic(this_object(),me,"over",0);//再次啟動魔法
              if(!objectp(magic[i])) continue;
              if(magic[i]->check_magic(this_object(),me,0,0,"over")) return 1;//再次啟動魔法
            }
        }
// ***************************** 卡片特殊功能(end) *****************************   
        cards=query_cards("pk");
        if(sizeof(cards)>0){
           for(i=0;i<sizeof(cards);i++){
                cards[i]->delete("act");
           }
        }

        return 1;
}

int do_add(string arg)//抽牌
{
   object me,a,b,player;
   int i,hnum,cnum,n,max_hand;
   string p;
   mapping data=([]),hcards=([]);
   string *card;

        me = this_player();

        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;

        player=query("player");
        if(player!=me) return notify_fail("現在不是輪到你說話。\n");;
        p=query(me->query("id"));

        data=query("cards/"+p);//取得牌組資料
        hcards=query("hcards/"+p);//取得手牌資料
        hnum=sizeof(hcards);
        cnum=sizeof(data);
        max_hand=query(p+"_mhand");//取得最大手牌數量

        if(hnum==max_hand) return notify_fail("你的手牌數量已經滿了!!\n");;

        if((max_hand-hnum)>cnum){//牌組數量小於抽牌數
           if(query("1p")==me)
             message_vision(HIG"\n"+query("1p")->short()+"抽到沒牌了，很可惜他輸了，勝利者是"+query("2p")->short()+"！！恭喜恭喜！！\n"NOR, me);
           else
             message_vision(HIG"\n"+query("2p")->short()+"抽到沒牌了，很可惜他輸了，勝利者是"+query("1p")->short()+"！！恭喜恭喜！！\n"NOR, me);
           call_out("lost",0,me);
           return 1;
        }

        message_vision(HIG"\n$N"HIG"抽了牌補到自己的手牌中\n"NOR,me);
        if(sizeof(hcards)<1) hcards=([]);
        for(i=0;i<(max_hand-hnum); i++){//抽牌
          card=keys(data);
          n=random(sizeof(data)-1);
          hcards[card[n]]=p;
          write("你抽到一張"+card[n]->name()+"\n");
          map_delete(data,card[n]);
        }
        set("cards/"+p,data);
        set("hcards/"+p,hcards);

        write("OK.你的牌組尚有"+chinese_number(sizeof(data))+"張卡片。\n");
        do_over(me);
        if(sizeof(data)<5) write(HIR"警告！！你牌組中的備牌張數已經快要抽完，請注意。\n"NOR);
        return 1;
}

int do_dump(string arg)
{
   object me,a,b,*cdata,ob,m,player;
   string *saying_name = ({ "看我的，","出來吧！","召喚－－","我使用","看清楚！這就是我的.." });
   string saying = saying_name[random(sizeof(saying_name))];
   int i,num,size,max_pk;
   mapping hcards;
   string *card,p,def;
   object *magic;

        me = this_player();

        ob=this_object();
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;

        player=query("player");
        if(player!=me) return notify_fail("現在不是輪到你說話。\n");

        if(query("dump")) return notify_fail("你這回合已經召喚過戰鬥怪獸了！\n");;

        p=query(me->query("id"));

        if(!arg) return notify_fail("指令格式 dump + 手牌編號 (可用 view hand 察看)\n");

//      cdata = all_inventory();//取得戰場上的卡片資料
        cdata = query_cards("pk");//取得戰場上的卡片資料
        max_pk=query(p+"_mpk");//取得最大場上怪獸數量
        if(get_amount(p,cdata)>max_pk) return notify_fail("你的檯面上的戰鬥卡已經塞滿了!!\n");

        if(!sscanf(arg,"%d %s",num,def)) sscanf(arg,"%d",num);//取得卡片編號
        hcards=query("hcards/"+p);//取得手牌資料
        size=sizeof(hcards);
        if(sizeof(hcards)<1) return notify_fail("你的手中已經沒有牌可以使用了!!\n");
        card=keys(hcards);
        if(num>(size-1) || num<0) return notify_fail("指令格式 dump + 手牌編號 (可用 view hand 察看)\n");
        if(card[num]->query("kind")=="magic")
           return notify_fail("dump是用來出怪獸卡和陷阱卡的，魔法卡請用專用指令！\n");

        m=new(card[num]);
        m->move(ob);
        map_delete(hcards,card[num]);
        set("hcards/"+p,hcards);

        m->set("owner",p);//卡片的設定
        if(def || m->query("kind")=="trap"){//防守跟陷阱卡的處理方式相同.
          m->set("defend",1);//防守
          m->set("hide",1);//蓋牌
          message_vision(HIG"\n$N"HIG"說道："NOR"我在檯面上蓋上\一張卡！\n",me);
        }else message_vision(HIG"\n$N"HIG"說道："NOR""+saying+"「"+m->name()+"」，採取"HIR"「攻擊狀態」"NOR"！\n", me);

        if(query("earth") == m->query("earth")) {
           if(def)
             write(HIM"你喃喃自語的說道："NOR"因為環境適應力的關係，我的"+
               m->name()+"還能提高 "HIW"200"NOR" 分的攻擊力！\n");
           write("你想到的諸多邪惡的事，正為此而偷笑著，但沒有笨到讓對手發現。\n");
           m->add("ap",200);    
           if(!def)
              message_vision(HIG"$N"HIG"說道："NOR"因為環境適應力的關係，我的「"+
              m->query("name")+"」還能提高 "HIW"200"NOR" 分的攻擊力！！！\n", me);
           m->add("ap",200);
        }
        set("dump",1);//召喚過怪物或是放上陷阱卡片
// ***************************** 卡片特殊功能(start) *****************************
//      if(m->query("do_open")) m->do_open(this_object(),me);
        if(!m->query("hide")) if(m->do_open(this_object(),me,0,"dump")) return 1;
        if(magic=query("magic")){//共通魔法
            for(i=0;i<sizeof(magic);i++){
              if(!objectp(magic[i])) continue;
//            magic[i]->check_magic(this_object(),me,"dump",0);//再次啟動魔法
              if(magic[i]->check_magic(this_object(),me,m,0,"dump"))return 1;//再次啟動魔法
            }
        }
// ***************************** 卡片特殊功能(end) *****************************
        return 1;
}

int die(object card)
{
// card : 傳入物件型態的卡片
// card2: 傳入文字檔型態的卡片
// die_cards所存的是物件型態的資料

   mapping d_cards;
   string owner;
   object new_card;

        owner=card->query("owner");//取得擁有者(1p或2p)
        new_card=new(base_name(card));
        destruct(card);
        new_card->set("die",1);
        new_card->move(this_object());
        return 1;
}

int do_pk(string arg)
{
   object me,a,b,target;
   int my=0,your=0,amount;
   string p;
   object *cdata;
   int my_ap,your_ap,my_dp,your_dp;
   object damage_p;
   string s_condition;
   object *magic;
   int i;

        me = this_player();
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(query("player")!=me) return notify_fail("現在不是輪到你說話。\n");

        p=query(me->query("id"));
        if(!arg) return notify_fail("指令格式: pk <我方怪數字> <敵方怪數字>\n");
        sscanf(arg,"%d %d",my,your);

//      cdata = all_inventory();//取得戰場上的卡片資料
        cdata=query_cards("pk");
        if(my<0 || my>(sizeof(cdata)-1)) return notify_fail("指令格式: pk <我方怪數字> <敵方怪數字>\n");

        if(cdata[my]->query("owner")!=p)
//        return notify_fail(cdata[my]->name()+"又不是你家的怪獸，你叫啥？\n");
          return notify_fail("它又不是你家的怪獸，你叫啥？\n");
        if(!cdata[my]->query("attrib"))
          return notify_fail("指令格式: pk <我方怪數字> <敵方怪數字>\n");

        if(your<0 ||your>(sizeof(cdata)-1)){
          if(p=="1p") target=b;
          else target=a;        
        }else target=cdata[your];
        if(target->query("owner")==p) return notify_fail("你想打倒自己的怪物嗎？\n");

//      write(cdata[my]->name());
//      write(cdata[your]->name());
//      write(target->name());

//特殊狀況
        if(cdata[my]->query("freeze") > query("round"))
          return notify_fail(cdata[my]->name()+"在這回合無法行動，必須再等"+chinese_number(
            cdata[my]->query("freeze")-query("round"))+"回合\n");
        else cdata[my]->delete("freeze");

        if(cdata[my]->query("act")) 
          return notify_fail(cdata[my]->name()+"在這回合已經行動過了\n");
        if(cdata[my]->query("defend")) return notify_fail("守備怪獸不能進行戰鬥\n");
        if(query("round") == 1) return notify_fail("第一回合不能進行戰鬥\n");
//
        amount=get_amount(p=="1p"?"2p":"1p",cdata);//取得敵方場上怪獸數量
//      write(""+amount);
        if(userp(target)){//直接攻擊玩家
          if(amount>0)return notify_fail("對方檯面上還有戰鬥怪獸未消滅，無法直接對玩家進行攻擊。\n");
          else{
            message_vision(HIG"\n$N"HIG"說道："NOR"你的檯面上已經沒有能保護你的戰鬥怪獸了！！所以.....\n"NOR,me);
            message_vision(HIG"\n$N"HIG"說道："NOR"就讓你就承受我所有的攻擊吧！！\n"NOR,me);
            if(cdata[my]->query("a_msg"))
                message_vision(HIG"\n$N"HIG"說道："NOR"戰鬥！"+cdata[my]->name()+
                    "直接對$n攻擊！！"+cdata[my]->query("a_msg")+"\n"NOR,me,target);
            else
                message_vision(HIG"\n$N"HIG"說道："NOR"戰鬥！"+cdata[my]->name()+
                    "直接對$n攻擊！！\n"NOR,me,target);
            add(query(target->query("id"))+"_hp",-cdata[my]->query("ap"));
            cdata[my]->set("act",1);
          }
          damage_p=target;
        }else{//攻擊戰鬥怪獸
          my_ap=cdata[my]->query("ap");
          my_dp=cdata[my]->query("dp");
          your_ap=target->query("ap");
          your_dp=target->query("dp");
          cdata[my]->set("act",1);
          if(target->query("hide")) {
            message_vision(HIC"\n被覆蓋\的卡翻開了，他的真面目原來是"+NOR+target->name()+HIC
                "！！\n",me);
            target->delete("hide");
          }
          if(cdata[my]->query("a_msg"))
            message_vision(HIG"\n$N"HIG"說道："NOR"上吧！"+cdata[my]->name()+
                "！！攻擊對方的"+target->name()+"！"+cdata[my]->query("a_msg")+"\n",me);
          else
            message_vision(HIG"\n$N"HIG"說道："NOR"上吧！"+cdata[my]->name()+
                "！！攻擊對方的"+target->name()+"！\n",me);

// ***************************** 卡片特殊功能(start) *****************************
          if(target->do_trap(this_object(),me,cdata[my])) return 1;//陷阱
          if(magic=query("magic")){//共通魔法
            for(i=0;i<sizeof(magic);i++){
              if(!objectp(magic[i])) continue;
              if(magic[i]->check_magic(this_object(),me,cdata[my],target,"pk"))
                return 1;//再次啟動魔法
            }
          }
// ***************************** 卡片特殊功能(end) *****************************

          if(!target->query("defend")){//敵方怪物是攻擊狀態(start)
            if((my_ap-your_ap)>0){
              message_vision(HIG"\n$N"HIG"說道："NOR"哈哈哈！輕鬆擊破了你的"+target->name()+
                  "！！\n",me);
              add(target->query("owner")+"_hp",-(my_ap-your_ap));
              damage_p=query(target->query("owner"));//受攻擊方
              die(target);
            }else if((my_ap-your_ap)==0){
              message_vision(HIR"\n"+cdata[my]->name()+"和"+target->name()+"由於戰鬥力相當
                  ，而同歸於盡了！\n",me);
              die(target);
              die(cdata[my]);
            }else{
              message_vision("\n$N慘叫一聲，滿臉「那也安捏？？？」的表情。\n",me);
              message_vision(HIG"\n$N"HIG"說道："NOR"啊！！！我的"+cdata[my]->name()
                  +"被你殺死了！！\n",me);
              add(p+"_hp",my_ap-your_ap);
              damage_p=me;//受攻擊方
              die(cdata[my]);
            }
          }//敵方怪物是攻擊狀態(end)
          else{//敵方怪物是守備狀態(start)
            if((my_ap-your_dp)>0){
              message_vision(HIG"\n$N"HIG"說道："NOR"哈哈哈！雖然不傷你生命值，但還是輕鬆擊破了你的"+target->name()+"！！\n",me);
              die(target);
            }else if((my_ap-your_dp)==0){
              message_vision(HIR"\n"+cdata[my]->name()+"和"+target->name()+"由於攻守相當，不造成任何影響！\n",me);
            }else{
              message_vision("$N慘叫一聲，滿臉「那也安捏？？？」的表情。\n",me);
              message_vision(HIG"\n$N"HIG"說道："NOR"你的"+target->name()+"皮太厚了啦...我撩了"+(your_dp-my_ap)+"分的生命\n",me);
              add(p+"_hp",my_ap-your_dp);
              damage_p=me;//受攻擊方
            }
          }//敵方怪物是守備狀態(end)
        }

        if(damage_p){
          if(query(query(damage_p->query("id"))+"_hp") > 0)
            message_vision(HIW"\n$N"HIW"目前生命值還剩下 "+query(query(damage_p->query("id"))+"_hp")
                    +" 分。\n"NOR,damage_p);
          else {
            message_vision(HIW"\n$N"HIW"生命值被減到零了，獲勝的是$n！！恭喜恭喜！！。
                    \n"NOR,damage_p,damage_p==a?b:a);
            call_out("lost",0,damage_p);
        }}
        return 1;
}

int do_magic(string arg)
{
   object me,a,b,ob;
   int num,target=0,size;
   string p;
   mapping hcards=([]);
   string *card;
   object *cdata=({});

        me = this_player();
        p=query(me->query("id"));
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(query("player")!=me) return notify_fail("現在不是輪到你說話。\n");

        if(!arg) return notify_fail("指令格式: magic <手牌編號> <場上怪獸編號>\n");

        sscanf(arg,"%d %d",num,target);
        hcards=query("hcards/"+p);//取得手牌資料
        if(sizeof(hcards)<1) return notify_fail("你的手中沒有任何卡片可以使用!!\n");
        card=keys(hcards);
        size=sizeof(hcards);
        if(num<0 || num>(size-1)) return notify_fail("指令格式: magic <手牌編號> <場上怪獸編號>\n");
        if(card[num]->query("kind")!="magic") return notify_fail("「"+card[num]->name()+"」這張卡並不是魔法卡\n");

//      cdata=all_inventory();
        cdata=query_cards("pk");
        size=sizeof(cdata);
        if(target<0 || target>(size-1)) 
           return notify_fail("目前檯面上找不到你所說要當成施法對象的戰鬥怪獸。\n");
        ob=new(card[num]);
        ob->set("owner",p);
        if(ob->query("forever")) message_vision(HIG"$N"HIG"說道："NOR"看我的永久魔法卡－－「$n」\n",me,ob);
        else message_vision(HIG"$N"HIG"說道："NOR"看我的魔法卡－－「$n」\n",me,ob);
        map_delete(hcards,card[num]);
        set("hcards/"+p,hcards);
// ***************************** 卡片特殊功能(start) *****************************
        if(ob->do_open(this_object(),me,cdata[target],"magic")) return 1;
// ***************************** 卡片特殊功能(end) *****************************
        die(ob);//送進墳場

        return 1;
}

int do_tactic(string arg)
{
   object me,a,b;
   string p;
   object *cdata;
   int num,size;
   object *magic;
   int i;

        me = this_player();
        p=query(me->query("id"));
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(query("player")!=me) return notify_fail("現在不是輪到你說話。\n");

        if(!arg) return notify_fail("指令格式: tactic <場上怪獸數字>\n");
        sscanf(arg,"%d",num);

//      cdata=all_inventory();
        cdata=query_cards("pk");
        if(num<0 || num>(sizeof(cdata)-1)) 
           return notify_fail("指令格式: tactic <場上怪獸數字>\n");

        if(cdata[num]->query("owner")!=p)
           return notify_fail("它又不是你家的怪獸，你無法這麼做。\n");
        if(cdata[num]->query("kind")=="magic" ||cdata[num]->query("kind")=="trap")
           return notify_fail("你只能替戰鬥怪獸下此指令。\n");
        if(cdata[num]->query("act")) return notify_fail("它在這回合已經行動過了。\n");
        if(cdata[num]->query("freeze") > query("round")) 
           return notify_fail("他在這回合無法行動，必須再等"+(chinese_number(cdata[num]->query("freeze")-query("round")))+"回合\n");

        if(!cdata[num]->query("defend")){
           message_vision(HIG"\n$N"HIG"說道："NOR"我將"+cdata[num]->name()+"改變為"HIY"「守備狀態」"NOR"！\n",me);
           cdata[num]->set("defend",1);
        }else{
           message_vision(HIG"\n$N"HIG"說道："NOR"我將"+cdata[num]->name()+"改變為"HIY"「攻擊狀態」"NOR"！\n",me);
           cdata[num]->delete("defend");
           cdata[num]->delete("hide");
// ***************************** 卡片特殊功能(start) *****************************
//         if(cdata[num]->query("do_open")) cdata[num]->do_open(this_object(),me);
           if(cdata[num]->do_open(this_object(),me,0,"tactic"))return 1;
           if(magic=query("magic")){//共通魔法
             for(i=0;i<sizeof(magic);i++){
//             magic[i]->check_magic(this_object(),me,"tactic",0);//再次啟動魔法
               if(!objectp(magic[i])) continue;
               if(magic[i]->check_magic(this_object(),me,cdata[num],0,"tactic"))return 1;//再次啟動魔法
             }
           }
// ***************************** 卡片特殊功能(end) *****************************
        }

        return 1;
}

int do_history(string arg)
{
   object env,me,a,b,m,p;
   int i,pn;

        me = this_player();
        env = environment(me);

        write("戰績表\n================================================================================\n");
        for(i=0; i<query("score_num"); i++) {
           write(""HIY"第"+chinese_number(i+1)+"戰"NOR"  "HIW"勝利者："+
             query("fight_"+(i+1)+"/winner")+NOR+"  "HIR"落敗者："+query("fight_"+(i+1)+
             "/loster")+NOR+"  "HIM"勝利回合："+chinese_number(query("fight_"+(i+1)+
             "/round"))+NOR+"  "HIB"所剩生命："+query("fight_"+(i+1)+"/hp")+NOR+"\n");
        }
        if(i==0) write("自重新啟動到現在，尚無資料登入\n");
        write("================================================================================\n");
        return 1;
}

int do_cover(string arg)
{
   object me,a,b;
   string p;

        me = this_player();
        p=query(me->query("id"));
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(!query("player")){
           delete("1p");
           delete(me->query("id"));
           message_vision(HIG"\n"+me->name()+"退出了牌局!!\n",me);
           return 1;
        }

        if(p="1p")
             message_vision(HIG"\n"+me->name()+"覆牌了，他承認自己輸給了"+query("2p")->name()+"，恭喜"+query("2p")->name()+"勝利！\n"NOR,me);
        else message_vision(HIG"\n"+me->name()+"覆牌了，他承認自己輸給了"+query("1p")->name()+"，恭喜"+query("1p")->name()+"勝利！\n"NOR,me);
        call_out("lost",0,me);

        return 1;
}

int do_go(string arg)
{
   object me;

        me = this_player();
        if((query("1p")==me)||(query("2p")==me)){
          write(HIR"尊重一下，決鬥時請勿任意走動。\n"NOR);
          return 1;
        }
}

int lost(object me)
{
   object a,b,winner,loster;
   string p;
   int i;
   object *inv;

        if(!me) me = this_player();
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(me==a){ loster=a; winner=b;}
        else {loster=b; winner=a;}

        add("score_num",1);
        set("fight_"+query("score_num")+"/winner",winner->name());
        set("fight_"+query("score_num")+"/loster",loster->name());
        set("fight_"+query("score_num")+"/round",query("round"));
        set("fight_"+query("score_num")+"/hp",query(query(winner->query("id"))+"_hp"));

        delete(a->query("id"));  delete(b->query("id"));
        delete("1p"); delete("2p");
        delete("1p_hp"); delete("2p_hp");
        delete("1p_mhand"); delete("2p_mhand");
        delete("1p_mpk"); delete("2p_mpk");
        delete("player"); delete("earth");
        delete("round"); delete("check_round"); 
        delete("hcards");  delete("cards"); 

        inv = all_inventory();
        for(i=0;i<sizeof(inv);i++) {
           destruct(inv[i]);
        }

        message_vision(HIR"\n場上所有戰鬥怪獸不一會全部消失了。\n"NOR, this_player());
        return 1;
}

