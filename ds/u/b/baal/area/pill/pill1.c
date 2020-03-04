#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大門"NOR);

 set("long",@LONG
這裡是天梟針灸一派的大門口, 自天梟分裂後尉遲妄和邢
獨風相繼遠走, 只剩天梟針灸一派尚存於十萬大山群山之中, 
針灸一派是目前天梟分裂後尚能生存的明證, 再往東走即可
進入天梟, 往西則是十萬大山.
LONG
    );
 set("exits",([ "east":__DIR__"pill2",
                "west":__DIR__"ten42",
    ]));
// set("objects", ([__DIR__"npc/birdguard" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
