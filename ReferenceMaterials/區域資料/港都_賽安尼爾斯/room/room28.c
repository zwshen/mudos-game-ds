inherit ROOM;

void create()
{
  set("short", "�G��j����");
  set("long", @LONG
�o�̬O�䳣�ɦw�����������G��B���׶R��j�����A�䳣�P�F��
��������������b�o�ӥ����i��A�A�ݨ쥫�����u�첳�h�A���U��
�U�˪�����B���G�B���׵��A��B�O�u�c�s���n�A�D�`�a���x�n���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room27",
      "northeast" : __DIR__"room53",
     ])); 
  set("light",1);
  setup();
}
