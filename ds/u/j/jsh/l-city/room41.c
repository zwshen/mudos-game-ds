inherit ROOM;

void create()
{
        set("short", "長城");
        set("long", @LONG
test 
此為連接『未命名 -城』
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"room40", 
  //"southwest" : __DIR__"room40", 
  //"east" : __DIR__"room38", 
]));
set("light",1);

        setup();
}

