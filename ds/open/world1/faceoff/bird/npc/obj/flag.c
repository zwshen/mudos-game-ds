#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("令旗", ({ "flag", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "這是十萬大山旗主用來號令部下的用品.");
                }
        setup();
}
