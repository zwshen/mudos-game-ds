// Room: /u/m/mulder/area/shop3.c

inherit ROOM;

void create()
{
	set("short", "新彼得武器店 -");
	set("long", @LONG
這是全武最大的武器店，你可從這�媔R一些先進的武器．或
從這�婸P其他的玩家交換新的武器，你也可以在這�堜M他們一起
交換．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road5",
]));
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weaponrobot" : 1,
]));

	setup();
	replace_program(ROOM);
}
