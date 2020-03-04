#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城西道");
        set("long", @LONG
四周的風景十分優雅迷人，輕輕的風緩緩的拂過你的臉龐，一陣暖意
自心頭升起，地上凹禿不平的小石頭似乎也變成平坦的柏油路，這裡的氣
氛簡直可媲美人間仙境，走著走著走到了第一家連線主城的車站，門口的
人群著實不少，看來可能是屬於[ 主城觀光團 ]的人吧？
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec5.c",
     "west":__DIR__"sec9.c",
     "enter":__DIR__"boot.c", 
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
