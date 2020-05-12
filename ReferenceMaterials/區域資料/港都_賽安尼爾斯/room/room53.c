inherit ROOM;

void create()
{
  set("short", "道路");
  set("long", @LONG
這裡是港都外的道路，再往西走就進到港都了，你看到路上不斷
地有商人、馬車進出港都，在這邊你就可以聽到市場吵鬧的聲音了。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room54",
      "southwest" : __DIR__"room28",
     ])); 
  set("light",1);
  setup();
}

