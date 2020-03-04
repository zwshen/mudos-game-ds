// Room: /u/k/kenshin/sha-zin-gu/room24.c

inherit ROOM;

void create()
{
        set("short", "[0;1;36mª[1mZ[1m¾[1mÇ[1m¤[1m§[1m¸[1mô[0m");
        set("long", @LONG
¶V¨Ó¶V±µªñªZ¾Ç¤§®a¡A·P¨üªºÀ£­¢·P¤]§ó°ª¤F¡A±q³o¸Ì´N¯àÅ¥¨ì
¸Ì­±ªº§Ì¤l½m®±ªº¦[³ÜÁn¡A¯u¬O¦³´Â®ð¡C©¹¦è¨«´N¯à¨ì¹F·v¤é¨¦ªº¹A
³õ¢wÀÆ¥ú¹A³õ¡C
LONG
        );
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room25",
  "south" : __DIR__"room11",
]));
        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
        replace_program(ROOM);
}

