#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("步珇(animal-sacrifice stock) [港種 %d ]",query("time") );
}

void create()
{
        set_name("步珇",({"animal-sacrifice stock", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
硂琌蔓纍辰ψ步珇ノㄓいじ竊步よ
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","");
        }
        set("value", 100);
        set("time", 100 + random(500) );
    
        setup();
        set("long", query("long") + getLong() );
}


