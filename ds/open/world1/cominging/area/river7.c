#include <ansi.h>
#include <path.h>
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
"這裡是步靈城西南邊外護城河，在這裡有許\多小動物。\n"
        );
        set("exits", ([
  "north" : __DIR__"river6.c",
  "east"  : __DIR__"river.c",
  "west"  : COMINGING_PAST + "purple_sun/psin.c",
  "southwest" : LINJACK_PAST + "emperor/path1.c",
]));

        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

