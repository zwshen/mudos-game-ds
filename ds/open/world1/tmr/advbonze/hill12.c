// Room: /open/world1/tmr/advbonze/hill12.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰半山腰-小平地");
	set("long", @LONG
你正處在凌雲峰半山腰的一塊小空地中，這塊平地約方尺見寬
而已，大概只可容納四五個人在此休息，空地中放了幾塊大石頭，
看石頭上面長綠苔，看樣子似乎少有人來這。在空地往北的方向，
仍然是「上天梯」的道路。
LONG
	);
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hill13.c",
  "southwest" : __DIR__"hill11",
]));

	setup();
	replace_program(ROOM);
}
