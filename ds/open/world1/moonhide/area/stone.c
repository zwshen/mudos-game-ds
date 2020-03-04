#include <ansi.h>

inherit NPC;

void create()
{
  set_name(WHT"¥Û¥¨¤H"NOR, ({"tall stone-man","man"}) );
  set("long",@LONG
¬O¬°¤F°t¦X¥j¹Ó°g®c°}©Ò©ñ¸mªº[0;1;36m¡[1mA[0m
¥D­n¬O¨¾½Ã¼Ä¤H¡C
LONG
);
  set("race", "beast");
  set("unit","°¦");
  set("age",1000);
  set("level",30); 
  set("evil",1);
  set("attitude","aggressive");
  set_skill("unarmed",80);
  set_skill("dodge",40);
  set_skill("parry",70);   
  setup();
}

