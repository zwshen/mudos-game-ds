inherit ROOM;

void create()
{
  set("short", "海岸");
  set("long", @LONG
這裡是港口的海岸邊，腳底下是用石塊鋪成的道路，岸邊放有許
多大岩石用來抵擋海浪的侵襲，路旁有些海蟑螂在四處逃竄。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"room13",
      "west" : __DIR__"room4",
      "northwest" : __DIR__"room11",
      "east" : __DIR__"room29",
     ]));
  set("outdoors","land");
  setup();
}
