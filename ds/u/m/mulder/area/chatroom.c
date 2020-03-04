// Room: /u/m/mulder/area/road12.c

inherit ROOM;

void create()
{
	set("short", "閒聊室");
	set("long", @LONG
你可能覺得在這裏常常打打殺殺，十分無聊．所以才有這間
房的出現，可以供給你在和不同的人聊天或是在這裏交流心得和
希望各位新手們，可在這裏問一問其他的玩家在這裏是怎樣生存
那就不需什麼小事也要用「閒聊」問人．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
