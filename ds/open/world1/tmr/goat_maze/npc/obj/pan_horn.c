#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me);

int query_pan();

void create()
{
        set_name( "白色羊畸角"  ,({"pan horn","horn", "_PAN_HORN_"}) );
        set_weight(10);
        set("long",@LONG
這是一根乳白色的羊畸角，上頭還沾有幾滴鮮血。
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","根");
                set("value", 10);
        }
        setup();
}
