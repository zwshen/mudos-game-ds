#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(WHT"日邪魔甲"NOR, ({ "yi-chan armor","yi-chan","armor" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
              else {
                set("long","一件壁綠凝翠的硬甲，上面用血寫著\n"
                HIR"有仇不報非強者！\n"NOR);
                set("unit", "套");
                set("material","steel");
                set("value",40000);
                set("armor_prop/con",10);
                set("armor_prop/dex",-3);
                set("armor_prop/int",5);
                set("armor_prop/str",8);
                set("armor_prop/dodge",-5);
                set("armor_prop/shield",20);
                set("armor_prop/armor", 55);
                set("armor_prop/wit",10);
                set("armor_prop/sou",10);
                set("wear_msg","$N穿上$n,$N身上邪氣四散！");
                set("remove_msg","$N除下了$n,$N身上的邪氣剎那消失。");
        }
        setup();
}
