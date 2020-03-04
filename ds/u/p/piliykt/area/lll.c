inherit ROOM;

void create()
{
        set("short", "神木");
        set("long", @LONG
你正站在大神木上, 你看了旁邊有許多的樹幹及樹枝, 互相連接成許
多條路, 你往上看只見一大推的樹葉擋住你的視線, 讓你想爬到最高處看
看神木村的風景.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "down" : __DIR__"big_tree.c",
          "north" : __DIR__"tree.c",
               ]));
            
        set("no_clean_up", 0);
        set("outdoors","forest");               
        setup();
        replace_program(ROOM);
}


