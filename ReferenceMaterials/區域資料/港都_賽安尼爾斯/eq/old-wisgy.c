#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIB"���~�¤h��"NOR, ({ "old-wisgy","wisgy" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�Ӯc�Q�کҶ������~�A���Ȥ��Z�A�ר�O���~���A���ȧ󰪡C\n");
                set("unit","�M");
        }
        set("value",350);
        set("heal_ap",60);
        set("water_remaining",3);
        setup();
}
