inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A�������ɦa�祴����E�_�}�}����A
�N�����q��F�@���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room6",
      "southwest" : __DIR__"room16",
      "northeast" : __DIR__"room14",
      "east" : __DIR__"room38",
     ]));
  set("outdoors","land");
  setup();
}
