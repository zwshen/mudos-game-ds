// Room: /u/s/suez/grave/path_6.c

inherit ROOM;

void create()
{
	set("short", "雲天鞍部");
	set("long", @LONG
此處常有雲氣聚集，所以文人騷客就稱此為雲天。就在雲霧的深處，
隱隱約約可以看見一些屋舍，那是一些在斌山腳下討生活的，這裡雖然不
是桃源鄉，但是也別有一番人間仙境的安和樂利。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path_5",
  "eastup" : __DIR__"path_7",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
