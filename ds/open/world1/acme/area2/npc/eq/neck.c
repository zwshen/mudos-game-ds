#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("�ѥɶ���" ,({ "jade neck","neck" }) );
        set("long","�o�O�@����⪺����C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "jade");
        set("unit", "��" );
       set("value",1000);
        set("armor_prop/armor", 2);
        set("limit_int",3);
        set("armor_prop/str", 1);
        }
        setup();
}
