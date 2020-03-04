// Room: /u/d/domy/workroom.c

inherit ROOM;

void create()
{
        set("short", "[32m¦h¦Ì¤p¯¸[0m");
        set("long", @LONG
§A²{¦b©Ò¦b¬O¦h¦Ì¤p¯¸ªù«e¡A¦h¦Ì¨p¤H¿ì¤½«Ç
¡A²{¥N®ÉªÅªº¤u§@ÆU.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "eeman" : "/u/e/eeman/workroom",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"area/npc/lieutenant" : 1,
]));
        set("no_clean_up", 0);
set("valid_startroom", 1);
setup();
call_other("/obj/board/domy_b.c", "???");
      
}

void init()
{

write("~~~~~[35mÅwªï¨Ó¨ì¦h¦Ì¤p¯¸[0m~~~~~\n"); 
}


