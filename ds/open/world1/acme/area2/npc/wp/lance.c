#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name("���K�j" , ({ "black iron lance","lance" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",10);
               set("unit", "��");
		set("volume",5);
               set("long", "�o�O�@��Ѷ��K�ҧM��Ӧ������j�A�۷�I���C\n");
           set("value",2000);
            set("material","iron");
        }
    init_fork(30);
   setup();
}
