/*
  [配置]水果販(Fruiterer)
  [配置]肉販(Meatman)
  [配置]魚販(Fishmonger)
  [配置]菜販(Greengroser)
*/
//海軍長官 1 位
inherit ROOM;

void create()
{
        set("short", "港都大道");
        set("long", @LONG
這裡是貫通港都的主要道路，路面相當寬闊而且平整，兩旁林立著商家、店
    面，路旁可以看到海軍分部的大門及建築。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room13",
  "south" : __DIR__"room35",
  "north" : __DIR__"room29",
  "east" : __DIR__"room33",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

