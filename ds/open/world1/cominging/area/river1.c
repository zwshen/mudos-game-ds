#include <ansi.h>
#define BBLU ESC+"[44m"
inherit ROOM;
void create()
{
	set("short", "護城河");
	set("long",
NOR"\n"BBLU"　　　　　　　　　　　　　　　　　　　　　　　　　　 　　　"NOR"\n"NOR
BBLU""HIW"　　　﹏\﹏\﹏\﹏\﹏\﹏\　　　﹋﹋﹋﹋﹋　　　　　　　　 　　　　"NOR"\n"
BBLU""HIW"　　　﹋﹋﹋﹋﹋﹋﹏\ ﹏\ ﹏\　﹏\ ﹏\　　　　　　　　　　　　　"NOR"\n"
BBLU""HIW"﹏\  ﹏\ 　　　　　　﹋﹋﹋﹋　﹋﹋﹋　　　　　　　　　　　　"NOR"\n"
BBLU""HIW"﹋﹋﹋﹋　　　　﹏\﹏\﹏\﹏\﹏\　　　　　　　﹏\﹏\﹏\ 　　　　　　"NOR"\n"
BBLU""HIW"　　　　　　　　﹋﹋﹋﹋﹋　　　　　　　﹋﹋﹋　　　　　 　"NOR"\n"NOR"\n"
NOR""
"這裡是步靈城東南邊外護城河，在這裡有許\多小動物。\n"
	);
	set("exits", ([
  "north" : __DIR__"river2.c",
  "west"  : __DIR__"river.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}