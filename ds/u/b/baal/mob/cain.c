a
inherit NPC;
#include <ansi.h>
void create()
{
 set_name("庫拉斯特凱恩",({"Kurast Cain","Cain"}));
 set("long","庫拉斯特凱恩是現今暗斯德塔的領導者, 相傳他是費斯
傑利一族族人, 如果傳言屬實, 也正好可以解釋為何他
在支配元素魔法方面的技巧如此的高超, 他七歲便能以
自己的力量聚集自然界的元素施展出照明術, 他優良的
天資讓他在學習元素魔法的路上無往不利, 這也造成了
他身體不及常人的強壯, 但他冷靜的眼神及能夠迅速施
展的強大法術令人們對他總是懷著又敬又畏的心理, 不
管在那裡, 他都披著一件暗紅色的斗篷, 斗篷下令人不
寒而慄的眼神以及他手腕上由惡魔骨頭所串製而成的手
鐲所散發出的青綠色光芒便是他給人最深刻的印象, 儘
管他的魔法已機乎使他擁有天神一般的力量, 但他眉宇
之間仍舊透出淡淡的哀愁...
LONG
        );
set("max_ap",900);
        set("guild_skills",([
        "sword":({110,4,80}),
        "blade":({110,4,80}),
        "dodge" : ({120,3,80}),
        "parry" : ({120,4,80}),
        "unarmed":({110,4,80}),
        "staff":({110,4,80}),
        ])  );
 set("attitude","peaceful"); 
 set("age",55);
 set("gender","男性");
 set("level",45);
 set("title",HIW"元素支配者"NOR);
 set("nick",HIR"暗斯德塔暗領"NOR);
 set_skill("staff",45);
 set_skill("dodge",35);
 set_skill("parry",40);
 set("guild_gifts",({6,4,0,10}));
 set("chat_chance",10);
 set("chat_msg", ({"庫拉斯特凱恩說道:如果有了那個珠子, 我的法術就可趨近於完美, 可是...\n",
                   "庫拉斯特凱恩長長吸了一口氣, 再緩緩的吐出來道:我用了那麼多精力去搜尋, 仍然無法知道確切的位置。\n",
                   (:command("think"):),
                   (:command("say"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"cast stone shield":),
                    (:command,"say 看來你低估了一個瘦弱的法師...嘿嘿 ":),
 }));
 set("talk_reply","你能幫我一點忙(help)嗎?\n");
 set("inquiry/help","請你幫我尋找一個名為"元素法珠"的珠子, 我目前只知道他在幽遮蘭城一帶, 但是有另一個不知名的力量讓我無法確切的找出它的位置。\n");
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") != "element-pearl")
        {
           command("angry "+who->query("id"));
           command("say 這不是我想要的珠子...滾!!!");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 你內心想說什麼, 我都知道, 
不要打擾我了。\n");
             return 0;
           }
    message_vision("$N給了庫拉斯特凱恩一個 "+ob->query("name")+"。\n");
             command("smile");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
            command("say 嗯？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"庫拉斯特凱恩小心的捧起元素法珠, 看著裡面變化的色彩, 發出讚美的嘆息。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say 就是這個珠子...我的元素魔法終於可以到達完美的境界了!!。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            message_vision(HIY"庫拉斯特凱恩小心的把元素袍子收進預先準備的寶盒裡,再放進斗蓬裡的夾層。\n"NOR);
            command("whaha");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 
            {
              command("say " +  RANK_D->query_respect(me) + "真是謝謝你幫我找到元素法珠。");
              command("shakehand "+me->query("id"));
              obj->delete_temp("givehat");
            }
            else {
command("say 今天我心情挺好, 我看你"+ RANK_D->query_respect(me) + "滿有修習元素魔法的天份的, 不知你願意追隨我鑽研更深一層的元素魔法嗎?");
              obj->set_temp("givehat",i+1);
              call_out("givehat",2,me);
            }
            break;
          case 5:
            command("say 從今以後, 把暗斯德塔當作你自己的家吧, 好好學習元素魔法的奧妙!!");

            message_vision(YEL"$N深深的一鞠躬, 接過庫拉斯特凱恩遞給$N的骨鐲, 輕輕的戴在手上\n"NOR,me);
            command("nod "+me->query("id"));
            message_vision(HIC"$庫拉斯特凱恩輕輕的說:暗斯德塔有些地方是封閉的, 等到你能力夠了就自己穿過結界去看看吧...\n"NOR,me);
            me->set("adv_class",1);
            me->set("class1","元素法師");
            me->create_family("元素",3,"法師");
        me->set("guild_rank","初入門的元素學徒");
            obj->delete_temp("givehat");
            break;
      }
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     

        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                                
                        case 0: rank = "初入門的元素學徒"; break;
                                
                        case 1: rank = "稍有見識的小法師"; break;
                                
                        case 2: rank = "鑽研技法的咒術師"; break;
                                
                        case 3: rank = "修習咒術的咒法師"; break;
                                
                        case 4: rank = "操縱元素的魔法師"; break;
                                
                        default: rank = HIC "暗斯德塔之大法師" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                
                        case 0: rank = "初入門的元素學徒"; break;
                                
                        case 1: rank = "稍有見識的小法師"; break;
                                
                        case 2: rank = "鑽研技法的咒術師"; break;
                                
                        case 3: rank = "修習咒術的咒法師"; break;
                                
                        case 4: rank = "操縱元素的魔法師"; break;
                                
                        default: rank = HIC "暗斯德塔之大法師" NOR;
                }

        }
        return rank;
}
	
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIC"\n  西方大陸傳出了一個令人驚訝的消息"HIC"\n\n\t支配著世界元素能量的HIR暗斯德塔暗領 庫拉斯特凱恩HIC竟然喪生在"+ob->name(1)+"。\n\n"+NOR,users()手上);
        ob->add("popularity",1);
        ::die();
        return;
}
