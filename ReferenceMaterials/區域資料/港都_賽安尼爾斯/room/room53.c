inherit ROOM;

void create()
{
  set("short", "�D��");
  set("long", @LONG
�o�̬O�䳣�~���D���A�A���訫�N�i��䳣�F�A�A�ݨ���W���_
�a���ӤH�B�����i�X�䳣�A�b�o��A�N�i�Hť�쥫���n�x���n���F�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room54",
      "southwest" : __DIR__"room28",
     ])); 
  set("light",1);
  setup();
}

