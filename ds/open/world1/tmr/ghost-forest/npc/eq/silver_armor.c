#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW "白銀戰甲" NOR,({ "silver armor","armor" }) );
        set("long",
"白銀戰甲相傳為鬼王　無妄極重視的一件戰甲，常穿著此件參加不同\n"
"戰役。雖然全為純銀打造，卻已被無數敵人的鮮血染著帶有一份淡紅色。\n"
);
        set_weight(22500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "silver");
        set("unit", "件" );
	}
        set("limit_con",30);
        set("limit_lv",25);
        set("value",4600);
        set("armor_prop/armor", 30);
        set("armor_prop/dex", -4);
        set("armor_prop/con",  2);
        setup();
}

