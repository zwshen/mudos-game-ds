#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("東副師的官印", ({ "mark" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("value",1);
                set("unit", "個");
                set("long", "顧名思義, 就是東副師的官印啊!");
                }
        setup();
}
