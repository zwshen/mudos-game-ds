#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�L�פM" , ({ "wu do blade","blade" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("limit_str",10);
		set("volume",3);
               set("long", "�o�O�@����ª��j�M�A�۷�W�Q�A���ᬰ�I���C\n");
          set("value",2250);
               set("material", "iron");
              }
        init_blade(33);
        setup();
}
