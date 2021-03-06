// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"異教徒禮堂內"NOR);
	set("long", @LONG
在你的頭頂上的屋頂是由彩色的玻璃所拼湊而成，看不懂這些圖案所
代表的含意。在前方有一個臺子(Estrade)， 而旁邊是兩排的長桌，桌上
卻沒有放置任何的物品，只有幾根蠟燭正在燃燒著。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room092",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	set("item_desc", ([
		"estrade":"這個臺子上放著一本沒有闔上的厚書(Book)。\n",
		"book":   "上面寫滿了密密麻麻的文字，而最讓你失望的是那些文字好像並不太認識你耶。\n"
     ]) );

	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{

	if(!arg) return 0;
	if( arg != "the book" )	return 0;
	write("Yes...哈...哈...你打開了這本書...也跟著打開了你往後悲慘痛苦的人生了...\n"
		"你感到有種莫名的失落感降臨到你的身上了...\n");
	return 1;
}