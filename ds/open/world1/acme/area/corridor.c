// Room: /u/a/acme/area/corridor.c

inherit ROOM;

void create()
{
	set("short", "走廊");
     set("light",1);
	set("long", @LONG
這裡是神武教中的走廊，沿著走廊擺上了一排盆栽，上頭栽種著奇花
異樹，氣味芬芳，令你覺得神清氣爽。東邊傳來了呦喝聲，原來是間練武
大廳，西邊則是藏經閣，往南可通往大廳。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"portal",
  "west" : __DIR__"library",
  "south" : __DIR__"parlor",
  "east" : __DIR__"hall",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
