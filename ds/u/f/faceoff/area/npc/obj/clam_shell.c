#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("巨蚌殼", ({ "clam shell", "shell" }) );
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long", "顧名思義, 就是巨蚌的殼.");
                }
        setup();
}
