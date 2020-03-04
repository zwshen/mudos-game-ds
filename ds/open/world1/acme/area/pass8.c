// Room: /u/a/acme/area/pass8.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是一條頗為狹小的山路，四周雜草叢生，往北可看到一間小屋，南
邊則是一片濃密的森林，在山路旁有個殘破的告示牌。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"forest1",
  "west" : __DIR__"wewd1",
  "north" : __DIR__"hunter",
]));
	set("no_clean_up", 0);
     set("outdoors","land");
     set("objects",([
        __DIR__"npc/obj/sign" : 1,
     ]));

	setup();
	replace_program(ROOM);
}
