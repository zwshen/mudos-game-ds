#include <ansi.h> 
inherit ITEM; 
void create()
{
        set_name(HIY"轉龍鏡"NOR, ({"turn dragon-mirror", "mirror" }));
        if( clonep() )
                set_default_object(__FILE__);
        else { 
                set_weight(1000);
                set("long", "一面刻著龍型圖案的鏡子，不反光，每個角落都有一個凹槽。\n");
                set("unit", "面");
                set("material", "golden"); 
                set("no_sell",1); 
                set("no_drop",1);
        }
}

