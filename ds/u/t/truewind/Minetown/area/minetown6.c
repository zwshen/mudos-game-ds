// Room: /u/t/truewind/Minetown/area/minetown6.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
這裡是礦村邊緣的一塊空地，一道包圍礦村的牆往西延伸而去。
這裡空空蕩蕩的，什麼也沒有，不過被風刮來這裡的沙子非常多，附
近還有一條小排水溝流過。也許很適合小孩子玩堆城堡的遊戲。
LONG
	);
	set("current_light", 0);
	set("outdoors","land");
	set("objects", ([ 
        __DIR__"npc/child.c" :1 ,
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown7",
  "south" : __DIR__"minetown5",
  "east" : __DIR__"minetown2",
]));

	setup();
}
