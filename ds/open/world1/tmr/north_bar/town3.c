// Room: /open/world1/tmr/north_bar/town3.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
正當你無聊再這裡閒逛時，發現許多新奇的玩意，旁邊的屋
子、建築都十分特別，有些房屋看起來很新，但有些看起來卻十
分破舊，連用木頭做的牆壁都被蟲蛀光了。旁邊也許多附近的小
孩子在這裡玩耍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town2",
  "north" : __DIR__"town4",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
