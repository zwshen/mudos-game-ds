inherit ROOM;

void create()
{
  set("short", "�C�l�߰s�a");
  set("long", @LONG
�o�Ӱs�a���F��s���~�A�٦���@�ǥ~�a�����ơA�O�q�U�a�Ө�
�䳣���ȫȱa�Ӫ��A�ҥH�����|���Ǥk�H�B�p�Ĩ�o�̫~���s�_����
�ơC
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room18",
      "southeast" : __DIR__"room23",
      "east" : __DIR__"room20",
     ]));  
  set("objects",([
      __DIR__"npc/room19-boss":1,
     ]));
  set("light",1);
  setup();
}
