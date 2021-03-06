/**
 * Shadow's area [湖底世界 - 湖底監牢盡頭 - a12]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"湖底監牢盡頭"NOR);
	set("long",
"監牢的路在這裡到了盡頭，四周擺\滿了各式各樣的珍珠與貝殼，\n"
"前方就是監禁室的門口，入口有著一扇半月形的"HIY"小門"NOR"，你嘗試著進入\n"
"監禁室，然而門前似乎被什麼給檔著讓你不得其門而入。\n"
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"south" : __DIR__"a10",
		"west" : __DIR__"a11",
	]));
	set("item_desc", ([
		"小門" : "一扇半月形的門，門上有兩個形狀奇怪的洞，看起來很像是鑰匙孔(hole)。\n",
		"hole" : "兩個洞孔(left hole, right hole)。\n",
		"left hole" : "貝殼型的洞孔，可以放入鑰匙看看(put)。\n",
		"right hole" : "魚型的洞孔，可以放入鑰匙看看(put)。\n",
		]));

	setup();

}

void init()
{
	add_action("do_put", "put");
}

int do_put(string arg)
{
}
