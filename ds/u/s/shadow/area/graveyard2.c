/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard2]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
施氏義莊雖然已經年代久遠了，但是從墳墓的數量、佔地之廣以
及極盡雕刻之能的墓碑，仍可看出其規模之氣派，想必在當時定是大
戶人家往生安置之處，只是讓人納悶的是究竟是何原因這原本人丁興
旺的施家怎麼會沒落，進而使這施氏義莊淪落為亂葬崗？看著四周破
舊不堪的墳墓與雜生的雜草藤蔓，總覺得有種莫名的恐懼。
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east": __DIR__"graveyard3",
		"west": __DIR__"graveyard4",
		"south": __DIR__"graveyard1",
		"north": __DIR__"graveyard21",
	]));
  
	setup();
	create_door("south","義莊大門","north", DOOR_OPENED, "nokey");
	
}

int valid_leave(object me, string dir)
{
	if( dir=="south" && !userp(me) )
		return notify_fail("那裡只有玩家才能通行。\n");
	return ::valid_leave(me, dir);
}
