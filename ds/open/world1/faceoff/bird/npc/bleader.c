#include <ansi.h>
inherit NPC;
void create()
{
 set_name(HIB"正藍旗主"NOR,({"blue flag leader","blue","leader"}));
 set("long",@LONG
一個山寨的旗主, 他是率領籃旗的頭目
LONG
    );
 set("attitude", "aggressive");
 set("age",40);
 set("gender","男性");
 set("level",15);
 set_skill("sword",40);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/fur_waist")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"obj/flag");

}
