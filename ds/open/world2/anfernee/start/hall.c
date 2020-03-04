// bug.c
#include <path.h>
inherit ROOM;
string look_sign(object me);
void create()
{
	set("short", "旅館大廳");
	set("long", @LONG
這裡是夢幻旅館的大廳。大廳中央有個螺旋狀的樓梯，前方不遠有條
走道，兩旁牆上貼了一些告示(Note)。左手邊有個長廊，長廊的另一端泛
著神秘的紫色光芒，使人感覺到裡面有不可思議的偉大力量。右邊則是本
旅館的商品交易處。

LONG
	);
	set("objects", ([
	__DIR__"npc/master" : 1,
	ALWAYS"newspaper": 1,
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"login",
 "west" : __DIR__"bug",
 "east" : __DIR__"shoproom",
 "north": __DIR__"hall2",
 "up": __DIR__"prayroom",
// "past" : TMR_PAST"area/hotel",
	]) );
	set("item_desc", ([
		"note": (: look_sign :),
		"告示": (: look_sign :),
	]) );
	set("light",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
	call_other( "/obj/board/login_b", "???" );
}

string look_sign(object me)
{
   if( file_size("/open/world2/anfernee/start/note.txt") > 0 )
   {
    me->start_more( read_file("/open/world2/anfernee/start/note.txt") );
    return "\n";
   } else return " SORRY. 說明建構中. \n";
}

