//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("瞭望員",({"tower guard","guard"}));
set("level",52);
set("age",32);
set("long","一位擔任瞭望和警戒工作的瞭望員, 正在用心的觀察四周的環境。\n");
set("gender", "男性");
set_skill("tenken",340);
set("amount",1);
map_skill("unarmed","tenken");
set("coin",400+random(400));
//set_temp("apply/armor",400+random(200));
//set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",460);
carry_object(__DIR__"eq/towercloth")->wear();
carry_object(__DIR__"wp/club")->wield();
}
