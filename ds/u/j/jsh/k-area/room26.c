inherit ROOM;

void create()
{
        set("short", "港都大道");
        set("long", @LONG
這裡是貫通港都的主要道路，路面相當寬闊而且平整，兩旁林立著商家、店
    面，路上可以看到形形色色的人走動。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room25",
  "south" : __DIR__"room29",
  "north" : __DIR__"room23",
  "east" : __DIR__"room27",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

