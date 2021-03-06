
inherit ROOM;

void create()
{
	set("short", "巫毒教玄關");
	set("long", @LONG
有種神秘的感覺向你襲來，詭異的氣氛充斥在整個房間裡。你看到左
右各一條走廊，而前方是巫毒教內的前廳。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room11",
	    "west" : __DIR__"room16",
	    "north": __DIR__"room22",
	    "down" : __DIR__"room09",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/student" : 3,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
