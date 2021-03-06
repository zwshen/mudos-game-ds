/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard41]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
你走到義莊西側的邊緣，西面的高山看來險峻無比，勸你還是打
消了攀登的念頭。望來望去都是荒廢已久的墳墓，殘留在地上的焚香
與冥紙盡已成灰，若不仔細觀察定無法辨認是為何物，陰森森的氣氛
使你起了雞皮疙瘩，四周似乎都有奇怪的聲響，但卻無從辨別來源。
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard21",	
		"south": __DIR__"graveyard4",
		"north": __DIR__"graveyard42",
	]));
  
	setup();
	replace_program(ROOM);
}

