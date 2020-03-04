#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIR"魔炎甲"NOR,({"magic flame armor","armor"}) );
        set("long",@LONG
由魔炎鬥氣生物所凝聚成的盔甲，由於是氣體聚合而成，重量相當的
輕，並具有防護魔法的力量。
LONG
);
        set_weight(5000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",15);
                set("limit_con",15);
                set("unit", "件");       
                set("value",100);          
                set("volume", 3);                       
                set("material", "air");   
        }
        set("monster_armor_type","armor");
        set("monster_armor_prop/armor",32);       
        set("monster_armor_prop/con",3);
        set("monster_armor_prop/shield",18);
        set("armor_prop/armor",30);
        set("armor_prop/shield",18);
        set("armor_prop/con",2);
        set("armor_prop/int",-1);
        setup();
}


