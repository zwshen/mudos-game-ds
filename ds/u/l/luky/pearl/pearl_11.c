// Room: /u/l/luky/room/pearl_11.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠西街"NOR);
set("long", @LONG

��╲                                                   ╱��
�� :╲    你正走在大街上。長途的跋涉讓你覺得有些疲   ╱: ��
�� : :▏倦，看著附近平常人家的房屋，你開始有點想在 ▕: : ��
�� : :▏這裡買塊地安定下來。道路向南北延伸而去。   ▕: : ��
�� :╱                                               ╲: ��
��╱                                                   ╲��

LONG
);
set("objects",([
__DIR__"npc/oceaner":1,
]));
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"pearl_12",
"south" : __DIR__"pearl_10",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
