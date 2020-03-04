#include <ansi.h>
inherit NPC;

void create()
{
//=========================°ò¥»³]©w==========================
        set_name( "¥b¤HÃT", ({ "halfshark",}));
        set("level",45);
        set("title","[1;32m®ü§¯[m");
        set("race", "³¥Ã~");
        set("age", 42);
        set("evil",45);
        set("war",1);
        set_skill("spear",250);
        set_skill("rapid",140);
        set("coin", random(300));
        set("long", @LONG
¤@°¦¤H­±ÃT¨­ªº¥b¤H³½, ¤@¤f¾U§Qªº¤ú¾¦¬Ý°_¨Ó¤Q¤À¤¿´Ý¡C
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
(:command("go down"):),
(:command("go up"):),
}) );


set("chat_chance_combat", 20);
set("chat_msg_combat", ({
(:command("rapid"):),
(:command("go east"):),
(:command("go west"):),
(:command("go north"):),
(:command("rapid"):),
(:command("go south"):),
(:command("go out"):),
(:command("go enter"):),
(:command("rapid"):),
(:command("go down"):),
(:command("go out"):),
(:command("go up"):),
}) );
set("limbs", ({ "ÀY³¡", "¨­Åé", "«e¸}", "«á¸}","¸¡³¡"})); //¨ü§ð³¡¦ì
set("verbs", ({ "bite","claw"})); //§ðÀ»«¬ºAÃÞhoof¼²crash«rbite§ìclaw°Öpoke
 setup();
//==========================¸Ë³Æ¹D¨ã=============================
//      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/blackspear")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
 object npc, me;
 me=this_player();
 if(!me) return;
 if(this_object()->is_fighting()) return;
 this_object()->remove_all_killer();
 if(me==this_object()) return;
 if(me)
  if(!userp(me))
 { 
 if(npc=present("ovelia",environment(this_object()))) kill_ob(npc);
 if(npc=present("sightseer",environment(this_object()))) kill_ob(npc);
 if(npc=present("lamuza",environment(this_object()))) kill_ob(npc);
 if(npc=present("tifa",environment(this_object()))) kill_ob(npc);
 if(npc=present("asan",environment(this_object()))) kill_ob(npc);
 if(npc=present("guard",environment(this_object()))) kill_ob(npc);
 if(npc=present("oceaner",environment(this_object()))) kill_ob(npc);
 if(npc=present("buddy",environment(this_object()))) kill_ob(npc);
 if(npc=present("boy",environment(this_object()))) kill_ob(npc);
 if(npc=present("yuan",environment(this_object()))) kill_ob(npc);
 if(npc=present("guest",environment(this_object()))) kill_ob(npc);
 if(npc=present("tiger",environment(this_object()))) kill_ob(npc);
 if(npc=present("king",environment(this_object()))) kill_ob(npc);
 if(npc=present("squire",environment(this_object()))) kill_ob(npc);
 if(npc=present("leader",environment(this_object()))) kill_ob(npc);
 } else kill_ob(me);
}
