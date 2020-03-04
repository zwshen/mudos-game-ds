// Room: /u/s/slency/area/ugelan/wood10.c

inherit ROOM;

void create()
{
	set("short", "山崖");
	set("long", @LONG
你的面前是一座高崖，崖頂入雲，崖壁上沒有任何的植物，你不禁
有些好奇崖上有些什麼，不過這麼高的山崖你想你是不可能上得去的，
看看附近的風景，並沒有什麼特別之處，不過倒是有顆巨石的擺放有些
奇怪。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wood9",
]));
	set("item_desc", ([ 
     "巨石" : "一顆巨大的石頭，其地面上有磨擦的痕跡，你可以試試看推開(push)它\n"
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
}
void init()
{
    add_action("do_push", "push");
}
int do_push(string arg)
{
	if(arg != "巨石") return 0;
	write("你使出你吃奶的力氣用力地推!!巨石移動了!!\n\n");
	this_player()->move(__DIR__"cave1");
	return 1;
}
