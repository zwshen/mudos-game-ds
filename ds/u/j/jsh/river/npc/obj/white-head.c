#include <ansi.h>
 
inherit ITEM;
 
void create()
 
{
 
        set_name(GRN"八岐大蛇"RED"．"HIW"白首"NOR,({"orochi white head","white","head"}));
        set("long",GRN"八岐大蛇"RED"之"HIW"白首\n"NOR);
        set_weight(10000); 
        set("value",10000);
        set("unit","顆"); 
        setup();

}

