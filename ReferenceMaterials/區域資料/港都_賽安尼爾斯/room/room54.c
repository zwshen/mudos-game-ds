inherit ROOM;

void create()
{
  set("short", "�D��");
  set("long", @LONG 
�o���D���������Υ۪O�Q���A�i�H�e�Ǩ�x�����æ�A���W����
���Ӹ붤���滰���A�����٦��_�Ǫ��H�e���䤤�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room55",
      "southwest" : __DIR__"room53",
     ])); 
  set("light",1);
  setup();
}
