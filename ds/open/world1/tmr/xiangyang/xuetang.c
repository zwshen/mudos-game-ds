// Room: /d/xiangyang/xuetang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "學堂");
	set("long", @LONG
這裡是襄陽的學堂，窗明几淨，一塵不染。一位莊重嚴肅
的老先生坐在太師椅上講學。在他的兩側坐滿了求學的學生。
一張古意盎然的書案放在老先生的前面，案上擺著幾本翻開了
的線裝書籍。
LONG );
	set("exits", ([
		"west" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/laoxiansheng" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}