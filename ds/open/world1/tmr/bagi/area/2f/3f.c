// Room: /open/world1/tmr/bagi/area/2f/3f.c
#include <room.h>
inherit DOOR;

inherit ROOM;

void create()
{
        set("short", "石室");
        set("long", @LONG
你正處在一間石室內，四週的牆壁滿是血跡和武器砍打的痕跡，室角
還有七、八具已風乾的人骨，身上的血肉、衣服都已經爛的精光，似乎是
在數十年前發生的事。雖然是在地上的石室內，但還是非常的燥熱。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "east":__DIR__"3f-1",
          "up" : __DIR__"map_17_10",

        ]));
        set("current_light", 1);
        set("light",1);
        setup();
        create_door("up","石門","down",DOOR_LOCKED,"bagi_key");
}

