// Room: /u/d/darkfool/area1/1.c

inherit ROOM;

void create()
{
	set("short", "新諾提斯鎮門口");
	set("long", @LONG
這裡是新諾提斯的鎮門，兩根石柱分立在進出口的兩旁，斑駁的
柱身透露出些許歷史的滄桑，它們曾經是古鎮的一部份，為了採礦而
來到此地的新居民們見這兩根石柱還蠻有特色的，便將其保留了下來
。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
