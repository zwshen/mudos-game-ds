inherit ROOM;

void create()
{
  set("short", "商店街－二手商店");
  set("long", @LONG
這裡是間二手商店，專門買賣舊貨，想買便宜貨或是身上有不要
的裝備都可以在這個地方交易。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room39",
      "east" : __DIR__"room43",
     ])); 
  set("light",1);
  setup();
}
