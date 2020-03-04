
inherit ROOM;

void create()
{
	set("short", "前廳");
	set("long", @LONG
你看到桌子椅子都排列整齊，壁上有許多標本，仔細一看才知道都是
有毒性的動物及昆蟲。地上鋪的事大紅色的地毯。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room22",
	    "north": __DIR__"room24",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
