// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ʳf���q"NOR);
	set("long", @LONG
�b�o���̮i�ܵۮɻ쪺�A���έ����A�󦳷~�̽Яu�H�үS��b�o����
�i�ܡC�C�ӱM�d�����@�ܤG�쪺�p�j�A�ȡA�Ҧ��y�檺�T���b�o�䳣��o
��C�A�i�H�ݨ�@�ӵP�l(sign)�\��b�A���e�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room092",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	set("item_desc", (["sign":@NOTE

		     ��������      �\
	    �\       �x �� �x
	             �x �� �x            �\
	�\         ���� �� ����
		�\ �x�x �� �x�x
		   �x�x �� �x�x�\
		   �x��������x
		 �~�r��    �~�r��   �\
	     �ʡ����w���ʡ����w���ʡ�
	         ��       �\    ��      �\
NOTE
        ]) );

	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{

	if(!arg) return 0;
	if( arg != "the book" )	return 0;
	write("Yes...��...��...�A���}�F�o����...�]��ۥ��}�F�A����d�G�h�W���H�ͤF...\n"
		"�A�P�즳�ز��W�������P���{��A�����W�F...\n");
	return 1;
}