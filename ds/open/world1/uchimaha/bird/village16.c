#include <room.h>
inherit ROOM;
void create()
{
 set("short","���A�a");
 set("long",@LONG
�A��F�@�ɤp���, �o�̳��C�ۦU���U�˪����ǡA
�o�ǥ��N�_�Ӫ�Ĳ�P�D�`�n, ���O�@��´��������Ұ�
���@�~, �A�ݨ쪺���O�֤k����Ϋ~, �ҥH�o���O�֤k
���ж�.
LONG
    );
 
 set("exits",(["east":__DIR__"village15",
              ]));
 set("objects",([__DIR__"npc/chiu" : 1,
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        