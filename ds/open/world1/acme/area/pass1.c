// Room: /u/a/acme/area/pass1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你正走在一條筆直的山路，四周盡是山木，高聳穿雲，往北遙望可看
見瀑布，瀑布遠遠望去倒似一條張牙舞爪的水中蛟龍，並不時的傳來嘶吼
聲。往南可通往天城，北邊可至天池。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pool",
  "south" : __DIR__"pass",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
