#include <ansi.h>
inherit NPC;


void create()
{
//=========================°ò¥»³]©w==========================
        set_name( "ÃT¤H¤ý", ({ "sharkleader",}));
        set("level",55);
        set("title","[1;32m®ü§¯[m");
        set("race", "³¥Ã~");
        set("age", 42);
        set("evil",105);
        set("war",1);
        set_skill("hammer",180);
        set_skill("fireball",300);
        set("env/spellpower",3);
        set("coin", random(3000));
        set("long", @LONG
¤@°¦¯S§O°ª¤jªº¥b¤HÃT, ¥¿«ü´§µÛ¨ä¥Lªº®ü§¯±þ®`¤HÃþ¡C
LONG
        );

//========================ºA«×Ãþ§O=================================
   set("attitude", "aggressive");    //­^¶¯¥D¸qªº NPC¡C

//=============================¦Û°Ê°Ê§@=================================
set("chat_chance", 50 );  //°Ê§@¾÷²v
set("chat_msg", ({       //°Ê§@¤º®e
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
set("limbs", ({ "ÀY³¡", "¨­Åé", "«e¸}", "«á¸}","¸¡³¡"})); //¨ü§ð³¡¦ì
set("verbs", ({ "bite","claw"})); //§ðÀ»«¬ºAÃÞhoof¼²crash«rbite§ìclaw°Öpoke
 setup();
//==========================¸Ë³Æ¹D¨ã=============================
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
shout(HIG"\n\n «Ü§Öªº, ®ü§¯¤§¤ý³Q"+ob->query("name")+HIG"®ø·À±¼ªº®ø®§¶Ç¹M¤F¦U¦a...\n\n"
"    ¦¨¬°¤H­Ì¯ù¾l¶º«áªº¤@¬q¨Î¸Ü.... \n\n"NOR);
   ::die();
}
