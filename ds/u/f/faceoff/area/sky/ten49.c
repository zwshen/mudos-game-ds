#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"霧峰-山腰"NOR);
 set("long",@LONG
這條山路是連接霧峰及奇倪峰的主要道路，往北會通往
頗有盛名的霧峰，而往南則會回到十萬大山的最高峰，奇倪
峰....
LONG
    );
 set("exits",([  "southup":__DIR__"ten21",
                     "northup":__DIR__"ten50",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

