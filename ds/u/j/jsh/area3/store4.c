inherit ROOM;

void create()
{
        set("short", "步靈市集");
        set("long", @LONG 
這攤是步靈城裡大家公認的好攤子，這裡所打造出來的武器，可以
說是好啊 !攤販老闆不斷的叫賣，叫賣的程度幾乎把整個市集的吵雜聲
給蓋了過去，可見生意好的不得了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"store2", 
  "north" : __DIR__"store6",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"storeman4" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

