/**
 * Shadow's area [湖底世界 - 淺灘 - a3]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"淺灘"NOR);
	set("long",@LONG
這兒的水位幾近胸膛，腳下踏著的是軟綿綿的泥土。南邊與西邊
的湖水顏色轉為深藍色，想必水深將會遽增，萬萬不可冒險。水裡的
魚蝦圍繞在你身邊打轉，一點也不怕你的到來，碧綠的湖水倒映出四
周的山明水秀，讓你不由得讚嘆大自然之美！
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits",([
		"east" : __DIR__"a4",
		"south" : __DIR__"a1",
	]));

	setup();
	replace_program(ROOM);
}

