#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIW"�ո���s"NOR, ({ "white-grape wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�C�F�n�X�V���ո���s�A��󬡦�A���ܤj���\\�ΡC\n");
                set("unit","�M");
        }
        set("value",280);
        set("heal_hp",50);
        set("water_remaining",3);
        setup();
}
