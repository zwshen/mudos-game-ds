inherit ROOM;

void create()
{
  set("short", "�ө���ЪZ����");
  set("long", @LONG
�o�̬O�䳣�ө��󤤪��Z�����A�����f�W�豾�ۨ��M�C�A����
�h�O�\���F���̮̪��M�C�Z���A�䤤�����٬O�A�����S���L���A����
���ͷN�ܦn�A���ץ����B�Z�̡B�U��U�~���|��o��ӬD��ǪZ���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room38",
      "southwest" : __DIR__"room42",
      "north" : __DIR__"room35",
      "east" : __DIR__"room40",
     ])); 
  set("light",1);
  setup();
}

