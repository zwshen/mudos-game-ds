#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "妖槍地祇", ({ "ghost lancer","ghost","lancer","__GUARD__" }) );
        set("level",28);
           set("combat_exp",2800);
set("exp",1500);
        set("long","他是幽冥地窖中的使槍高手，和鬼杖客在多次戰役中，合殺了無數好手。\n");
        set("age",50);
        set("evil",40);
        set("gender","男性");
        set("title",CYN"鬼出神沒"NOR);
        set("attitude","killer");
           set_skill("fork",56);
           set_skill("dodge",56);
           set_skill("parry",56);
        setup();
        carry_object(__DIR__"wp/lance.c")->wield();
           carry_object(__DIR__"eq/hands.c")->wear();
}
