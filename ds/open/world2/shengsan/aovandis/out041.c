// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
��L�����𳣫��R�o�V�W�ͪ��A�K�Y���𸭭Z�������ۡA�ϱo��U�O
�@�����D�n�A�j��P�j�𤧶����ɷ|���Q���Ψ䥦���ͪ����D�����A��F
�W�i�H�ݨ��л\�ۤ@�h�C�a�C�C�a�W�٦����Ʀb���Ԫ��u�@�ۡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out042",
	    "south": __DIR__"out050",
	    "north": __DIR__"out037",
            ]));

	set("outdoors","forest");	// ��L
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}