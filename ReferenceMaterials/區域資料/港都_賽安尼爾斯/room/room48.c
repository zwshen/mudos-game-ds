inherit ROOM;

void create()
{
  set("short", "�H�ۤl��");
  set("long", @LONG
����o�@�q���A�e���������X�G�֬ݤ�������A��L���j�L�N
�����i���@��_��A���樫�_�ӥi�O�ܤ���K�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "southeast" : __DIR__"room49",
      "west" : __DIR__"room47",
     ])); 
  set("light",1);
  setup();
}
