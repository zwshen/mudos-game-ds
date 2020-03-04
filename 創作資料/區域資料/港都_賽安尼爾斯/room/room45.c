inherit ROOM;

void create()
{
  set("short", "碎石子路");
  set("long", @LONG
這裡是港都賽安尼爾斯外的道路，路上鋪滿著碎石子，隱隱有車
輪的痕跡，雜草稀疏地從石縫中長出，看來這條路很少人走。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room41",
      "southeast" : __DIR__"room46",
     ])); 
  set("light",1);
  setup();
}
