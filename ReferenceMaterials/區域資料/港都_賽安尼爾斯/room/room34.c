inherit ROOM;

void create()
{
  set("short", "海軍分部－辦公室");
  set("long", @LONG
這裡是海軍辦公室，中間擺了一張大大的辦公桌，旁邊立著一些
旗子，右邊的牆上則張貼著許多的懸賞單，左邊牆上幾個大字寫著『
海軍港都分部』，南邊設有一個小牢房。 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room33",
      "south" : __DIR__"room37",
      "north" : __DIR__"room31",
     ])); 
  set("light",1);
  setup();
}
