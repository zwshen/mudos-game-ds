#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIW "碎骨皇袍" NOR, ({ "crush bone armor", "armor" }) );
        set_weight(1000);

        if( !clonep() ) {
                set("unit", "套");
                set("value", 18000);
                set("long",@long
    這是一件十分高級的皇袍，為碎骨寨皇帝的一種權力像徵。上面
鑲滿輕薄短小的不知名金屬片，更增添了幾許肅容的感覺。
long
                );
                set("armor_prop/armor", 10);
                set("armor_prop/con", 2);
                set("armor_prop/str", 2);
        } else 
                     set_default_object(__FILE__);

        setup();
}

