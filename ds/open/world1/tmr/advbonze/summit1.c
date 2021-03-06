// Room: /open/world1/tmr/advbonze/summit1.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰頂-平台中央");
	set("long", @LONG
你正站在凌雲峰頂上的一處人造平台中，由於地形高峻，氣候非常的
寒冷，石頭鋪成的地面都積了一層薄雪。在平台正中央供奉著一尊有十數
人之高的巨大如來金佛像，遠處山峰裡日光照射過來，登時讓你覺得金光
閃閃，瑞氣千條，兩個眼睛幾乎快睜不開了。
LONG
	);
	set("current_light", 1);
	set("no_recall",1);
	set("no_clean_up", 0);
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"summit2",
  "northwest" : __DIR__"summit3",
  "south" : __DIR__"hill17",
    "north" : __DIR__"summit6",
  "southwest" : __DIR__"summit5",
  "southeast" : __DIR__"summit4",
]));

        set("objects", ([
                __DIR__"buddha-statue.c" : 1,
                ]));


	setup();
	replace_program(ROOM);
}
