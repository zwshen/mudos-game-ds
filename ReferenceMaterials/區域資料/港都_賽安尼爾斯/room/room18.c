inherit ROOM;

void create()
{
  set("short", "�}��M�s�a");
  set("long", @LONG
�o�̬O�����x���s�a�A���M���C�ܯ}�¡A���O���w�o�̪��s����
�H�٬O�|�Ө�o��ӥ��U�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "southeast" : __DIR__"room22",
      "east" : __DIR__"room19",
     ])); 
  set("objects",([
      __DIR__"npc/room18-boss":1,
     ]));
  set("light",1);
  setup();
}
