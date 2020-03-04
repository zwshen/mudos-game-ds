#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "野人頭目", ({ "redhair captain","captain","wildman","man"}) );
        set("long",@long
    野人頭目長的非常的高大，滿頭的紅髮雜亂無章，不時地的往你這兒
望來，似乎隨時都會攻擊你似的。
long
);
        set_race("human");
        set("title","紅髮");
        set("age", 25);
        set_attr("str",30);
        set_skill("whip" , 80);                  // 鞭法
        set_skill("parry",80);
        set_skill("dodge",50);
        setup();
        set_level(15);
        advance_stat("hp",500);
        do_heal();
        carry_object("/d/obj/whip")->wield();
		carry_object(__DIR__"obj/monster_pants")->wear();
		carry_object(__DIR__"obj/bone-earring")->wear();
}

