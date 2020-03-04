#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"寶瓶座黃金聖衣"NOR, ({ "Aquarius armor","armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這件就是黃道十二宮中第十一宮的寶瓶座聖衣\n");
                set("unit", "件");
                set("material", "steel");
                set("value",20000);
                set("armor_prop/con",5);
                set("armor_prop/dex",2);
                set("armor_prop/str",5);
                set("armor_prop/dodge",5);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 45);
                set("armor_prop/wit",5);
                set("armor_prop/sou",5);
                set("wear_msg","$N穿上$n,$N感到四周凝結了一層凍氣!");
                set("remove_msg","$N除下了$n,你的神力消失了");
        }
        setup();
}
