#include <ansi.h>
inherit NPC;
void create()
{
        set_name("上官聚" , ({ "jui shang guan","jui","shang","guan" }) );
        set("title", HIG "刀狂" NOR);
         set("race","人類");
         set("gender","男性");
        set("age",43);
        set("level", 25);
        set_skill("blade",80);
        set_skill("parry",60);
        set_skill("dodge",70);
        set("long",
            "他是絕代刀狂，愛刀如癡，刀法造詣亦高，與「劍癡」併稱【神劍邪刀】。\n");
        setup();
        carry_object(__DIR__"wp/blade2.c")->wield();
} 
