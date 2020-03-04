#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name("¯}¥¬ªø¿Ç",({"broken pants","pants"}) );
        set("long",@LONG
¯}¯}ÄêÄêªº´Ö¥¬ªø¿Ç¡C
LONG
);
        set_weight(200); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¥ó");       
                set("value",100);          
                set("volume", 2);                       
                set("material", "cotton");   
        }
        set("armor_prop/armor",2); 
        setup();
}

int query_autoload() { return 1; }   