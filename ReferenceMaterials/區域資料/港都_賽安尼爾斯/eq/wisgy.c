#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIB"�¤h��"NOR, ({ "wisgy" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�Ӯc�Q�کҶ������~�A���Ȥ��Z�C\n");
                set("unit","�M");
        }
        set("value",200);
        set("heal_ap",30);
        set("water_remaining",3);
        setup();
}
