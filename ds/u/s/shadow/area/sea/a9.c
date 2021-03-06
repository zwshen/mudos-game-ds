/**
 * Shadow's area [湖底世界 - 海底監牢 - a9]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"海底監牢"NOR);
	set("long",@LONG
天然的石壁，但是有人工刻鑿的痕跡。海水在此處異常地平靜，
似乎沒有任何外力可以干擾這兒...。緩緩地水流與監牢的陰森毫不
搭調，似乎有種奇怪的力量控制著這海底監牢。
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a10",
		"north" : __DIR__"a11",
		"southwest" : __DIR__"a8",
	]));

	setup();
	replace_program(ROOM);
}

