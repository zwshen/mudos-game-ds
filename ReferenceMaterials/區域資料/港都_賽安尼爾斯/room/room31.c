inherit ROOM;

void create()
{
  set("short", "���x�����з|ĳ��");
  set("long", @LONG
�o�̬O���x�F���}�|�Ϊ��|ĳ�ǡA��ꪺ������\�ۤC�i�Ȥl�A
�e�豾�۶ªO�٦��X�T���ϡA�z�L����ݹL�h�i�H�ݨ춰�X���C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"room34",
     ])); 
  set("light",1);
  setup();
}
