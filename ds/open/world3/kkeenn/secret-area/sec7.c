#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城東端");
        set("long", @LONG
這裡是地下城的東走道的盡頭，在這條街上有許多從地上聖˙都來
觀光的地上人，北邊的通道通往地下城的專屬礦坑，許多的礦工都以遷
居到那裡去，以方便工作。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec6.c",
     "north":__DIR__"min1.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
