#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"惡魔"HIW"之"HIY"眼"NOR,({"evil eye","eye"}));
        set("long",@long
天魔的右眼球，可開啟修羅門。
long
                );

        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("door","evileye");
                set("value", 5600);
        }
        setup();
}


