#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "神堂");
        set("long", @LONG
這裡是雲端的最尾邊 , 往下一探 , 離地萬尺 , 抬頭一望 
, 浩月千里 , 只見這裡的周圍 , 圍繞著薄薄的雲霧 , 有種神
聖不可侵犯的感覺 , 如果你在這裡做了什麼[0;7;31m�[7ma[7m�[7m�[0m ,可能會遭受
到天譴 。 這裡有一尊雕像 。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

