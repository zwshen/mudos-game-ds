// Room: /future/area/digging_street1.c

inherit ROOM;
void create()
{
	set("short", "馬路");
	set("long", @LONG
一條連繫礦場與住宅區的馬路。由於礦場的空氣非常污濁，在馬路兩
旁有大型的空氣清新機，亦用可穿越型護罩將兩區隔離，令到居民得到舒
適的生活環境。
LONG
	);
	set("world", "future");
        set("outdoors","desert");
	set("no_clean_up", 0);
        set("item_desc",([
        "穿越型護罩":
"由一種膠質物體製成的，只能讓液體和固體通過，使得能夠達到阻隔\n"
"污濁空氣的效果。\n",
        ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"digging_road3",
  "south" : __DIR__"digging_street2",
]));

	setup();
	replace_program(ROOM);
}
