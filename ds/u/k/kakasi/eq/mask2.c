#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIC"木葉村畢業護具"NOR,({"mo-ie mask","mask",}) );
        set("long",@LONG
木葉村的學生畢業的護具。
LONG
);
        set_weight(291);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "個");
                set("value",3100);
                set("volume", 2);
                set("material", "gold");
        }
        set("armor_prop/armor",2);
        set("armor_prop/int",1);
        set("armor_prop/dex",1);
  setup();
}
