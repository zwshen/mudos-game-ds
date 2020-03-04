// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠West[2;37;0m");
	set("long", @LONG
南面發出了嘈吵的聲音，就知道是一部機器在製造武器時發出的巨響
。而香味仍然在四處飄散，使得你好像遊魂般想飄過去食品街。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gate4.c",
  "south" : __DIR__"shop2.c",
  "east" : __DIR__"dst15.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
