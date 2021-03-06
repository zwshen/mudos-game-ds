// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
樹林的密度在這裡有很大的差別，往西是較疏稀的，而東方卻是較為
密集。這裡有一些植物生長在樹下，聽說有些種類的植物還可以拿來做藥
。樹幹上披覆著一層青苔，還有些細小的水流從石縫間涓涓的流出。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out046",
	    "west" : __DIR__"out044",
	    "north": __DIR__"out039",
            ]));

	set("outdoors","forest");	// 樹林
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}