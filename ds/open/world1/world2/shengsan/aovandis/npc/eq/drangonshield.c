#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("�K�s���",({"drangon shield","shield"}) );
	set("long",@LONG
�o�Ӭ޵P�W���K�����s���O�����S��,�C���s���O���򪺮ݮݦp�͡A��
�����̪��F��w�g������`�b�o���ޤW�F�C
LONG
	);
	set_weight(5500);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",1600);
	}
	setup();
}

int query_autoload() { return 1; }
