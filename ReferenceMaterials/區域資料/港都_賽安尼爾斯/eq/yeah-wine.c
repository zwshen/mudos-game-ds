#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("���s", ({ "yeah wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�η��l���C���s�A���ɷ|���X�}�}�������C\n");
                set("unit","�M");
        }
        set("value",200);
        set("heal_mp",20);
        set("heal_hp",20);
        set("heal_ap",20);
        set("water_remaining",3);
        setup();
}
