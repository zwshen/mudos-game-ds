#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("羅漢護甲" ,({ "luo-han armor","armor" }) );
        set("long",@LONG
一件極為厚重的護甲，但感覺得出來非常結實，在防禦敵人的攻擊有
一定的功效。在護甲下擺繫了幾條紅絲線，瞧著倒也覺得美觀。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(15000);
                set("material", "gold");
                set("unit", "副");
                set("value",3000);
                set("volume",3);
        }
                 set("armor_prop/armor", 24);
                 set("limit_con",20);
                 set("limit_str",20);
                 set("armor_prop/con", 2);
                 set("armor_prop/str", 2);
        setup();
}
