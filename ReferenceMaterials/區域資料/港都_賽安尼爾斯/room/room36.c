inherit ROOM;

void create()
{
  set("short", "海軍分部－集合場");
  set("long", @LONG
這裡是海軍的集合場，海軍的整隊、操練和檢閱都在這邊進行，
場上有些海軍正在進行訓練。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"room33",
     ])); 
  set("light",1);
  setup();
}
