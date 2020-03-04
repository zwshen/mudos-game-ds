// Room: /u/d/darkfool/area1/34.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
你已經走到街道的盡頭了，這裡感覺上特別的昏暗，角落的幾間
房子看來也是很久沒住人了，有幾間甚至因為太久沒保養而鏽跡斑斑
，你看著滿地的垃圾飄來飄去，疑惑這裡到底有什麼特別，居民們好
像故意遺忘了這個角落。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"33",
]));

	setup();
	replace_program(ROOM);
}
