inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A�������ݥh���X������b��i�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room5",
      "southwest" : __DIR__"room15",
      "north" : __DIR__"room13",
      "east" : __DIR__"room35",
     ]));
  set("outdoors","land");
  setup();
}

