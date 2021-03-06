#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIY"防具陳列架"NOR,({"equip shelf","shelf"}));
        set("unit", "個");
        set("long",@LONG
        
  一個擺放著許多防具的鐵架。你可以把一些防具放在架上保存或是從
  架子中拿東西出來。

  放東西: put [東西] in equip shelf
  拿東西: get [東西] from equip shelf

  這個架子有著特殊的功能:
         ** checkuse 'box or shelf's id' {-w|-l|-m}
         ** cleanup 'box or shelf's id' {get|put|all}

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); //2003.4.16  10000 -> 400  by ksj
        set("club_id", "sky");
        set("demand_level", 3);
        setup();
}

