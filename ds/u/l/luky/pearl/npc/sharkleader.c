#include <ansi.h>
inherit NPC;


void create()
{
//=========================基本設定==========================
        set_name( "鯊人王", ({ "sharkleader",}));
        set("level",55);
        set("title","[1;32m海妖[m");
        set("race", "野獸");
        set("age", 42);
        set("evil",105);
        set("war",1);
        set_skill("hammer",180);
        set_skill("fireball",300);
        set("env/spellpower",3);
        set("coin", random(3000));
        set("long", @LONG
一隻特別高大的半人鯊, 正指揮著其他的海妖殺害人類。
LONG
        );

//========================態度類別=================================
   set("attitude", "aggressive");    //英雄主義的 NPC。

//=============================自動動作=================================
set("chat_chance", 50 );  //動作機率
set("chat_msg", ({       //動作內容
(:command("go east"):),
(:command("go west"):),
(:command("go north"):),
(:command("go south"):),
(:command("go climb"):),
(:command("go out"):),
(:command("go enter"):),
(:command("go down"):),
(:command("go out"):),
(:command("go up"):),
}) );

set("chat_chance_combat", 20);
set("chat_msg_combat", ({
(:command("bite"):),
(: cast_spell2, "fireball":),
}) );
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
 setup();
//==========================裝備道具=============================
//      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/blackhammer")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
 object npc, me;
 me=this_player();
 if(this_object()->is_fighting()) return;
 this_object()->remove_all_killer();
 if(me==this_object()) return;
 if(me)
  if(!userp(me))
 { 
 if(npc=present("jailor",environment(this_object()))) kill_ob(npc);
 if(npc=present("dracion",environment(this_object()))) kill_ob(npc);
 if(npc=present("rtmwu",environment(this_object()))) kill_ob(npc);
 if(npc=present("dwarf",environment(this_object()))) kill_ob(npc);
 if(npc=present("troll",environment(this_object()))) kill_ob(npc);
 if(npc=present("pedestrian",environment(this_object()))) kill_ob(npc);
 if(npc=present("mother",environment(this_object()))) kill_ob(npc);
 if(npc=present("child",environment(this_object()))) kill_ob(npc);
 if(npc=present("flaw",environment(this_object()))) kill_ob(npc);
 if(npc=present("nanie",environment(this_object()))) kill_ob(npc);
 if(npc=present("master",environment(this_object()))) kill_ob(npc);
 if(npc=present("father",environment(this_object()))) kill_ob(npc);
 if(npc=present("sweeper",environment(this_object()))) kill_ob(npc);
 if(npc=present("kid",environment(this_object()))) kill_ob(npc);
 if(npc=present("pupil",environment(this_object()))) kill_ob(npc);
 } else  kill_ob(me);
}


void die()
{
object ob;
if( !ob = query_temp("last_damage_from") )
ob = this_player(1);
if( !ob ) ::die();
shout(HIG"\n\n 很快的, 海妖之王被"+ob->query("name")+HIG"消滅掉的消息傳遍了各地...\n\n"
"    成為人們茶餘飯後的一段佳話.... \n\n"NOR);
   ::die();
}
