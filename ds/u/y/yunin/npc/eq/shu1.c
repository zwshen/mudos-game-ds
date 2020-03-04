#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIR"修羅鎧甲〥"NOR,({"shu lo armor","armor"}) );
        set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG
);
        set_weight(5000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "件");       
                set("value",3400);          
                set("volume", 3);                       
                set("material", "cold");   
        }
        set("monster_armor_type","armor");
        set("monster_armor_prop/armor",35);       
        set("monster_armor_prop/con",1);
        set("armor_prop/armor",29);
        set("armor_prop/con",1);
        
        setup();
}
