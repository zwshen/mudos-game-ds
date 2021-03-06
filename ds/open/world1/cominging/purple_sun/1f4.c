// 紫陽山第一層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
四周一貫如一的風景，在山壁旁有些小溝，似乎是山上泉水流下時
所流下的痕跡，還有些小水在流動著，直通橫跨過山路，流下山底的森
林裡而去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"1f3.c",
  "southwest" : __DIR__"1f5.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("item_desc", ([
  "水溝" : "一道由山上流下的水渠, 水流相當的緩慢. \n",
]));
	setup();
	replace_program(ROOM);
}
