#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("�Ƴ��u" ,({ "snow boots","boots" }) );
        set("long","�o�O�@�������ƪ����u�A�@�Ф��V�A�զp�q���C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "linen");
        set("unit", "��" );
        set("value",1250);
		set("volume",2);
        set("armor_prop/armor", 3);
        set("limit_con",6);
        set("armor_prop/dex", 2);
        }
        setup();
}
