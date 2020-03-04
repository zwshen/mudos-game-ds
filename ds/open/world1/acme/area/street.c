inherit ROOM;

void create()
{
        set("short", "街道");
        set("long", @LONG
這裡是位於天城的南邊，東西兩邊盡是住家，往北的街道十分寬敞
往南可以離開天城，這裡灑掃的甚是乾淨，連片落葉都沒有。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sdoor",
  "north" : __DIR__"plaza2.c",
]));
         set("objects",([
             __DIR__"npc/man" : 1,
         ]));
        set("no_clean_up", 0);
         set("outdoors","land");
        setup();
        replace_program(ROOM);
}
