#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIW"希望之鑽"NOR, ({ "hope diamond","hope","diamond" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("long",HIW"\n這是一份簡單卻又美麗的希望凝聚而成的鑽戒。\n"NOR);
                set("unit", "只");
                set("value",0);
                set("material","diamond");
        }
        set("armor_prop/int",1);
        set("armor_prop/armor",1);
        set("armor_prop/shield",1);
        setup();
}

int query_autoload() { return 1; }

