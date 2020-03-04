// Room: /u/s/slency/area/ugelan/defense.c

inherit ROOM;

void create()
{
	set("short", "防具店");
	set("long", @LONG
這裡是一間專賣護盾等防護裝備的商店，牆上掛著玲瑯滿目的護具
，你可以清楚地聽到屋後敲打冶鐵的聲音，這裡的生意十分熱絡，聽說
這裡所出產的護具不僅品質優良，且價格合理喔，往南可以回到街道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
