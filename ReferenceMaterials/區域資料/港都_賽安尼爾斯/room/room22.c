inherit ROOM;

void create()
{
  set("short", "�j�G�l�s�a");
  set("long", @LONG
�o���s�a��b���Iż�áA�ⴲ����ȤW���׵ۤ@�ǾK�H�H���s��
�A�䥦�ȤH�h�O�ʼɦa�j�f�ܰs�A��Ӱs�a�x�����a�æ��@�ΡC
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room21",
      "south" : __DIR__"room25",
      "northwest" : __DIR__"room18",
      "east" : __DIR__"room23",
     ]));  
  set("objects",([
      __DIR__"npc/room22-boss":1,
     ]));
  set("light",1);
  setup();
}
