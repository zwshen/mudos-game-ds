// Room: /u/a/acme/area/farm2.c

inherit ROOM;

void create()
{
	set("short", "農田");
	set("long", @LONG
你正走在田間小路，環顧四方，盡是正正方方的農地，田中央還插著
一個稻草人，農田中一片綠油油的秧苗，生氣蓬勃，欣欣向榮，令你不自
覺得停下腳步，細細品嘗這小小的生機。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"farm",
  "east" : __DIR__"farm1",
]));
       set("objects",([
             __DIR__"npc/farmer" : 2,
          __DIR__"npc/buffalo" : 2,
       ]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
