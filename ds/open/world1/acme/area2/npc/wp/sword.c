#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "¶���X�C" NOR , ({ "around fingers sword","sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�@��Ӫ����C�A�M��q�աA�Q���X�n�A���ä��O�ܭ��C\n");
               set("value",1200);
               set("limit_int",5);
		set("volume",2);
               set("material", "copper");
        }
    init_sword(24);
   setup();
}
