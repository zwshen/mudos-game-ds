// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
樹林間充滿著濃郁的芬多精，清新的空氣讓你怡然自得。在樹木與樹
木之間也會有各種草類植物生長，有些還可以當作藥材。地上似乎有幾隻
小鹿出沒在這裡的腳印。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out045",
	    "west" : __DIR__"out043",
            ]));

	set("outdoors","forest");	// 樹林
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
