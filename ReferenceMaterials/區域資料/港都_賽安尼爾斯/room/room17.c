inherit ROOM;

void create()
{
  set("short", "南角燈塔");
  set("long", @LONG
佇立在港口南方的燈塔，用石塊堆砌而成，高約十幾碼，夜晚或
天候不佳時會燃燒火堆做為船隻入港的指引，往南邊望去可以看到遠
方煙霧繚繞的皮斯活火山。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room16",
     ]));
  set("outdoors","land");
  setup();
}
