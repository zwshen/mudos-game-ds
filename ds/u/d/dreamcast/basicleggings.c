#include <ansi2.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(HIC"閃"HIY"神"HIW"脛甲"NOR ,({ "Dreamcast leggings","leggings" }) );
        set("long","相傳這是，閃靈神的閉關寶物，能增加移動速度•\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("material", "leather");
        set("volume",5);
        set("unit", "雙");
        set("value",1500);
        }
        set("armor_prop/armor",3);
        set("armor_prop/dex",3);
        set("armor_prop/dodge",10);
        setup();
}

