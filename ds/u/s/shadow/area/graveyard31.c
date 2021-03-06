/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard31]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
這兒似乎是義莊東側的邊緣地帶，朝東望去只見重重密林，看樣
子是不可能從中找到出路。北邊依舊是數不清的墓地，真讓人擔心是
否會迷失在這廣大的義莊之中。也許是靠近義莊邊緣的關係，這兒的
風開始大了起來，再加上原本陰森晦暗的墓地氣氛，讓你不自覺地縮
成一團！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"west": __DIR__"graveyard21",	
		"south": __DIR__"graveyard3",
		"north": __DIR__"graveyard32",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(3))
	{ 
		case 1:
			message_vision("你似乎感覺有雙手摸了摸你的腳！\n", me);
			return 1;
		default:
			return 1;
	}
}
