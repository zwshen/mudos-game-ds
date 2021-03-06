// Room: /u/t/truewind/Minetown/area/machinefield2.c

inherit ROOM;

void create()
{
	set("short", "漂浮車維修廠");
	set("long", @LONG
這裡是各類漂浮車維修的工廠，放眼望去，各式各樣的漂浮車堆
的跟山一樣高，幾乎要遮蔽了你的視線。有臺重力壓縮機正在壓縮不
需要的漂浮車，被壓縮過的車輛會根據組成的元素分解到不同的壓縮
機儲藏槽中。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"machinefield1",
  "west" : __DIR__"machinefield5",
  "south" : __DIR__"machinefield3",
]));

	setup();
	replace_program(ROOM);
}
