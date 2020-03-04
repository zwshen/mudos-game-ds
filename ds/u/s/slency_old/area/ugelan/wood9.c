// Room: /u/s/slency/area/ugelan/wood9.c

inherit ROOM;

void create()
{
	set("short", "影合湖湖畔");
	set("long", @LONG
你來到影合湖的湖畔，這裡長年無風，因此湖面幾乎沒有任何波動
，只有一些小小的漣漪，湖旁圍繞著高山，山的倒影清楚地呈現在水面
上，此處山嵐水影之妙，實不可言。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wood10",
  "south" : __DIR__"wood8",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
