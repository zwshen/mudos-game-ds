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
      "southeast" : __DIR__"room12",
      "west" : __DIR__"room3",
      "northwest" : __DIR__"room10",
      "east" : __DIR__"room25",
     ]));
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/sea-cockroach":3,
     ]));
  setup();
}
