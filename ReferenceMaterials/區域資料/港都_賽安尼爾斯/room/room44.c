inherit ROOM;

void create()
{
  set("short", "�ө���и��D����");
  set("long", @LONG
�o�̬O�@�B���x���³f�����A�a�W�\���F�\�h�G��f�~�A�p�G��
�ݭn�]�i�H�ܽ�A���W�����~�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room43",
      "northeast" : __DIR__"room41",
     ])); 
  set("light",1);
  setup();
}
