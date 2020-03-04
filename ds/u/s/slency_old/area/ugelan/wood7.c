// Room: /u/s/slency/area/ugelan/wood7.c

inherit ROOM;

void create()
{
	set("short", "森林深處");
	set("long", @LONG
在這裡你發現有許多小木屋夾雜在樹林中，中央有營火燒過的橫跡
看來有不少的人住在這個隱密的小村落裡，不過從四周寂靜的程度看來
，這個村莊裡現在應該一個人也沒有。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wood6",
]));
	set("objects", ([ /* sizeof() == 1 */
	 __DIR__"npc/bandit1" : 3, 
]));
	set("outdoors", "forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
