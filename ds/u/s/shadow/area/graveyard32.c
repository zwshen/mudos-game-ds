/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard32]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
這兒似乎是義莊東北側的邊緣地帶，東邊的密林讓你打消了從東
邊離去的念頭，北邊的高牆亦阻擋了你的去路！看了看圍繞著你的墓
堆，再望望西邊與南邊，幾乎都是千篇一律長滿了雜草的墳墓，飛揚
的塵土讓你更加心浮氣躁，恨不得插上翅膀飛離這鬼地方！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"west": __DIR__"graveyard22",
		"south": __DIR__"graveyard31",
	]));
  
	setup();
	replace_program(ROOM);
}
