#include <npc.h>
#include "barbarian_base.c"


void create()
{
        set_name("女野蠻人", ({ "woman barbarian","barbarian" }) );
        set("long",@long
一個穿獸皮衣的女野蠻人，瞧起來就是過著茹毛飲血的日子，長的一
副暴力而血腥的模樣，而他似乎也正懷好意的打量你。
long
);
        set_race("human");
        set("age", 25);
        set("age", 25);
        set("gender","female");
        set_attr("str",30);
        set_skill("blunt",80);                  // 棒法
        set_skill("twohanded blunt",60);        // 雙握棒法
        set_skill("parry",50);
        set_skill("dodge",50);
        setup();
        set_level(6);
        carry_object("/d/obj/woodblunt")->wield();
	carry_object(__DIR__"obj/monster-cloth")->wear();
}

