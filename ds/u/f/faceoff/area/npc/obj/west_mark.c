#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("西副師的官印", ({ "mark" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("value",1);
                set("unit", "個");
                set("long", "顧名思義, 就是西副師的官印啊, 看來你應該把他拿給海政司的官員...");
                }
        setup();
}
