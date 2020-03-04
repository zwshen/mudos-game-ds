// 紫陽山第一層森林

inherit ROOM;

void create()
{
	set("short", "紫陽山旁小森林");
	set("long", @LONG
這裡是紫陽山下旁邊一個小森林，你從山上縱跳下來，竟然落在這
的泥濘上，只見你的一些物品散落在地上，還是快點撿起來的好，旁邊
有一團白骨，不知道是誰的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"psin_forest2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("inquiry", ([
  "白骨" : "一團白骨, 旁邊似乎有張紙條. \n",
  "紙條" : "一張小紙條, 似乎有寫著些東東. \n",
]));
	setup();
}

void init()
{
//	add_action("do_get", "get");
}

int do_get(string arg)
{
	object me = this_player(), paper;
	if( arg == "紙條" )
	{
		paper = new(__DIR__"npc/obj/easy_paper.c");
		paper->move(this_player());
		message_vision("$N撿起了一張紙. \n", me);
		return 1;
	}
	else return 0;
}