inherit ROOM;

void create()
{
        set("short", "港都大道");
        set("long", @LONG
這裡是貫通港都的主要道路，路面相當寬闊而且平整，兩旁林立著商家、店
    面，從西邊的道路看過去可以看到澎派的海岸。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room14",
  "south" : __DIR__"room39",
  "north" : __DIR__"room32",
  //"east" : __DIR__"room34",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

