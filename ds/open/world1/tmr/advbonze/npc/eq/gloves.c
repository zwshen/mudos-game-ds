#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIW "吉祥蓮華" NOR ,({ "lucky gloves","gloves" }) );
        set("long",@LONG
吉祥蓮華是一雙以蓮花圖案為主的護手，只見繡工精細，將蓮花出淤泥
而不沾染半點風塵的精神，表現得非常生動。這雙護手正反面都繡滿了各式
各樣的蓮花，如睡蓮、蓮伳、香水蓮等各種花兒。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "雙");
                set("value",3500);
        }
  set("limit_lv",35);

        set("armor_prop/armor",5);
        set("armor_prop/shield",10);
        set("armor_prop/int",3);
        setup();
}

