// Room: /u/t/truewind/Minetown/area/sewer1.c

inherit ROOM;

void create()
{
	set("short", "下水道");
	set("long", @LONG
你來到一個陰暗潮濕的下水道，空氣裡有一種說不出來的味道，
讓你很想馬上離開。附近有蟑螂老鼠跑來跑去，你彎腰下來仔細的看
了一下，注意到這裡的生物似乎長的有點奇怪...??
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"machinefield5",
]));
	set("current_light", 0);

	setup();
}
