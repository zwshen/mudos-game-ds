inherit ROOM;

void create()
{
  set("short", "�J��");
  set("long", @LONG
�o�̬O�@���Z�j���J�ΡA���Ӵ䳣���ȫȤ֤��F�n��o��ӱH�J
�@�ߡA�q�~���[�ݴN���D�����֫ȩЦ��A�ݨӥͷN�����C 
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room11",
      "north" : __DIR__"room22",
      "east" : __DIR__"room26",
     ])); 
  set("light",1);
  setup();
}
