// Room: /u/l/lestia/area/map_8_3.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-大殿旁廳");
	set("long", @LONG

這裡是靈幻教大廳兩旁的廳堂，專門給普通教徒或旅客歇息的地方，擺
設平常但不失一派之風，幾個身穿白色勁裝的教徒正坐在椅子上聊天，一張
普通的桌子上擺著茶水，你如果渴了可以倒一杯來喝。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_7_3",
  "west" : __DIR__"map_8_2",
]));
   set("objects", ([ 
__DIR__"obj/tea":1,
]));

	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
