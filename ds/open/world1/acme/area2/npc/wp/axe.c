#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name( MAG "�q�ѩ�" NOR , ({ "tung tian axe","axe" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
                set("limit_str",10);
               set("long", "�o�O�@�⥨�j�����Y�A�W�Y���C�ѥն����ϮסC\n");
                  set("value",3000);
		set("volume",5);
               set("material", "iron");
        }
    init_axe(40);
   setup();
}
