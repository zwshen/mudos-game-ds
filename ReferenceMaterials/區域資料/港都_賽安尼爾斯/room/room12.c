inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A���Ǧ��Ǯ������b�|�B�k«�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"room13",
      "west" : __DIR__"room4",
      "northwest" : __DIR__"room11",
      "east" : __DIR__"room29",
     ]));
  set("outdoors","land");
  setup();
}
