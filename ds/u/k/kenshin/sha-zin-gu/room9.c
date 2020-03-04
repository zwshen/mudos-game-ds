// Room: /u/k/kenshin/sha-zin-gu/room9.c

inherit ROOM;

void create()
{
        set("short", "[0;1;32m°[1mÓ[1m©[1m±[1mµ[1mó[0m");
        set("long", @LONG
³o¸Ì´N¬O·v¤é¨¦ªº°Ó©±µó¤F¡A³o¸Ì¦³³\¦hªº©±®a¡A¨Ò¦pªZ¾¹çE¡B
¨¾¨ã©±µ¥µ¥¡A¦pªG§A¯Ê¤°»òªº¸Ü¡A¥i¥H¨ì¦¹¦a¨Ó¬Ý¬Ý¡AÀ³¸Ó¦³§A¯Êªº
ª««~¡C
LONG
        );
        set("outdoors", "land");
        set("current_light", 3);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"room8",
  "east" : __DIR__"room14",
  "northwest" : __DIR__"room15",
  "north" : __DIR__"room12",
  "south" : __DIR__"room13",
]));

        setup();
        replace_program(ROOM);
}

