inherit ROOM;

void create()
{
  set("short", "�H�ۤl��");
  set("long", @LONG
�o�@�q���W���Ǫd�ڡA�[�W�����л\���_�өǤ��ΪA���A���Ǥ@
�ʬ\��ɭ˦���j�b�������C 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northwest" : __DIR__"room50",
      "east" : __DIR__"room52",
     ])); 
  set("light",1);
  setup();
}
