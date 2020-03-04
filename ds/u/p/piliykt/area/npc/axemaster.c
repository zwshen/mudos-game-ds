#include <ansi.h>
inherit NPC;
void create()
{
        set_name("公孫晉", ({ "axe-master-guard","guard" }) );
        set("title",HIG "斧將" NOR);
        set("level", 40);
        set("race","人類");
        set("gender","男性");
        set("age",32);
        set("str", 70);
        set("con", 50);
        add("addition_armor",50);        
        add("addition_damage",50);        
        set_skill("axe", 100);
        set_skill("parry", 40);
        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set("long",
   "一位王爺的護衛，身手非凡武藝高強，斧法更是出神入化。\n");
        setup();
        carry_object(__DIR__"wp/axe_1.c")->wield();
        carry_object(__DIR__"eq/ring_1.c")->wear();
 
}

