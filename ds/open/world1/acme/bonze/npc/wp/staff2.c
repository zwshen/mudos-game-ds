#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("���",({"staff","staff"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�@��ΨӼ��ۨ����Ϊ�����A�ר䨫�s���ɯS�O�n�ΡC\n");
set("value",800);
               set("limit_str",1);
               set("limit_con",1);
		set("volume",3);
               set("material", "wood");
        }
init_staff(8);
   setup();
}
