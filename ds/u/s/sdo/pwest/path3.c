inherit ROOM;

void create()
{
	set("short", "森林裡");
	set("long", @LONG
這座森林出乎意外的生氣蓬勃。在頭上的盤旋飛翔的各種鳥類，
還有偶而從腳邊一竄而過小動物，讓你感覺到再這古老的森林裡依然
充滿著活力。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"path2",
  		"northeast" : __DIR__"path4",
	]));

	setup();
	replace_program(ROOM);
}
