// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�����L");
	set("long", @LONG
�X�ʰ��j�����b�o��ͪ��A�٦��X�ʤp����H�b�j�𪺮���C�]��
�n�䦳�@�y��y�A�ϱo�o�̪��g�a���I�P�n�C���ɷ|���r�D�M���Y���b�o
�X�S�A���\�h�C�ȴ��g�b�o������Y���������A�ҥH�٬O�p�ߪ��n�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out050",
	    "west" : __DIR__"out048",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}