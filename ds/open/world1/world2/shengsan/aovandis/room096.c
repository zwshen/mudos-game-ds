// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�}�G��"NOR);
	set("long", @LONG
�o���}�G�y�����ө��A�O���M���c��s�L�B�p�I�ߪ��ө��A�����@��
�ƾ���������[���`�O���ȤH�b���D����w���s�L�C�����C�K���⪺����
�A�۹����H���ؿˤ��P�C�b��W���ۤ@�ӵP�l(sign)�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room090",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss4.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
�G�i�P�W�g��:
[1;33m
		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���
[m
NOTE
        ]) );
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");	// �ө�

	setup();
	replace_program(ROOM);
}