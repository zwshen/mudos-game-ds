inherit ROOM;

void create()
{
  set("short", "���x�����ж��X��");
  set("long", @LONG
�o�̬O���x�����X���A���x���㶤�B�޽m�M�˾\���b�o��i��A
���W���Ǯ��x���b�i��V�m�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"room33",
     ])); 
  set("light",1);
  setup();
}
