// Room: /u/l/luky/room/pearl_12.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠西街"NOR);
set("long", @LONG

��╲                                                   ╱��
��▕＿    這裡是碧雷爾鎮的西方街道。傳說這裡就是召   ╱: ��
��▕ :▏喚術的發源地，故有不少傾心於鑽研上古咒術的 ▕: : ��
��▕ :▏施法者都聚集於此，其目的就是為了探索召喚術 ▕: : ��
��▕￣  的秘密。                                     ╲: ��
��╱                                                   ╲��

LONG
);
set("exits", ([ /* sizeof() == 3 */
"west" : __DIR__"pearl_26",
"south" : __DIR__"pearl_11",
"north" : __DIR__"pearl_13",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
