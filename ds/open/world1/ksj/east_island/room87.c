#include <room.h>
inherit ROOM;

void create()
{
 set("short","�˪L");
 set("long",@LONG
�A�ү����a��B��˪L�����A�@����h�|�P���O�A�񪺦ˤl�A�H
�۷L���j�L�o�X�����ڰڪ��n�T�A�Y���W���ɦ��˸��@�����@����
���U�ӡC
LONG);
   set("exits",([ 
       "east":__DIR__"room86",
       "north":__DIR__"room85",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            