inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG   
�o�̬O��f��������A�}���U�O�Υ۶��Q�����D���A����񦳳\
�h�j���ۥΨө�׮������Iŧ�A���ۤW���X���p���ɪ��Ӫ��h�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room21",
      "west" : __DIR__"room2",
      "northwest" : __DIR__"room9",
      "southeast" : __DIR__"room11",
     ]));
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/crab":2,
     ]));
  setup();
}
