inherit ROOM;

void create()
{
  set("short", "�H�ۤl��");
  set("long", @LONG
�o�̬O�䳣�ɦw�������~���D���A���W�Q���۸H�ۤl�A��������
��������A����}���a�q���_�����X�A�ݨӳo�����ܤ֤H���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room41",
      "southeast" : __DIR__"room46",
     ])); 
  set("light",1);
  setup();
}
