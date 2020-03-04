// Room: /u/a/acme/area/plaza.c

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裡是位於廣場的西邊，只見路中央有塊大石碑，約有八尺高，傲然
聳立，上頭還用朱砂寫了篇文章，字跡斑駁，看來似乎歷史已相當久遠，
往東可通往廣場的中央，西邊可看到有一間客棧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"st",
  "east" : __DIR__"plaza1",
]));
set("objects",([
//        __DIR__"npc/moon" : 1,
]) );
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
