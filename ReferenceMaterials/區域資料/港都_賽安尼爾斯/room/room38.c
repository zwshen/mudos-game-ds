inherit ROOM;

void create()
{
  set("short", "�A��x");
  set("long", @LONG
�o�̦��@�y���Y�[�������x�A�O���x�ΨӺʬݮ����Ϊ��A�x�W��
���T�ϡA���Ƶo�ͪ��ɭԯਲ਼�t���q�������A�x�U���X�W���x�b���^
�C 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room15",
      "east" : __DIR__"room39",
     ])); 
  set("light",1);
  setup();
}

