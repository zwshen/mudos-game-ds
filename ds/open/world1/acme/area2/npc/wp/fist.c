#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
        set_name( GRN "����" NOR , ({ "ghost claw","claw" }) );
      set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�@�ӳz�ۺ�𪺰����C\n");
          set("value",2000);
		set("volume",2);
               set("limit_str",6);
      	       set("limit_dex",5);
               set("limit_int",4);
               set("limit_con",8);
               set("material", "iron");
        }
    init_fist(30);
   setup();
}
