#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("�P���@��" ,({ "sing yun hands","hands" }) );
        set("long","�@�ӧe�i���ΡA�۷�S�O���@�áC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(2000);
        set("material", "linen");
        set("unit", "��" );
         set("value",1000);
        set("armor_prop/armor", 3);
        set("limit_int",5);
        set("armor_prop/dex",2);
        set("armor_prop/int",-1);
        }
        setup();
}
