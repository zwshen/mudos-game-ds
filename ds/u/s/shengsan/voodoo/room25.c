
inherit ROOM;

void create()
{
	set("short", "前廳");
	set("long", @LONG
有許多的刀槍劍刃掛在你南面的檔牆之上，每把兵器看起來都相當的
鋒利且具殺傷力。而在你北面的牆上掛了一幅大掛圖(picture)。
LONG
	);

	set("item_desc", (["picture":@NOTE
[1;32m
這幅掛圖出自名家之手，上面的馬匹在萬丈的草原高地上奔馳，氣勢
非凡，筆路瀟灑。
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room24",
	    "west" : __DIR__"room26",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/believer" : 3,
	    __DIR__"mob/studentp" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
