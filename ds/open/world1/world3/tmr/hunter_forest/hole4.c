// Room: /tmr/future/hunter_forest/hole4.c

inherit ROOM;

void create()
{
	set("short", "山洞裡");
	set("long", @LONG
你正處在一個山洞裡，伸手不見五指的黑暗，使得你只得邊摸著牆壁
邊行走，你只覺得你現在所處的通道約可勉強站著行走。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"hole9",
	  "southwest" : __DIR__"hole1",
	]));
	set("light", 1);
	set("world", "future");
	setup();
	replace_program(ROOM);
}
