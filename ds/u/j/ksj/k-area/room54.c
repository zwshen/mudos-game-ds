inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG 
這條道路的路面用石板鋪成，可以容納兩台馬車並行，路上不時有商賈隊伍急
    急趕路，偶爾還有奇怪的人攙雜其中。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"northeast" : __DIR__"room54",
  "east" : __DIR__"room55",
  //"north" : __DIR__"room34",
  "southwest" : __DIR__"room53",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

