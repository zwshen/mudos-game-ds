#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "度途士", ({ "do tu si","do","tu","si", "__GUARD__" }) );
        set("level",36);
        set("combat_exp",3600);
set("exp",2500);
        set("long","他是拿著大刀的老者，體格相當的矮小，卻拿得起沉重的武器。\n");
        set("age",70);
        set("evil",70);
        set("title",HIR"群魔亂舞"NOR);
        set("gender","男性");
        set("attitude","killer");
        set("Merits/wit",2);
        set_skill("blade",72);
        set_skill("dodge",72);
        set_skill("parry",72);
        setup();
        carry_object(__DIR__"wp/blade2.c")->wield();
}
