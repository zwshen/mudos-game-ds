inherit ROOM;

void create()
{
        set("short", "½YÀs«°");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room21",
  "west" : __DIR__"room23", ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

