inherit ROOM;

void create()
{
  set("short", "�ڨ����s�a");
  set("long", @LONG
�o���s�a���\��ۤ@�ǴӪ��A�����W���ٵ��۪G�l�A�o�a�s�a��
�D�H�O�n�v�Ӫ��ȫȡA�s�a�����ѯS�C���n�v���G�s�A����W�S����
���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room23",
      "south" : __DIR__"room27",
      "northwest" : __DIR__"room20",
     ]));  
  set("objects",([
      __DIR__"npc/room24-boss":1,
     ]));
  set("light",1);
  setup();
}
