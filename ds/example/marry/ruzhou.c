
inherit ROOM;

void create()
{
	set("short", "汝州城");
	set("long", @LONG
汝州城是本府的大城，立來是兵家必爭之地。故州治在此駐扎重
兵，盤查南來北往的行人，并負責翦滅附近山上的草寇。由于這里是
北上京城的必經之道，官兵盤查也十分嚴格。從這里向西出城門，可
以到五岳之中的嵩山了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaozheng",
      "north" : __DIR__"yidao2",
		"west" : __DIR__"wangxi-lu",
		"east" : __DIR__"hong-damen",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



