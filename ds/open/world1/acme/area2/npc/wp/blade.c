#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�s�Y�M" , ({ "dragon blade","blade" }) );
     set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
      set("limit_str",8);
 set("limit_dex",5);
                              set("limit_str",5);
               set("long", "�o�O�b�M�`�B�J���s�Y���j�M�A���G�¤O�j�j�A���ᬰ�I���C\n");
              set("value",2000);
               set("rigidity",300);
               set("material", "iron");
		set("volume",4);
        }
	init_blade(40,TWO_HANDED);
   setup();
}
