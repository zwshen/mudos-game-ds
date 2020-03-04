// Room: /u/a/aring/tomb/5.c

inherit ROOM;

void create()
{
      set("short", "大墓園－東側大門");
	set("long", @LONG
    這裡是大墓園的大門，門口的石雕拱門已經毀壞的剩下一點柱腳
，四周零散地散落一些石雕像的碎片，往裡面望去大墓園呈中央微高
環繞小路的地形，從這裡可以看出整個墓園被[32m淡綠色[1;36m的霧氣籠罩住。

LONG
	);
	set("no_clean_up", 0);
	set("light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"4",
  "southeast" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
