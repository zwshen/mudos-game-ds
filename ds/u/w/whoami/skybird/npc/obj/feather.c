#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ÆN¦Ð", ({ "feather", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "®Ú");
                set("long", "¤@®Ú¯«ÆNªº¦Ð¤ò.");
                }
        setup();
}
