inherit ROOM;

void create()
{
  set("short", "碎石子路");
  set("long", @LONG
這一段路上有些泥窪，加上雜草覆蓋走起來怪不舒服的，路旁一
棵枯樹傾倒佔住大半的路面。 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northwest" : __DIR__"room50",
      "east" : __DIR__"room52",
     ])); 
  set("light",1);
  setup();
}
