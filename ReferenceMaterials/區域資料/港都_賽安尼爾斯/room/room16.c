inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A�ѪŤ����ɦ����ýL�ۡC
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room7",
      "southwest" : __DIR__"room17",
      "northeast" : __DIR__"room15",
     ]));
  set("outdoors","land");
  setup();
}
