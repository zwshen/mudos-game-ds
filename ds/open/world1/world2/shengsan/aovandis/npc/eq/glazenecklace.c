
#include <armor.h>

inherit NECK;

void create()
{
	set_name("�[���]����",({"glazed necklace","necklace","glazed"}));
	set("long",@LONG
�o������O�ѳ\�h�����R�[���]�Ҧꦨ���A��{�b����o�ج��R���]�l
�w�g�ܤ֤H�|���F�C
LONG
	);
	set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "��");
		set("value",225);
	}
	setup();
}
