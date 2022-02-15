inherit ROOM;

void create()
{
  set("short", "'港都大道");
  set("long", @LONG
這裡是貫通港都的主要道路，路面相當寬闊而且平整，兩旁林立
著商家、店面，西邊的岔路可以通往海岸邊。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room12",
      "south" : __DIR__"room32",
      "north" : __DIR__"room26",
     ])); 
  set("light",1);
  setup();
}
