#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "瘋狗" , ({ "crazy dog", "dog", "__GUARD__" }) );
        set("level",4);
           set("combat_exp",400);
       set("gender","雄性");
        set("age",5);
        set("race","野獸");
              set("attitude","killer");
       set("evil",12);
        set("long","這是一隻嘴角流著口水的瘋狗。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
