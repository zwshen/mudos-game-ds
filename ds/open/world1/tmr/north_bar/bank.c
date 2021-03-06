// Room: /open/world1/tmr/north_bar/bank.c

inherit ROOM;

void create()
{
	set("short", "錢莊");
	set("long", @LONG
這是一間全用青綠竹子搭建而成的錢莊，涼爽的和風由竹子
與竹子之間的夾縫迎面吹來，帶給人們神清氣爽的氣氛。你注意
到東邊竹牆上有塊木匾(board)，上頭清清楚楚寫著本錢莊提供
的項目。
LONG
	);
	set("no_clean_up", 0);
        set("objects",([        
                __DIR__"npc/jin-kai" : 1,
        ])      );

	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"town18",
]));
	set("current_light", 1);
	set("light", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "board" : "   本錢莊提供的服務有:

deposit      : 存錢
withdraw     : 提錢     

",
]));
	set("room_type", "bank");
	set("no_kill", 1);

	setup();
	replace_program(ROOM);
}
