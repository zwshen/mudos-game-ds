inherit ROOM;

void create()
{
  set("short", "�䳣�j�D");
  set("long", @LONG
�o�̬O�e�q�䳣���D�n�D���A�����۷�e��ӥB����A��ǪL��
�۰Ӯa�B�����A�q���䪺�D���ݹL�h�i�H�ݨ�ꬣ�������C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room14",
      "south" : __DIR__"room39",
      "north" : __DIR__"room32",
     ])); 
  set("light",1);
  setup();
}
