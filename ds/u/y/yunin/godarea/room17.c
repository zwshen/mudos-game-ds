#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"�F�[��"NOR);
        set("long", @LONG
�A�i�h���Y���F�䨺�ж��A�\�]����A�и̤����F�賣�ܴ��q�A
�Q���o�����ӥu�O���q�~�a�Ӫ��X�ȩҥ�͡B�߮Ѫ��a��a�C
LONG
 );       
        
  set("exits", ([ /* sizeof() == 1 */
  "west"  : __DIR__"room15",
  
]));  
        set("no_clean_up", 0);
        setup();
}     
