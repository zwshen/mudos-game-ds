// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
��o�o����W�ͪ��b�o���g�a���W�A���I���N���Ů���j���۴�����
�����̾����C���ɤ]���X�ʰ��L�@��H�������~����b�a�W�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"out002",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}