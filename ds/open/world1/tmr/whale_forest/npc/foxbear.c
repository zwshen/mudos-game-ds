// fox bear.c

#include <npc.h>

void create()
{
        set_name("小狐熊", ({ "small fox bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw" }) );
        set("age", 5);
        set("long", "一隻野生的小狐熊，一雙漆黑亮麗的眼睛正望著你。\n");
        setup();
        set_stat_maximum("hp",200);
        set_stat_maximum("gin",200);
           do_heal();
}


