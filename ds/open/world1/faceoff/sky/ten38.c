#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"滅骨峰"NOR);
 set("long",@LONG
踏上了實地的感覺讓你又勇氣大增, 完全沒有注意到你
的身旁還有一位形跡奇異的老叟, 而這裡的風景也極為壯觀
, 只見你腳下翠綠一片,想必就是東北澤林了吧, 而那建築物
目前是在你的南邊下方幾丈處, 不知道到底是什麼?
LONG
    );
 set("exits",([  "north":__DIR__"ten37",
    ]));
set("objects", ([    __DIR__"npc/monk" : 1,
]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

