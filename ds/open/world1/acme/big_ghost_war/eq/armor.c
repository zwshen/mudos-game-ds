/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit ARMOR;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"破神甲"NOR ,({ "po god armor", "armor" }) );
            set("long","一件來自鬼界的戰甲，兩肩有著二個威風凌凌的虎頭。\n");
            set_weight(13000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(20)+25);
            break;
        case 21..45:
            set_name(HBK"困心甲"NOR ,({ "heart armor", "armor" }) );
            set("long","一件緊緊束住人身的戰甲。\n");
            set_weight(12000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(20)+20);
            break;
        case 46..70:
            set_name(HBK"歸西甲"NOR ,({ "west armor", "armor" }) );
            set("long","一件用怪異材質製成的輕質戰甲。\n");
            set_weight(2000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(20)+15);
            break;
        default:
            set_name(HBK"戰魂甲"NOR ,({ "ghost armor", "armor" }) );
            set("long","一件來自妖界的戰甲，似乎存著許\多怨靈。\n");
            set_weight(10000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(20)+10);
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
        set("unit", "件" );
    }

    setup();
}
