#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIY"九寶金冠"HIR"(S)"NOR,({ "nine-gem crown","crown" }) );
        set("long",@LONG
鑲嵌九種寶石的金冠，戴在頭上令人覺得尊貴無比，寶石的力量可以
抵禦術力的攻擊。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5000);
                set("material", "steel");
                set("unit", "頂");
                set("value",3000);
                set("volume",2);
        }
                set("armor_prop/armor", 10);
                set("armor_prop/shield", 6);
        setup();
}

int query_autoload() { return 1; }
