#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name("���r�٫�" ,({ "hao chi ring","ring" }) );
        set("long","�o�O�@�u��ۤ��K�лx���٫��C\n");
        set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "jade");
        set("unit","�u");
       set("value",200);
        }
         set("armor_prop/armor", 2);
        setup();
}
