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
        set("short", "海軍分部－會議室");
        set("long", @LONG
這裡是海軍幹部開會用的會議室，橢圓的長桌旁擺著七張椅子，前
    方掛著黑板還有幾幅海圖，透過窗戶看過去可以看到集合場。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room12",
  "south" : __DIR__"room34",
  //"north" : __DIR__"room26",
  //"east" : __DIR__"room28",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

