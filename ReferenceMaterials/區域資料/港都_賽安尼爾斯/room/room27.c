inherit ROOM;

void create()
{
  set("short", "���]");
  set("long", @LONG
�o�̬O�@�����ت����]�A���M���O�ܤj���O���C�B�]�Ƴ��ܤ���
�A�p�G�Aı�o�֤F�i�H�q�өХ𮧤@�U�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room26",
      "north" : __DIR__"room24",
      "east" : __DIR__"room28",
     ])); 
  set("light",1);
  setup();
}
