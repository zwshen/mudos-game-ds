#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("�C����",({"green steel staff","staff"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",8);
               set("limit_con",6);
               set("unit", "��");
               set("long", "�o�O�@��ΫC���ҧM��Ӧ��������A�۷�I���C\n");
		set("volume",4);
              set("value",2000);
               set("material", "copper");
        }
    init_staff(30);
   setup();
}
