#include <ansi.h>
inherit NPC;
void create()
{
set_name("余滄",({"yu chen","yu","chen"}));
set("long",@LONG
這是一個在無砂名聲響噹噹的鹽梟, 但他到底是黑道白道
到今天還是眾說紛紜, 不過可信的是, 在無砂尚未有海政司之
前, 余滄倒是相當公平的處理貧富之間的糾紛, 也因此得罪了
不少富人, 因此相當不滿於今日站在富人群中, 壓榨窮民的王
霸, 幸虧余滄早年曾得一高人指點刀法, 才能在無砂中不受王
霸的鏟除.
LONG
    );
set("level",60);
set("str",  80+random(10));
set("evil",-20-random(50));
set("combat_exp",59000);
set("age",random(9)+33);
set("chat_chance",6);
set("chat_msg",({
  (: command("say 最近世事真多變") :),
  (: command("say 天似圓蓋\，地似棋盤") :),
  (: command("say 江南隱居處，不知十昧火") :),
  (: command("exert moon_force recover") :),
  (: command("exert moon_force addtimes") :),
}));
set_temp("sorgitimes",12);
set("max_ap",4500);
set("chat_chance_combat",120);
set("chat_msg_combat",({
         (:command("exert sorgi_sword"):),
         (:command("exert moon_force recover"):),
}));
        set("class","fighter");
        set("class1","軍人");
        set("title","疾風門創人");
        set("nickname",HIR"武神"NOR);
        set("flurrydodge",1);
        set_skill("unarmed",70+random(10));
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("combat",100);
        set_skill("sorgi_sword",100);
        set_skill("force", 100);
        set_skill("moon_force",100);
        set_skill("fogseven",100);
        map_skill("sword","sorgi_sword");
        map_skill("force","moon_force");
        map_skill("dodge","fogseven");
        setup();
}

void init()
{
        object me,obj;
        me = this_player();
        obj = this_object();
        if( me->query_temp("enter_house") )
        {
                me->delete_temp("enter_house");
                me->set_temp("want_kill",1);
                call_out("want_kill",1,obj);
        }
}


void want_kill()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("enter_house");
      switch( i ) {
          case 1:
            command("say 啊! 這不是神鷹的鷹羽嗎?");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此鷹羽的？");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 2:
            message_vision(YEL"$N將得到鷹羽的過程告訴江清流。\n"NOR,me);
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 3:
	    command("nod");
            command("say 原來如此...。");
            command("hoho");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 4:
	    if(me->query_skill("sky-dagger") == 0 && me->query("class1") == "天梟教") 
            {
            command("say 師父常說天嘯匕法可授天梟之人..。");
            command("say 如大俠不嫌棄, 就請大俠一觀!");
	    obj->set_temp("meet_eagle",i+1);
	    call_out("meet_eagle",3,me);
	    }
	     else {
              command("say 只可惜在下無以為報 ..請受在下一拜!");
	      command("bow");
              obj->delete_temp("meet_eagle");
            }
            break;
          case 5:
            message_vision(YEL"江清流將天嘯匕法的基本心訣講解給$N聽.\n"NOR,me);
            message_vision(HIY"(~~~~~一~~~~~個~~~~~時~~~~~辰~~~~~過~~~~~去~~~~~了~~~~~)\n"NOR,me);      
	    message_vision(HIY"江清流說道:大俠果然是奇人, 這天嘯匕法竟能如此快的領悟!!\n"NOR,me);
	    command("smile");
            me->set_skill("sky-dagger",5);
            obj->delete_temp("meet_eagle");
            break;
            }
}