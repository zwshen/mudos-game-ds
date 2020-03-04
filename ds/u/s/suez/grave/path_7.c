// Room: /u/s/suez/grave/path_7.c

inherit ROOM;

void create()
{
	set("short", "小石山巔");
	set("long", @LONG
在山巔上種了幾株古松，落了一處涼亭，亭中聚集了兩三位文人正在
談詩論賦，松下則又是另一番趣味，幾個江湖豪客吟酒高歌，雖然同地不
同心，但是在這小巧峻麗的小石山巔上，卻別有一番和諧氣味。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_6",
  "eastdown" : __DIR__"path_8",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
