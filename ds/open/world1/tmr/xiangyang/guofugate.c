// Room: /d/xiangyang/guofugate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "郭府大門");
	set("long", 
"一座建築古樸的大宅院出現在你的眼前。只見門樓高挑，
上書兩個大字"HIY"
                     郭   府
"NOR"
    全真教第二代弟子耶律齊和幾個家丁站在門前接待前來保
衛襄陽的各方義士。\n"
 );
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"westjie1",
		"north" : __DIR__"guofuyuan",
	]));
	set("objects", ([
//          __DIR__"npc/yelvqi" : 1,
          __DIR__"npc/jiading" : 2,

	]));
	set("coor/x", -520);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
