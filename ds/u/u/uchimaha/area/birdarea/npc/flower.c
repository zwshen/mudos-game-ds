#include <ansi.h>
inherit NPC;
void create()
{
       set_name("食人花",({"eat people flower","flower"}));
        set("level",20);
        set("race", "野獸");
        set("age", 100);
        set("long", "一朵會吃人的大花，五顏六色的非常漂亮。\n");
        set("limbs", ({ "花朵", "枝條", "莖幹", "枝葉"}) );
        set("verbs", ({ "bite"}) );
        setup();
}
