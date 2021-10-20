inherit ROOM;

void create()
{
  set("short", "碎石子路");
  set("long", @LONG
這段路的路旁是微高的土丘，土丘上有一些坑洞，可能有什麼動
物居住吧，路面上散落著土丘上滾下來的碎土塊。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northwest" : __DIR__"room48",
      "south" : __DIR__"room50",
     ])); 
  set("light",1);
  setup();
}
