// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�g�H���s�S");
	set("long", @LONG
�o�̬O�g�H���s�S�A�o�̪����׭�n�i�H�ݨ���u�̲����v���b
������A�]�i�H�ݨ�_����L������C�X�ʴӪ��ͪ��b�o�A�ϱo�o�s�S�]
����⪺��Ũ�A�L�ɤѪŤ����ն��d���A�@�ǷQ�����Ŷ��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out061",
	    "north": __DIR__"out056",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}