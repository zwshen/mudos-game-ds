#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "麻雀" , ({ "sparrow" }) );
        set("level",2);
        set("race","野獸");
        set("age",5);
        set("long","這是一隻麻雀，對愛門村而言，無疑是種討厭的生物。\n");
        set("limbs", ({ "頭部", "身體", "尾巴", "翅膀" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}

