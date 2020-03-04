// Room: /u/m/matlab/area/entrance.c

inherit ROOM;

void create()
{
	set("short", "陰暗的山腳下");
	set("long", @LONG
這裏位於山峽之中，地屬極陰，終年不見陽光人煙罕至，斜前方的飛瀑
倒頗有一番景緻，只是去路似乎也被斷絕了，但瀑布旁的大石縫好像可容一
人通過。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"start.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/3.c" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
