// Room: /open/world1/tmr/dragoncity/house4n.c

inherit ROOM;

void create()
{
	set("short", "少帥府－臥室");
	set("long", @LONG
這裡就是寇仲的臥室。屋子裡的陳設很簡單。門的左邊有一張軟床。
床上的被褥被疊得整整齊齊。床頭正對的地方擺著一張梳妝台。桌上擺著
一個光亮的銅鏡，銅鏡旁邊的花瓶裡，有一束百合花，正在散發出淡淡的
幽香。裡邊放著兩張木椅，中間是一茶几，上面擺著一盆山茶花。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"house4",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
