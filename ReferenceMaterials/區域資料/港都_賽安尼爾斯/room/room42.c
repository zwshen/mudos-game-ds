inherit ROOM;

void create()
{
  set("short", "�ө���ФG��ө�");
  set("long", @LONG
�o�̬O���G��ө��A�M���R���³f�A�Q�R�K�y�f�άO���W�����n
���˳Ƴ��i�H�b�o�Ӧa�����C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room39",
      "east" : __DIR__"room43",
     ])); 
  set("light",1);
  setup();
}
