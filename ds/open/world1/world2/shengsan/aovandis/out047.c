// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�@�ƪ����H�Ȯy���b�򩤤W�A�b�Ȥl���٦��@�ƪ��h��A�o�̬O����
�k�k�̳��w�Ӫ��a�I���@�A�]���o�̪���^��ù�Ҹ��J�C���ɶ��A�i�H�[
���򭱨��쬰���Z�ʦӦ��������C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out048",
	    "north": __DIR__"out040",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}