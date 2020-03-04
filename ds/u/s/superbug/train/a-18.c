// Room: /u/s/superbug/train/a-18.c

inherit ROOM;

void create()
{
	set("short", "墮落城市PUB");
	set("long", @LONG
這是一間充滿重金屬樂的ＰＵＢ，每天無時無刻這裡都擠滿了一群瘋
狂的的年輕人，在這裡尋求著短暫的愉快，這裡也是整個貧民區最熱鬧的
地方，如果你想要找誰到這裡就對了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-2.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
