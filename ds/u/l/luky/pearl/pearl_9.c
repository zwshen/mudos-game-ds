// Room: /u/l/luky/room/pearl_9.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠南街"NOR);
set("long", @LONG

＿＿＿＿＿   你正走在熱鬧的大街上。西方傳來一  ＿＿＿＿＿＿
"  .   -   股很濃的藥味，而你看見許多冒險者從     -  '    "
:      -   東方的一棟建築物中走出來。地上畫著     -    "  :
= ."   -   一些格子，讓你想起小時後最愛玩的一     -       =
==-  " -   種遊戲…跳格子。               -       - .   -==
￣￣￣￣￣                   ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
);
set("exits", ([ /* sizeof() == 2 */
 "west" : __DIR__"pearl_10",
 "east" : __DIR__"pearl_8",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
