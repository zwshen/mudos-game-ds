/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard22]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
不知跨過了多少座前人的墳墓，東西兩側依舊是難以計數的大小
墳墓，歪斜的墓碑越來越令人不寒而慄，望著這些讓你頭皮發麻的墳
墓群，你真希望能快點離開這個鬼地方。幸好北邊已經可看到有棟仿
廟宇的建築物，也許那將是個可以落腳的地方也說不定！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard32",
		"west": __DIR__"graveyard42",
		"south": __DIR__"graveyard21",
		"north": __DIR__"graveyard23",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(7))
	{ 
		case 3:
		case 2:
			message_vision(HIG"一盞鬼火從你面前冉冉飄過！\n"NOR, me);
			return 1;
		case 1:
			message_vision("∼ 嘰 嘎 吱∼ 你聽到指甲不斷抓扒木頭的聲音！\n", me);
			return 1;
		default:
			return 1;
	}
}
