// Room: /open/world1/tmr/frost/observatory.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-觀景台");
	set("long", @LONG
觀景台雖然位於倚霄山半山腰，佔地不高，但由於此處面臨溪谷，往
北方望去的視野內盡是一片開闊，上仰月星、下觀溪林，由晨至夜，勝景
無時無刻都不一，其千變萬幻而奪天地之美處，只有真正見識過的人才能
體會，不是三言兩語就能道盡的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hill1",
  "east" : __DIR__"observatory2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bisongbo" : 1,
]));

	setup();
	replace_program(ROOM);
}
