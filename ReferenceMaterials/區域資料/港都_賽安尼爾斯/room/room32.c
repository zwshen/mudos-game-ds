inherit ROOM;

void create()
{
  set("short", "�䳣�j�D");
  set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL��
�۰Ӯa�B�����A���ǥi�H�ݨ���x�������j���Ϋؿv�C 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room13",
      "south" : __DIR__"room35",
      "north" : __DIR__"room29",
      "east" : __DIR__"room33",
     ])); 
  set("light",1);
  setup();
}
