#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到東北澤林的泥沼區, 這裡有些你從未見過的
植物, 還有一些你從未見過的昆蟲, 你心想這是什麼奇
怪的森林.

LONG
    );
 
 set("exits",(["north":__DIR__"en59",
               "south":__DIR__"en69",
               ]));
 set("objects",([__DIR__"npc/fly" : 4,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
