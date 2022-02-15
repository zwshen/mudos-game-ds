inherit ROOM;

void create()
{
  set("short", "四號碼頭");
  set("long", @LONG 
這裡是賽安尼爾斯的四號碼頭，整個碼頭用岩石與木頭搭建而成
，四號碼頭是最大的碼頭可以同時停泊六艘大船，同時碼頭的構築也
特別堅固，可以承受砲擊而不會有大損傷，王國的使節船、海軍戰船
都在這個碼頭靠岸。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room12",
     ]));
  set("outdoors","land");
  setup();
}

