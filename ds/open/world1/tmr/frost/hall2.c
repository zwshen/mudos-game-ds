// Room: /open/world1/tmr/frost/hall2.c

inherit ROOM;

void create()
{
	set("short", "大高玄殿");
	set("long", @LONG
大高玄殿座北向南，呈長方形，門前原有旗杆，殿前為月臺，兩側配殿
各五間。正殿之後是面闊五間的九天應元雷壇。大高玄殿為象徵天圓地方的
兩層樓閣，上層圓錐形屋頂，象徵天，曰乾元洞；下層成方形，象徵地，曰
坤貞宇。整個建築佈局嚴謹，氣勢雄偉，精巧細緻。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"court3",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
        set("objects", ([
                 __DIR__"npc/yun-zhong-zi":1,
        ]) );



	setup();
	replace_program(ROOM);
}
