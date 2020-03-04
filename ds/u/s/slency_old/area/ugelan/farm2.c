// Room: /u/s/slency/area/ugelan/farm2.c

inherit ROOM;

void create()
{
	set("short", "幽遮蘭城外的莊園");
	set("long", 
"這裡是幽遮蘭城外附屬的莊園，天空中飛翔著白鷺鷥，一片祥和的\n""氣息使你的心情舒暢了不少，莊農們勤快地耕種著，就好像是處在桃花\n""源中，自給自足，無憂無慮。\n"

	);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"farm4",
  "west" : __DIR__"farm1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/cow" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
