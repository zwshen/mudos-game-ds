#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城南道");
        set("long", @LONG
一條很寂靜的街道，似乎全世界都凍結了，在這種完美的地方，為啥
一個人都沒有呢？微風輕輕的吹來，你的心情跟的活潑起來，北方就是整
個Secret City 的正中央了，阿！世界還是依舊美好，所謂情溢乎詞，可
能就是指現在的心情吧。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec3.c",
     "north":__DIR__"sec5.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
