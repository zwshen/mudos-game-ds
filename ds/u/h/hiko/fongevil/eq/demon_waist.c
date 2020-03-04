#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("妖皮韌帶",({"demon waist","waist"}) );
        set("long",@LONG
用妖怪的皮所製成的韌帶，感覺十分耐用，且帶著強大妖氣。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",25);
                set("limit_int",20);
                set("unit", "條");       
                set("value",5600);          
                set("volume", 3);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/str",2);
        set("armor_prop/dex",1);
  setup();
}

