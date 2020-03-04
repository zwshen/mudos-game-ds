inherit ROOM;

void create()
{
  set("short", "道路");
  set("long", @LONG 
這條道路的路面用石板鋪成，可以容納兩台馬車並行，路上不時
有商賈隊伍急急趕路，偶爾還有奇怪的人攙雜其中。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room55",
      "southwest" : __DIR__"room53",
     ])); 
  set("light",1);
  setup();
}
