#include <ansi.h>
inherit NPC;
void create()
{
        set_name("釣客" , ({ "fishing man","man" }) );
        set("level",10);
        set("race","人類");
         set("gender","男性");
        set("age",35);
        set_skill("parry", 20);
        set_skill("unarmed", 15);
        set_skill("dodge", 20);
        set("long","他是在溪邊垂釣的釣客。\n");
        setup();
        carry_object(__DIR__"wp/rod.c")->wield();
}
