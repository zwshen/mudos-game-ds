#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("勇士戰甲" ,({ "brave armor","armor" }) );
        set("long","這是一件只有真正的勇者可穿戴的護甲。\n");
        set_weight(15000);
        set("material", "iron");
        set("unit", "件" );
        set("limit_lv",25);
        set("value",5200);
set("volume",30);
set("armor_prop/armor",35);
set("armor_prop/con",1);
        setup();
}

