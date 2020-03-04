// Room: /open/world1/tmr/advbonze/summit3.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰頂-平台西北角");
	set("long", @LONG
你正站在凌雲峰頂上西北角的一處平台中，在你前方不遠處供奉著一
尊「大力金剛羅漢石像」，在往前數步就是峰頂的崖邊，地上積雪日深，
稍一踩不穩，就會連滾帶爬的摔下山去。
LONG
	);
	set("outdoor", "snow");
	set("no_recall",1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"summit1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
