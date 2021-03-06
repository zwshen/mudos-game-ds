// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "商業道路");
	set("long", @LONG
這條奧凡迪斯對外的道路，是條相當寬敞的商業道路，車子來來往往
的相當的頻繁，道路中間的路燈排成一整排，到了晚上可是相當的明亮呢。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out020",
	    "west" : __DIR__"out018",
	    "south": __DIR__"out027",
            ]));

	set("light",1);
	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}