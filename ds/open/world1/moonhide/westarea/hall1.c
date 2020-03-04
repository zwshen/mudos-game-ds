// Room: /open/world1/moonhide/westarea/hall1.c

inherit ROOM;

void create()
{
        set("short", "觀測平台");
        set("long", @LONG
觀測平台是雲端空島上的一處空地，在觀測平台出去就是大片
無盡的藍天，要是失足踩空，可是會摔的粉身碎骨。觀測平台四週
有一些金屬長筒似的儀器，居民常用來觀察跟了解天文。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"way4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("objects", ([
                __DIR__"npc/trainee" : 3,
        ]) );

        setup();
        replace_program(ROOM);
}

