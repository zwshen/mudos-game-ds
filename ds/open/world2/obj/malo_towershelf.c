#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("儲物櫃",({"cabinet"}));
        set("unit", "個");
        set("long",@LONG
        
  一個塗滿綠色油漆的金屬櫃，上面貼了幾張日本女明星的海報。
  
  放東西: put [東西] in cabinet
  拿東西: get [東西] from cabinet

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(1999999);
	setup();
}


