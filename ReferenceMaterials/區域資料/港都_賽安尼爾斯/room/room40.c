inherit ROOM;

void create()
{
  set("short", "�ө���Ш��㩱");
  set("long", @LONG
�o�̬O�䳣�ө��󤤪��Z�����A�����f�W�豾�ۤ@����ޡA����
�\�ۦU�����ҡB����A�Y�w�������A����·�áA²���i�H��@�ժ��]
�F�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room39",
      "southwest" : __DIR__"room43",
      "east" : __DIR__"room41",
     ])); 
  set("light",1);
  setup();
}
