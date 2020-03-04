inherit ROOM;
void create()
{
  set ("short", "舊磐龍遺址");
  set ("long", @LONG
從黃沙鎮下來，一路風塵僕僕，向遠眺望而去。懸崖峭壁，伴隨
的是黃沙滾滾；滔滔江水，伴隨的是悠悠天地，中原江湖幾多血淚，
豪壯之情，充塞於臆間！
LONG
);

  set("exits", ([
  "west" : __DIR__"room41",
  "eastup" : __DIR__"room39",
]));
  set("objects",([
  __DIR__"npc/npc24" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
