#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(MAG"����s"NOR, ({ "grape wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�C�F�n�X�V������s�A���y��A���ܤj���\\�ΡC\n");
                set("unit","�M");
        }
        set("value",200);
        set("heal_hp",30);
        set("water_remaining",3);
        setup();
}
