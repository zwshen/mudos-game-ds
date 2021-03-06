// Room: /open/world1/tmr/advbonze/hill10.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯");
	set("long", @LONG
你正走在凌雲峰名勝「上天梯」上，你可以看到延著往北而通往
山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，似乎還
有一段不長的路得走。
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill11",
  "southdown" : __DIR__"hill9",
]));

	setup();
	replace_program(ROOM);
}
