#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW "白袍" NOR, ({"white robe", "robe"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long",
"這是件用輕紗織成的白色長袍，雖然這件長袍沒有任何繡樣，\n"
"但是剪栽得宜，穿在身上能充分展現落落大方的感覺。\n"
                                );
                set("material", "silk");
                set("limit_lv",15);
                set("armor_prop/armor", 8);
                set("armor_prop/shield", 5);
                set("armor_prop/int", -1);
                set("armor_prop/dex", 1);
                set("value", 1500);
        }
        setup();
}

