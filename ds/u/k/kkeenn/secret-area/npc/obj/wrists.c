#include <armor.h>
inherit WRISTS;
void create()
{
        set_name("悲風手套", ({ "sad wind wrists","wrists" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一雙被悲傷的原力包圍的手套。\n");
                set("unit", "雙");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1250);          
                set("wear_msg", "$N把$n帶上, 四周突然變的淒風苦雨\n");
                set("unequip_msg", "$N將$n脫掉, 阿~世界依舊美好。\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",4);
        setup();
}

