inherit ROOM;

void create()
{
  set("short", "六號碼頭");
  set("long", @LONG   
這裡是賽安尼爾斯的六號碼頭，整個碼頭用岩石與木頭搭建而成
，六號碼頭是往東方大陸航線的三個碼頭之一，停泊開往東方的船隻
，碼頭上豎立著大牌子，上面寫著【東方二號航線】。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room15",
     ]));
  set("outdoors","land");
  setup();
}
