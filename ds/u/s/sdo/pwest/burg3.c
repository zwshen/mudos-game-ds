inherit ROOM;

void create()
{
	set("short", "村子裡小路");
	set("long", @LONG
悠閒的走在這裡，看見沿著這附近有幾塊小農田，有些裡面種著
小麥，有些則是種著一些蔬菜，看來村人是過著自給自足的生活。往
西邊看過去，有一戶人家孤立在農田中央。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"burg1",
  		"west" : __DIR__"burg4",
	]));

	setup();
	replace_program(ROOM);
}
