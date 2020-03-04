// Room: /open/world1/tmr/north_bar/f12.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-洞穴");
	set("long", @LONG
來到這裡，只雖然十分黑暗，但你似乎感覺到前面好像有一
股邪氣，擋住你的去路，如果要經過這裡，似乎要和他一絕死戰
！否則只好往回走了。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"f11",
  "down" : __DIR__"s1",
  "northwest" : __DIR__"f10",
]));
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
}

int valid_leave(object me, string dir)
{
   
        if( dir == "down" && !userp(me)  )
                        return 0;
        return ::valid_leave(me,dir);
}
