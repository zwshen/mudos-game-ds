#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
         set_name(HIR"紅錦腰帶"NOR,({"red waist","waist"}) );
        set("long","這是一條朝廷裡尋常的禁軍所佩載的防具。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(60);
        set("material", "linen");
        set("unit", "條" );
         set("value",1000);
        }
          set("armor_prop/armor", 3);
        set("armor_prop/dodge", 1);
        setup();
}
