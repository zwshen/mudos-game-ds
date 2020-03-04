// Room: /u/s/suez/grave/path_9.c

inherit ROOM;

void create()
{
	set("short", "小石山下");
	set("long", @LONG
前面一個小丘，被這附近的人稱之為小石山，山雖小，泉水林木俱有
，石雖多，小巧玲瓏令人喜愛。附近的村莊祭典多在山上舉行，任誰也沒
想到在這偏遠村野之地竟有如此風光，但是也只有如此偏遠村野，也才能
清新如故，不受塵染。
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"path_10",
  "westup" : __DIR__"path_8",
]));
        set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
