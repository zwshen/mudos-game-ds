// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
你看到這裡有許多的樟樹(camphor)生長在奧凡迪斯的城牆旁邊，大
太陽底下的曝曬使得濃郁的樟樹香瀰漫著這裡。往南走就是通往奧凡迪斯
西邊側門的道路。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out002",
	    "south": __DIR__"out006",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
