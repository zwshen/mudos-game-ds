inherit ROOM;
void create()
{
  set ("short", "亂石崗");
  set ("long", @LONG
你在沙漠中亂走，結果赫然發現前方不遠處有座小山，好奇心驅
使你前往一探究竟。
LONG
);

  set("exits", ([
  "west" : __DIR__"room29",
  "eastup" : __DIR__"room31",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
