inherit ROOM;

void create()
{
  set("short", "�H�ۤl��");
  set("long", @LONG
�o�q�������ǬO�L�����g�C�A�g�C�W���@�ǧ|�}�A�i�঳�����
���~��a�A�����W�����ۤg�C�W�u�U�Ӫ��H�g���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northwest" : __DIR__"room48",
      "south" : __DIR__"room50",
     ])); 
  set("light",1);
  setup();
}
