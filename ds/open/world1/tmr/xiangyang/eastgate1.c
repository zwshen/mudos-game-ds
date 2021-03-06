// Room: /d/xiangyang/eastgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "青龍內門");
	set("long", 
"這裡是襄陽城的東城門的內城門，只見城門上方是三個大
字。"HIG"

                      青龍門
\n"NOR
"近年來蒙古屢次侵犯襄陽城，故這兒把守相當嚴密，一些官兵
們正在盤查要離襄陽城的人。兩邊是上城頭的石階，向西進入
城區。\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southup" : __DIR__"walle1",
		"northup" : __DIR__"walle2",
		"west"    : __DIR__"eastjie3",
		"east"    : __DIR__"eastgate2",
	]));
	set("objects", ([
		__DIR__"task/pi2"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}
