#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"南走道"NOR);

 set("long",@LONG
這裡是天梟冶藥一派的南走道, 你感覺到走道的另一端似
乎傳來一陣異樣的敲擊聲, 你認為也許自己應該去看一看那敲
擊聲的由來....
LONG
    );
 set("exits",([ "north":__DIR__"pill2",
            "south":__DIR__"walk4",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);   
}        
           
