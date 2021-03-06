/**
 * Shadow's area [荒廢漁村 - a5]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"竹屋內部"NOR);
	set("long",@LONG
竹屋的內部只有一些簡單的擺設，一張斑痕累累的矮桌，兩張看
起來不甚堅固的竹椅，你好奇地環顧四週，赫然發現床底下有一個相
當大的箱子，但是似乎已經上了鎖，鎖頭上的斑斑鏽蝕隱約透露出這
寶箱已有相當久遠的年代！
LONG
	);
	
	set("light",0);
	set("exits",([
		"out": __DIR__"a4",
	]));
	
	/* 設置一個寶箱 */	
	set("objects", ([
		__DIR__"item/box": 1,
	]));
        

	setup();
}

