#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name( "�I�G�I��" ,({ "dab-aqua-armor","armor" }) );
        set("long",
"�o�O�@�j���u���s  �I�G�v�I�W������A�ݨ�����Q�������p�C�A\n"
"��������Q�ӬݮɡA�~�a�o�{���������o�X�@�Ѥ����W�������C\n"
);
	set_weight(12345);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
		set("volume",6);
        set("unit", "��" );
        set("limit_con",30);
        set("limit_level",15);
        set("value",4000);
	set("armor_prop/armor", 31);
	set("armor_prop/dex",-1);
        }
        set("beast_armor_prop/armor",31);
	set("beast_armor_prop/dex",-1);
	set("beast_armor_type","armor");
        setup();
}
