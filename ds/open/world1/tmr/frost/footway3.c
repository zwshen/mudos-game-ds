// Room: /open/world1/tmr/frost/footway3.c

inherit ROOM;

void create()
{
	set("short", "棧道口");
	set("long", @LONG
你正站在一條棧道口上，這條棧道建於兩座相鄰的峰腰之間，西通凌
雲峰而西達倚霄山，直接地促進佛、道中二個門派的互通有無。此處終年
和暖，風雪不起，堪稱為定居的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"footway2",
  "east" : __DIR__"hill1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
