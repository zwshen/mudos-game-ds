#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"龍井棧道"NOR);

 set("long",@LONG
這裡是一條由官府所修整的官道, 所以是十萬大山中最可
以稱為是路的路, 原來可以由這條棧道直接以三天腳程度過十
萬大山, 可是此路已在前方不遠處斷了, 你可以在東北方不遠
處看到一間小客棧.
LONG
    );
 set("exits",([ "north":__DIR__"ten_mountain9",
               "east":__DIR__"ten_mountain4",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
