inherit ROOM;

void create()
{
  set("short", "�䳣�j�D");
  set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL��
�۰Ӯa�B�����A���W�i�H�ݨ�ΧΦ�⪺�H���ʡC 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room25",
      "south" : __DIR__"room29",
      "north" : __DIR__"room23",
      "east" : __DIR__"room27",
     ])); 
  set("light",1);
  setup();
}
