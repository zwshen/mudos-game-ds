#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("玉",({"jude"}));
        set_weight(100);
                set("value",1000);
                set("unit","塊");
                set("long",@LONG
一塊看起來十分稀有的玉，不知道是誰掉的...
LONG);
setup();
}
