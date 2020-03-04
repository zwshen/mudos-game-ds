#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ÏEÂê",({"amk's shackles","amk's","shackles"}));
        set_weight(1000000000);
                set("value",0);
                set("no_sac",1);
                set("no_drop",1);
                set("can_give",1);
                set("unit","¥I");
 set("long",@LONG
AMK±MÄÝªºÏEÂê
LONG
                );
setup();
}
int query_autoload() { return 1; }
