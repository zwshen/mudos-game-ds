#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("�Q���I��",({"black wood staff","staff"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",8);
               set("limit_con",6);
               set("unit", "��");
               set("long", "�o�O�@��ΤW�n�Q��һs���������A�¤O�۷����C\n");
		set("volume",6);
               set("value",6000);
               set("material", "wood");
		set("limit_str",30);
		set("limit_int",15);
		set("limit_con",25);
        }
    init_staff(60,TWO_HANDED);
   setup();
}
