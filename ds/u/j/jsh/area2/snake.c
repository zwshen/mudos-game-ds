#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小小蛇", ({ "small snake","snake" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "小小的一條蛇，真的是小小的ㄛ。\n");
        set_skill("dodge",50);
        set_skill("unarmed",40); 
        set_skill("parry",30);        set("level",20);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        setup();
}

