inherit ROOM;

void create()
{
  set("short", "�����s�a");
  set("long", @LONG
�o�Ӱs�a���|�P��W�˹��ƦC�ۦU�ب��ߡA�ݱo�A������·�áA
�o���s�a���D�H�O�b�䳣���j���A�ۤp�N���j�����ߪ��ݦn�A���j��
�N�}�F�o�a�s�a�A�A�|�B�ݤF�@�U�A�o�{�s�s�M�]�O�ϥΨ��߻s�@�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room19",
      "southeast" : __DIR__"room24",
     ]));  
  set("objects",([
      __DIR__"npc/room20-boss":1,
     ]));
  set("light",1);
  setup();
}
