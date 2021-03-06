// Room: /u/t/truewind/Minetown/area/minetown4.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
這裡是礦村的一塊空地，空地上靠南的圍牆上堆滿了鼓鼓的塑膠
袋。南邊的礦工工寮把垃圾都裝袋放在這裡，讓清潔機器把垃圾回收
走。有幾袋垃圾破了，正發出奇怪的臭味，吸引了一些腐食蟲在附近
覓食。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("outdoors","land");
	set("objects", ([ 
        __DIR__"npc/meat-eat-worm.c" :2 ,
]));

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown5",
  "north" : __DIR__"minetown2",
  "east" : __DIR__"minetown3",
]));

	setup();
	replace_program(ROOM);
}
