// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�s�S");
	set("long", @LONG
�a�զ��I�T�򤣥��A���Ӧn�����ˤl�C�X�ʤj�𤴵M�b�o��L�ڵۤs
�S�A��W�٦��X�Ӿ�}�A�����D�O����ʪ���b�̭��H���ӧA�|�ݨ����
���q�o�W�Y���L�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out061",
	    "west" : __DIR__"out059",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}