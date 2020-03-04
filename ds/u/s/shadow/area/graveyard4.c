/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard2]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
這裡的墳墓似乎更為凌亂，支離破碎的骨骸四處散落，地上散佈
著密密麻麻分不出是動物還是人類的的腳印。靠近你腳邊的頭蓋骨缺
了一個大洞，看樣子死者身前死狀必定其慘無比，真想不透在這施氏
義莊中究竟出了甚麼變故！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east": __DIR__"graveyard2",
		"north": __DIR__"graveyard41",
	]));

	/*
	set("objects",([
	__DIR__"npc/dog1": 8+random(3),
	]));  
	*/
  
	setup();
	replace_program(ROOM);
}

