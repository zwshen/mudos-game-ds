inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A���_�����ۤ@�Ǥp���W�i�a«�k�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"room14",
      "north" : __DIR__"room12",
      "east" : __DIR__"room32",
     ]));
  set("outdoors","land");
  setup();
}
