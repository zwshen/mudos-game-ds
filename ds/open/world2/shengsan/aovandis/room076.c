// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¾�~���Щ�"NOR);
	set("long", @LONG
����l�W����󦳨Ǫ���áA�@�줤�~���H���b�줽�C�N��R���o��
�өж��A����������Ӥ���z��(box)�A�ݰ_�Ӹ̭����Ӧ��\�h���u�@
���|�C�A�ݨ���W�a���ۤ@�Ӻ}�G���i�ܵP(note)�C
LONG
	);
	set("item_desc", (["note":@NOTE

�G�i�P�W�g��:
[1;32m
	�ܰ����঳���|���z���Фu�@�A�Х��ݬݤ���z��(box)
	�����u�@���|�A�p�G���w�и�A�ȤH�����A�ڭ̱N�|�ˤ���
	���z�A�ȡC���±z�����{�C

[1;33m					* ¾�~���Щ� *
[m
NOTE
        ,"box":@NOTE

�o�Ӳ��l�W�g�ۡu�u�@���|�v�|�Ӧr�A�̭��˵ۤ@�|�@�|�����C

NOTE
	]) );

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room064",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/woman" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}