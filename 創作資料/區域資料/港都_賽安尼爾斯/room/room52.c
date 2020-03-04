inherit ROOM;

void create()
{
  set("short", "碎石子路");
  set("long", @LONG
這裡是廢墟外的道路，雖然兩旁雜草叢生蓋住部份路面，但是可
以看得出來以前是條寬廣的大路，這條路往西可以到達港都 賽安尼
爾斯。 
      [此與東南方的維南族廢墟相連，暫未完工，故不開放]
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room51",
     ])); 
  set("light",1);
  setup();
}
