inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG   
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A�������ɦa�祴����E�_�}�}����C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room1",
      "northwest" : __DIR__"room8",
      "southeast" : __DIR__"room10",
     ]));
  set("outdoors","land");
  setup();
}
