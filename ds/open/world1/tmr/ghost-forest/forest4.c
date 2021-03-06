// Room: /u/t/tmr/area2/forest4.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你正走在一條林間小路上，腳下踏的皆是碎石枯葉，林中不時拂來一
陣涼風，吹著枝葉簌簌作響，抬頭上望，只見樹木高聳入雲，樹梢與樹梢
間交相接耳，葉與葉間的些許空隙之間透露著一線的光線。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest2",
	  "northwest" : __DIR__"forest6",
	]));

          set("outdoors","forest");
	set("no_clean_up", 0);
      set("objects",([
         __DIR__"npc/obj/firewood": random(5),
      ]) );
	setup();
	replace_program(ROOM);
}

