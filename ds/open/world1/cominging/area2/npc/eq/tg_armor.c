#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("皮鎧甲", ({ "leathery armor","armor" }) );
        set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
			"用牛皮所做成的鎧甲，當你穿這這件鎧甲，就會聞到上面濃烈的\n"
			"腥味，讓你有些不太想穿下去，不過常穿這個衛兵卻早已習以為\n"
			"常，鎧假後面還畫了個大大的一個字「步」。\n");
                set("unit", "套");
                set("material", "peel");
		set("value", 3000);
                set("armor_prop/armor", 9);
                set("armor_prop/con",1);
        }
        set("wear_msg","$N穿上一件$n，似乎聞到那濃烈的牛的味道。");
        set("unequip_msg","$N卸下一套$n，似乎輕鬆了許多。");
        setup();
}