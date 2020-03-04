// Room: /open/world1/moonhide/area/hotel.c

inherit ROOM;

void create()
{
	set("short", "寒冰客棧");
	set("long", @LONG
這是寒冰客棧，在大門口就可以感受到一股冷冰冰的感覺，儘管
是白天或是大太陽，這間寒冰客棧還是冷冰冰的，但是唯一不同的是
，這裡的店小二給人的感覺還蠻親切的，寒冰客棧的特色，想必店小
二會說給你聽吧。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"hotelwaiter" : 1,
]));
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"hoteloo",
  "east" : "/open/world1/cominging/purple_sun/psin5",
  "up" : __DIR__"hotel_up",
]));
	set("no_clean_up", 0);
	set("light", 1);

	setup();
	replace_program(ROOM);
}
