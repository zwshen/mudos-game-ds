#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name("樹精戒",({"tree ring","ring"}) );
        set("long",@LONG
木頭戒指，裡面宿有樹精的法力。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",10);
                set("unit", "只");       
                set("value",500);          
                set("volume", 3);                       
                set("material", "wood");   
        }
        set("monster_armor_prop/armor",3);
        set("monster_armor_prop/int",4);
        set("monster_armor_prop/shield",3);
        set("monster_armor_type","finger");
        set("armor_prop/armor",2);       
        set("armor_prop/str",-1);
        set("armor_prop/int",2);
        setup();
}



