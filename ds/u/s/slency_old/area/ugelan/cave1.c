// Room: /u/s/slency/area/ugelan/cave1.c

inherit ROOM;

void create()
{
	set("short", "陰暗山洞");
	set("long", @LONG
這裡是一個陰暗的山洞，山壁十分平滑，應該是有人在此鑽鑿而成
的人工山洞，不過山洞裡空空如也，除了四方形的一間石室外便沒有其
他任何東西了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wood10",
]));
	set("no_clean_up", 0);
	set("light",0);
        setup();
	replace_program(ROOM);
}
