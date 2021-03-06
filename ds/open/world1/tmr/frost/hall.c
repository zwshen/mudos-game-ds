// Room: /open/world1/tmr/frost/hall.c

inherit ROOM;

void create()
{
	set("short", "三元殿");
	set("long", @LONG
三元殿座北面南，殿宇依山而築，正殿內供奉天、地、水三官大帝塑
像。三元殿在柱上和內外簷的枋上安裝斗拱，用以承托梁頭、枵頭和支撐
出簷的重量，出簷越遠，斗拱的層數也越多，形成優美而多變的曲線，使
本來沉重的大屋頂變得透逸典雅，形成了一種曲與直、靜與動、剛與柔的
和諧美。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"court3",
]));
	set("current_light", 1);
        set("objects", ([
                __DIR__"npc/mo-yue-ding":1,
        ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
