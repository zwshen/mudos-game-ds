inherit ROOM;

void create()
{
        set("short", "港都大道");
        set("long", @LONG
這裡是貫通港都的主要道路，路面相當寬闊而且平整，兩旁林立著商家、店
面，西邊的岔路可以通往海岸邊。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"room14", 
  "west" : __DIR__"room10", 
  "north":__DIR__"room6",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

