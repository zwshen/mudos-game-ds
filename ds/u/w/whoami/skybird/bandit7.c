#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","���D");
 set("long",@LONG
�@�����Ӽe�]���ܯ������Y�M���k���䯸���F�t�d�u�ê��H
�M�ӭӳ������a���ۧA�@�M�@�ƭn�N�A�Y�U���ˤl�M�O�H���ѱo
�߸�ı�o��򪺡M��������.
LONG);
 set("exits",([ 
                "west":__DIR__"bandit6", 
                "southeast":__DIR__"bandit8",
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}
