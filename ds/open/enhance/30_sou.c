#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( GRN "�����H���F��" NOR, ({"30p sou scroll","scroll"}) );
        set("long",@LONG
�o�O�@�i�㦳���_�ĪG�����b�A�i�H�Ψӱj�ƪZ���Ψ���C
�ϥΫ��O�A�аѦ� help enhance�C
�����]�w�A�аѦ� help scroll�C
LONG);
	set_weight(10);
	set("value",1000);
	set("unit","�i");
	
	set("is_enhance",1); // flag
	set("eff_p",30);	// ���\���v
	set("eff_type", "sou");

	setup();	
}

int query_autoload() { return 1; } 


