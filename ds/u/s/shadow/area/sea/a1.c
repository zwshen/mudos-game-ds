/**
 * Shadow's area [湖底世界 - 浮橋下]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"浮橋下"NOR);
	set("long",@LONG
跳下了浮橋，你的雙足已然半陷於湖水之中，往四周一望，四周
盡被這大湖所包圍。站在這兒任由一波波的浪水打在你的雙腳上，頓
覺一陣舒暢快意，水裡的小魚小蝦原本在橋下的石縫間游來游去，這
時卻都游了出來在你腳邊周圍打轉。
LONG
	);
	set("light",1);
	set("outdoors", "land");
	set("exits",([
		"east" : __DIR__"a2",
		"north" : __DIR__"a3",
	]));

	setup();

}

int room_effect(object me)
{
	switch(random(10))
	{ 
		case 1:
			message_vision("一陣浪打來，濺濕了你的衣服。\n", me);
			return 1;
		default:
			return 1;
	}	
}

