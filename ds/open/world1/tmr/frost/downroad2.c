// Room: /open/world1/tmr/freezetaoism/downroad2.c

inherit ROOM;

void create()
{
	set("short", "地下祕道");
	set("long", @LONG
你正在一條地下祕道裡，其通道不寬，約可容納一個人擠著身子通過
，通道盡頭有處通往更下一層的石梯。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"downroad3",
  "west" : __DIR__"downroad1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
