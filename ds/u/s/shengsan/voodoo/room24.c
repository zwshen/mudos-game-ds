
inherit ROOM;

void create()
{
	set("short", "前廳");
	set("long", @LONG
在你東面的牆上有許多動物及昆蟲標本，這些標本都有一個共通的特
性，那就是有相當的毒性，還好牠們都已經死了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room25",
	    "south": __DIR__"room23",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
