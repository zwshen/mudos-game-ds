inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
你可以聽到附近有練拳練劍的聲音，也可以聽到小鳥亂飛在竹林的
聲音。將武藝融入大自然之間也未長不是一件快人之事，正當你沉醉在
其中之時，突然想起你該做的事而作罷。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room08",
            "south": __DIR__"room05",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/master" : 1,
	    __DIR__"mob/disciple" : 3,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
