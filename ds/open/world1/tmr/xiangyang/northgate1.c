// Room: /d/xiangyang/northgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "玄武內門");
	set("long", 
"這裡是襄陽城的北城門的內城門，只見城門上方是三個大
字。"HIB"

                      玄武門
\n"NOR
"近年來蒙古屢次侵犯襄陽城，故這兒把守相當嚴密，一些官兵
們正在盤查要離襄陽城的人。兩邊是上城頭的石階，向南進入
城區。\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"eastup" : __DIR__"walln1",
		"westup" : __DIR__"walln2",
		"south"  : __DIR__"northjie",
		"north"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"task/pi1"   : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
	replace_program(ROOM);
}
