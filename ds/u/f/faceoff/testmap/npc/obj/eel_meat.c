#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ÅÁ³½¦×", ({ "meat", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶ô");
                set("long", "¤@¶ô¥ÍªºÅÁ³½¦×.");
                }
        setup();
}