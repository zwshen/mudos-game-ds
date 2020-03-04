inherit ROOM;
void create()
{
  set("short", "草原小路");
  set("long", @LONG
從孟村田地旁的小路走來，四週的雜草漸多，這裡是一條蜿
蜒小徑，沿途無甚特別的景色。腳底下的碎石子被你踩得喀喀直
響，從此向北極目望去，這條小路的彼端似乎是個草原。
LONG
);
  set("exits", ([
  "enter" : __DIR__"room2",
  "south" : "/open/world1/tmr/area/ms2",
]));
  set("no_clean_up", 0);
  set("outdoors","land");
  set("objects",([
"/open/world1/tmr/area/npc/dog" : 1,
]) );
  setup();
  replace_program(ROOM);
}
