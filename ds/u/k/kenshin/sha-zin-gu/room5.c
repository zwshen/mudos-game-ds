// Room: /u/k/kenshin/sha-zin-gu/room5.c

inherit ROOM;

void create()
{
        set("short", "暇日谷入口");
        set("long", @LONG
這裡就是暇日谷的入口了，前有守衛兩名，聽說要進暇日谷，釋出
當地的通行證，如果不知在何處買，可以詢問一下守衛，便可知道何處
可買這一通行證。
LONG
        );
        set("outdoors", "land");
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room6",
  "south" : __DIR__"room4",
]));
        set("no_clean_up", 0); 

        setup();
        replace_program(ROOM);
}

