// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�s�S");
	set("long", @LONG
�s�թ���a�Ѧ詹�n�ɰ��\�h�A�٬O���\�h�Ӫ��b�o��ͪ��A���\�h
���H�ۤΤj���Y���G�����ӧ��áA�䶡�٦��@�Ǭ\��b�W���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out062",
	    "west" : __DIR__"out060",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}