// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�A�ݨ�o�̦��\�h���̾�(camphor)�ͪ��b���Z�}�����������A�j
�Ӷ����U���n�Ψϱo�@�����̾��j���۳o�̡C���n���N�O�q�����Z�}��
���䰼�����D���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out002",
	    "south": __DIR__"out006",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
