#include <path.h>
inherit MOBROOM;
void create()
{
	set("short", "旅館外圍");
	set("long", @LONG

  這裡是旅館的外圍草地, 附近還長了一些小樹和一些從來沒有看過的小型
石雕。旁邊還有條小水溝, 不過裡面沒有水, 只有一些飲料罐和塑膠袋。

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "west" : LOGIN_NOW,
  "north" : __DIR__"room1",
]));
	set("objects", ([
	__DIR__"npc/seller" : 1,
	]) );
//        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"npc/bug",
	__DIR__"npc/mosquito",
	}) );
	setup();
	
	//注意, 繼承MOBROOM後 絕不可以有 replace_program(ROOM);
}
