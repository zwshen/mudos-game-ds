// Room: /tmr/garea/forest9.c

inherit ROOM;

void create()
{
	set("short", "分岐小路");
	set("long", @LONG
只見四周煙霧一陣散去，你發現你正站在林中的一條小路，眼前赫然
分出了四條小路，各自通往森林深處，兼之沒有醒目物標作引，不諳此間
的人，恐怕已臉色發青，不知該選擇何路前行，甚或折而回向。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	  "southwest" : __DIR__"forest8",
	  "southeast" : __DIR__"forest7",
	  "northwest" : __DIR__"forest10",
	  "northeast" : __DIR__"forest11",
	]));

	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
