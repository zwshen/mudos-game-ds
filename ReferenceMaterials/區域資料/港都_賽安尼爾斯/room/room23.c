inherit ROOM;

void create()
{
  set("short", "���{�s�a");
  set("long", @LONG
���i�o���s�a�|�H���O��F�Ӯc�A�������G����W���۳\�h�W�e
�A����\���J���γ����A�Ѫ�O�W���ۻ��ȫD�Z�������Q���A��b�O
���R�L��A�A�ݨ�ӳo�䪺���O�@�Ǭ�۾�����x�x�B�Q�ڵ������Z
���H���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room22",
      "south" : __DIR__"room26",
      "northwest" : __DIR__"room19",
      "east" : __DIR__"room24",
     ]));  
  set("objects",([
      __DIR__"npc/room23-boss.c":1,
     ]));
  set("light",1);
  setup();
}
