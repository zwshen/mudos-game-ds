// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "商業道路");
	set("long", @LONG
這裡的路段相當的筆直，開車的駕駛人常會不自覺的加快行車速度，
兩旁還有行車護欄，這條道路是通往奧凡迪斯正城門的道路，所以車輛的
數目也相當的多。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out034",
	    "north": __DIR__"out018",
            ]));
	set("light",1);
	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}