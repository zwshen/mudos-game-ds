#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("���Z�ܭ�" ,({ "god surcoat","surcoat" }) );
        set("long","�o�O�@�󯫪Z�Ф����{�M�Ϊ��ܭ��A�۷������C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "silk");
        set("unit", "��" );
        set("value",400);
set("volume",3);
        }
          set("armor_prop/armor", 5);
          set("armor_prop/int", 1);
        setup();
}
