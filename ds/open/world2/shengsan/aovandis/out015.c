// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������~");
	set("long", @LONG
�C�C��������b���Z�}��������~�A�o�ӫ���w�g���X�d�~�����v�F
�C���ǹC�ȷ|�b�o�̩�ӯd���A�]���Ǧҥj�Ǯa�b�o���[���A�٦��@
�ǫؿv�v�b�o���s���𪺵��c�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out022",
	    "north": __DIR__"out011",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}