/**
 * Shadow's area [荒廢漁村 - 義莊入口 - graveyard1]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊入口"NOR);
	set("long",
"走著走著你居然走到了一個牌坊前，抬頭一看，橫匾上隱約可以\n"
"看出題著"HIG"「施氏義莊」"NOR"四個大字。因年代久遠的關係，橫匾的四周皆\n"
"已剝落，張牙舞爪的藤蔓也爬滿了整座牌坊，更凸顯此義莊的疏於管\n"
"理。往前望去，周遭皆是一座又一座的墳墓，雜亂地安置在這高高低\n"
"低的丘陵上，駭人的是地上竟散落了人死後所留下來的骸骨！看來這\n"
"兒雖名為義莊，但在年久失修且無人管理下卻實已淪為亂葬岡了..\n"
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"south": __DIR__"oldway2",
		"north": __DIR__"graveyard2",
	]));
  
	setup();
	replace_program(ROOM);
}

