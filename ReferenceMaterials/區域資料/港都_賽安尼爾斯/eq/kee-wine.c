#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("��s", ({ "kee wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�ݵ۳o�M��s�A���_���_�X�w�w�A�����@�ˡC\n");
                set("unit","�M");
        }
        set("value",80);
        set("heal_mp",20);
        set("water_remaining",3);
        setup();
}
