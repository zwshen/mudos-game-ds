
inherit ROOM;

void create()
{
	set("short", "西側走廊");
	set("long", @LONG
你看到桐紅色的牆壁上有幾扇的窗戶，從窗戶看出去可以看到外面的
景色。沿著走廊的兩旁每隔一段距離都有幾盆的盆栽擺放著。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room10",
	    "west" : __DIR__"room17",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
