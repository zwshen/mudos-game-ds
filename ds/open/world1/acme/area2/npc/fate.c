#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "秤命客", ({ "balance fate herald","balance","fate","herald", "__GUARD__" }) );
        set("level",35);
           set("combat_exp",3500);
set("exp",1500);
        set("long","他是一位手上拿著秤錘的老人，眼神十分兇惡。\n");
        set("age",70);
        set("evil",70);
        set("title",HIR"群魔亂舞"NOR);
        set("gender","男性");
        set("attitude","killer");
           set_skill("whip",70);
                 set_skill("dodge",70);
                set_skill("parry",70);
        setup();
         carry_object(__DIR__"wp/beam.c")->wield();
       carry_object(__DIR__"eq/neck.c")->wear();
}
