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
      "southeast" : __DIR__"room12",
      "west" : __DIR__"room3",
      "northwest" : __DIR__"room10",
      "east" : __DIR__"room25",
     ]));
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/sea-cockroach":3,
     ]));
  setup();
}
