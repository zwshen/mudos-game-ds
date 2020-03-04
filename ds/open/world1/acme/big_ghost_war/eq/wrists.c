/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit WRISTS;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"瘆臔得"NOR ,({ "po god wrists", "wrists" }) );
            set("long","ンㄓ碍臔得η︹皌称\n");
            set_weight(3000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+6);
            break;
        case 21..45:
            set_name(HBK"み臔得"NOR ,({ "heart wrists", "wrists" }) );
            set("long","ン候候も得臔得\n");
            set_weight(2000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+5);
            break;
        case 46..70:
            set_name(HBK"耴﹁臔得"NOR ,({ "west wrists", "wrists" }) );
            set("long","ンノ┣钵借籹Θ淮借臔得\n");
            set_weight(1000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+4);
            break;
        default:
            set_name(HBK"驹活臔得"NOR ,({ "ghost wrists", "wrists" }) );
            set("long","ンㄓН臔得帝砛\艶\n");
            set_weight(1500);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(5)+3);
            break;
    }

    switch( random(100) ) {
        case 0..19: set("armor_prop/str",1); break;
        case 20..39: set("armor_prop/con",1); break;
        case 40..59: set("armor_prop/int",1); break;
        case 60..79: set("armor_prop/dex",1); break;
        case 99:
            set("armor_prop/str", 1);
            set("armor_prop/con", 1);
            set("armor_prop/int", 1);
            set("armor_prop/dex", 1);
            break;
    }

    if ( clonep() )
        set_default_object(__FILE__);
    else {
        set("material", "iron");
        set("unit", "癸" );
    }

    setup();
}
