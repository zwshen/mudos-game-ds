#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIR"���s"NOR, ({ "red wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","���s�O�@��H���ܪ��_���s�A�ҥH�ܨ����w��C\n");
                set("unit","�M");
        }
        set("value",100);
        set("heal_mp",10);
        set("heal_hp",10);
        set("heal_ap",10);
        set("water_remaining",3);
        setup();
}
