#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"十萬大山-山口"NOR);

 set("long",@LONG
從這裡再往北走就是號稱天下奇峰皆據於此的十萬大山
了，你從這裡只能看到眼前層層相疊的青巒，間或點綴幾座
不同顏色的山峰,有黃，紅.... 只覺胸襟豁然一闊，無比清
爽 !
LONG
    );
 set("exits",([ "north":__DIR__"ten2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

