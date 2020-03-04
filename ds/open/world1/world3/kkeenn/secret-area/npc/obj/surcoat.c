#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("綠海護肩", ({ "green sea surcoat","surcoat" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件鏽有綠色海洋的輕巧墊肩。\n");
                set("unit", "件");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1050);          
                set("wear_msg", "$N緩緩的把$n帶上去,似乎很喜歡它的美呢\n");
                set("unequip_msg", "$N隨手將$n脫掉。\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",4);
        setup();
}

