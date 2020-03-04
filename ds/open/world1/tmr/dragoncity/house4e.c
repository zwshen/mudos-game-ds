// Room: /open/world1/tmr/dragoncity/house4e.c

inherit ROOM;

void create()
{
	set("short", "少帥府－客房");
	set("long", @LONG
這裡是少帥府客人們的住處，整整齊齊的一排平房。門的左右兩邊各
是一張床，床上的被褥被疊得整整齊齊。床頭正對的地方擺著一張桌子，
旁邊還放著一張椅子。桌上整齊地放著文房四寶，旁邊還放著幾本書。地
上擺著一盆牡丹花，一絲清香縈繞房中。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"house4",
]));
	set("current_light", 1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhixuan" : 1,
]));


	setup();
	replace_program(ROOM);
}
