#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIG"牧羊戒" NOR ,({ "mo-yang ring","ring" }) );
        set("long",@LONG
某深山高人所造，但其身分姓名未知。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",1);
                set("unit", "對");
                set("value",3000);
        }
        set("wear_msg",HIY"$N把牧羊戒戴上，便感受到大地的溫和。"NOR);
        switch(random(3))
        {
        case 0:        
                set("armor_prop/con",4);
                set("armor_prop/str",4);
                set("armor_prop/bar",1); 
                set("armor_prop/armor",4);
        break;
        case 1:
                set("armor_prop/dex",4);
                set("armor_prop/int",4);
                set("armor_prop/tec",1); 
                set("armor_prop/armor",4);
        break;
        case 2:
                set("armor_prop/int",-2);
                set("armor_prop/str",-2);
                set("armor_prop/dex",-2);
                set("armor_prop/con",-2);
                set("armor_prop/bar",-1);
                set("armor_prop/tec",-1);
                set("armor_prop/armor",-4);
        break;
        }
        setup();
}

