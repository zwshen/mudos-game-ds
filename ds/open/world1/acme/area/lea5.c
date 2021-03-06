// Room: /u/a/acme/area/lea5.c

inherit MOBROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你身處在一片大草原之上，四周的野草已長得比人高了，腳下的泥土
也變得較為泥濘，行走相當不便。你聽見不時得傳來飛禽走獸的的叫聲。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"lea12",
  "south" : __DIR__"lea4",
  "north" : __DIR__"lea15",
  "southwest" : __DIR__"lea8",
]));
        set("chance",65);
        set("mob_amount",4);   
     set("mob_max",12);
        set("mob_object",({   
            __DIR__"npc/rabbit",
        }) );
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
}
