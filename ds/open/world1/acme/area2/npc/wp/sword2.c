#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
                set_name( HIB "�����C" NOR , ({ "ghost king sword","sword" }) );
      set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",15);
               set("limit_dex",10);
		set("volume",3);
               set("unit", "��");
               set("long", "�o�O�@�ⴲ�o�۳��𪺧��C�C\n");
             set("value",3500);
               set("material", "iron");
        }
    init_sword(45);
   setup();
}
