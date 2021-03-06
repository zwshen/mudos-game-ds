// Room: /u/a/acme/area/lea3.c

inherit ROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你身處在一望無際的大草原，四周的野草略為高大，行走時便覺得有
點困難，你可聽見春蟬在「知了∼知了∼」的叫著，顯得生氣盎然。你發
現草原上散落著一些白色的石頭。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lea2",
  "north" : __DIR__"lea4",
  "west" : __DIR__"lea6",
  "east" : __DIR__"lea10",
]));
	set("item_desc",([
 "石頭":"你仔細一看，發現這些石頭排列的十分規律，似乎是個石陣。\n",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("objects", ([
       __DIR__"npc/antelope" : 4,
    ]) );
	set("moon_club_enter",1); //月族幫會入口
	setup();
	replace_program(ROOM);
}
