inherit ROOM;
void create()
{
  set ("short", "山洞");
  set ("long", @LONG
經過曲曲折折的窄路，來到了一個山洞，山洞並不甚寬廣，僅能
容納二三人並行，洞旁雜草叢生，長成如人一般高大，看來這裡己久
絕人跡。
LONG
);

  set("exits", ([
  "north" : __DIR__"room46",
  "southeast" : __DIR__"room48",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
