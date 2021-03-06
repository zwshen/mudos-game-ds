// Room: /u/s/slency/area/ugelan/wood1.c

inherit ROOM;

void create()
{
	set("short", "西城門");
	set("long", @LONG
這裡是幽遮蘭城西面的城門，往東走便是幽遮蘭城了，由這裡往西
走可以到達幽遮蘭城附近著名的密比斯森林，這座森林相信大家都耳熟
能詳，當每個人聽到這個名字時，總是臉色蒼白，原來自兩年前，凡是
進入此森林的人，都再也沒有出來，這令人懷疑是否有什麼猛獸潛伏在
此森林裡，之後就再也沒有居民敢進入這座令人心驚的森林了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood2",
  "east" : __DIR__"road12",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
