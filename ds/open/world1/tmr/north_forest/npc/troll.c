#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "���]", ({"troll"}) );
  set("long",@LONG
���]�]Troll�^�_����_�گ��ܡA�O�@�إީ~�ʡA�ۻ���c���Y�H�Ǫ��A
�����i�F�E�`�A�魫���ʽS�C���]��O����׳��Y�����ƭ��ת̡A�q�`����
�D�`�ժZ���O�A�󽦦����ֽ��л\�ۺ��ѪѪ��٦סA�n���y�L���I�O�A�N��
��A�����}�F�C
LONG
);
  set("age", 200);
  set("gender", "����" );
  set("level", 15);
        set("attack_merits","bar");

  setup();
	carry_object(__DIR__"obj/stick")->wield();
	if(random(20)==0)
		carry_object(__DIR__"obj/troll_blood");

}

