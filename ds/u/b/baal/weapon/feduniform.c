#include <armor.h>

inherit CLOTH;
 
void create()
{
set_name("星際聯邦制服-指揮部",({"federation uniform","uniform"}) );
set("long","這是一件星際聯邦紅黑相間的高層指揮人員制服。\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "件");
set("value",10000);

set("limit_con",3);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor    物理防護
//  armor_prop/shield   非物理防護
//  armor_prop/hit      命中率
set("armor_prop/armor", 500);
set("armor_prop/shield", 300);
        }
        setup();
}
