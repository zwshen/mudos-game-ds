inherit ROOM;
void create()
{
  set ("short", "��D");
  set ("long", @LONG
���̳W�ҷ��p�A�u���@���j��A����]���֡A��W���F�u�u�A��
�H�@���Y�D�A�������~�ӫȦb�����ʡC
LONG
);

  set("exits", ([
  "west" : __DIR__"room17",
  "east" : __DIR__"room15",
  "south" : __DIR__"room18",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}