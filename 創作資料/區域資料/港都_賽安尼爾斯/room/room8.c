inherit ROOM;

void create()
{
  set("short", "北角燈塔");
  set("long", @LONG   
佇立在港口北方的燈塔，用石塊堆砌而成，高約十幾碼，夜晚或
天候不佳時會燃燒火堆做為船隻入港的指引，有些釣客喜歡在這個地
方釣魚。 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "southeast" : __DIR__"room9",
     ]));
  set("outdoors","land");
  setup();
}
