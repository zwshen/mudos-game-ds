// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�B�ä��Щ�"NOR);
	set("long", @LONG
�A���B�ܡH�A���b��ĤG�K�ܡH�o�̬O�P���}�n�ýt���n�a��C����
��^�����C�A�[�W���ФH���M�~�P���ۡA���f���k�k�i�O���]�������Cť
���b���@�ɦU�a�����L�̪������q�C��W���ӧi�ܵP(note)�C
LONG
	);
	set("item_desc", (["note":@NOTE

�G�i�P�W�g��:
[1;36m
	�B�äD�ר��j�ơA���i�H���������C
	�O�b�S�ݤF�A�S�O���z�q���w������Q�A�@�w���z���N�C
	�p�G���ݭn�N�Х����q�����ФH���A���Чa�C
[m
[1;33m					* �B�ä��Щ� *
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room063",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/introducer.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}