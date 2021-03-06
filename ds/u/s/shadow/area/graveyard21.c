/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard21]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
跨過了一座又一座的墳墓，四周的墳墓卻彷彿無邊無際似地，始
終看不到盡頭。抬頭看著天空詭譎多變的顏色，你才赫然發現從踏入
這義莊後，世界彷彿都變了個顏色，陰暗沈悶的氣氛壓得你的心情更
加沈重，似乎有一不小心就會被這墓海給淹沒的感覺！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard31",
		"west": __DIR__"graveyard41",
		"south": __DIR__"graveyard2",
		"north": __DIR__"graveyard22",
	]));
 
	setup();	
}

int room_effect(object me)
{
	switch(random(6))
	{ 
		case 1:
			message_vision("∼ 叩 ∼ 叩 ∼ 你似乎聽到四周墳墓中傳來陣陣的敲擊聲！\n", me);
			return 1;
		default:
			return 1;
	}
}
