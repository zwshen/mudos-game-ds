// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���ϹA��");
	set("long", @LONG
�o�̪��A�Ц��I�p�A���L�]�����M�|���C��K�K�K���s�n�q�ж��Ǩ�
�A�X����;�Q�شӦb�A�Ю���A�M������;𻴻����j�ۡA�𸭶�����
�X�F�F���n���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out032",
	    "north": __DIR__"out024",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}