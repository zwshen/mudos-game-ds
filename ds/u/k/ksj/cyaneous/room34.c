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
        set("short", "海軍分部－辦公室");
        set("long", @LONG
這裡是海軍辦公室，中間擺了一張大大的辦公桌，旁邊立著一些旗
    子，右邊的牆上則張貼著許多的懸賞單，左邊牆上幾個大字寫著
    "海軍港都分部"，南邊設有一個小牢房。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room33",
  "south" : __DIR__"room37",
  "north" : __DIR__"room31",
  //"east" : __DIR__"room34",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

