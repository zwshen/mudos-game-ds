//2006.6.9 add by manto
#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIW"月光"+HIY"寶盒"NOR,({"moon box","box"}));
        set("unit", "個");
        set("long",@LONG
一個泛著淡黃色光芒且綻放出微微金黃色氣息的寶盒。裡面裝著月族得來不易的寶物。
  箱子中拿東西出來。
  
  放東西: put [東西] in moon box
  拿東西: get [東西] from moon box

  這個箱子有著特殊的功能:
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
        set("club_id", "moon");
        set("demand_level", 3);
        set("access_log",1);
        setup();
}

