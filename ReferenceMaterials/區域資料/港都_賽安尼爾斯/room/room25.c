inherit ROOM;

void create()
{
  set("short", "宿屋");
  set("long", @LONG
這裡是一間蠻大的宿屋，往來港都的旅客少不了要到這邊來寄宿
一晚，從外面觀看就知道有不少客房住滿，看來生意不錯。 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room11",
      "north" : __DIR__"room22",
      "east" : __DIR__"room26",
     ])); 
  set("light",1);
  setup();
}
