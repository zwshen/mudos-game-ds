#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("聖騎頭盔",({ "holy knight helmet","helmet"}) );
        set("long","這是通過聖騎士考驗的人才擁有的東西。\n");
        set_weight(2400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "crimsonsteel");
                set("unit","頂");
        }
        set("value",3300);
        set("limit_lv",20);
        set("armor_prop/armor",15);
        set("armor_prop/con",1);
        set("armor_prop/str",1);
        setup();
}


