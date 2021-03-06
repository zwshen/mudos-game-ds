// Room: /open/world1/acme/bonze/b10.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你正走在上山小徑中，四周重巒疊嶂，怪石嵯峨，人稱之為『雞
足山』，你仰頭一望，山勢峻險，高插雲天，看山而去，黑壓壓景物
模糊加上冷風瑟瑟，間什著獸吼猿啼，鷹鳴鳥叫，越發令人有淒涼之
感。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"b9",
  "north" : __DIR__"b11",
]));
set("objects",([
  __DIR__"npc/dog.c" : 4,
]) );
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
