#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("헍낸┹", ({ "meat", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "락");
                set("long", "�@락Νず헍낸┹.");
                }
        setup();
}