#include <ansi.h>
inherit NPC;
void create()
{
        set_name("兌澤將" , ({ "marsh general","general" }) );
        set("title","ξ神武教ξ 八神將" );
        set("level",30);
        set("race","人類");
        set("age",40);
        set("con", 45);
        set("str", 40);
        set("dex",40);
        set("int",40);
        set_skill("force", 100);
        set_skill("blade", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("unarmed",100);
        set_skill("dodge", 130);
        set("long","他是神武教的八神將之一。\n");
        setup();
        carry_object(__DIR__"wp/longsword.c")->wield();
}
