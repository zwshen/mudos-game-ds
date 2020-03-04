#include <path.h>

inherit ROOM;
//string look_sign(object me);
void create()
{
	set("short", "時空走廊");
	set("long", @LONG
這裡是旅館的中央走廊。東邊的牆上掛滿了古代俠士的畫像及許多英
勇事蹟的記載，西邊牆上則掛了許多現代的科技武器的圖鑑。你看到東邊
、西邊和北邊的門上分別刻著【古之夢房】、【今之夢房】與【未之夢房
】四個小字。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
 "north" : __DIR__"hall3",
 "south" : __DIR__"hall",
 "east" : __DIR__"pastroom",
 "west" : __DIR__"nowroom",
	]) );
	set("item_desc", ([
//		"note": (: look_sign :),
//		"告示": (: look_sign :),
	]) );
	set("light",1);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}
/*
string look_sign(object me)
{
   if( file_size("/open/world2/anfernee/start/note.txt") > 0 )
   {
    me->start_more( read_file("/open/world2/anfernee/start/note.txt") );
    return "\n";
   } else return " SORRY. 說明建構中. \n";
}
*/
