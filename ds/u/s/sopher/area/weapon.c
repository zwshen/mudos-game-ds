#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIR"武器"HIW"控制室閘門前"NOR);
        set ("long", @LONG
東邊就是這作管理處警衛取裝備的地方了，看來除了
森嚴的警備外，警鈴設備也相當周全。
LONG);  
        set("exits", ([
        "west" : __DIR__"time4",
         ]) );
        set("hide_exits",([
        "east" :__DIR__"weapon1",
        ]));
        set("objects", ([
        __DIR__"npc/admin" : 1,
        ]) );
        set("light",1);
        setup();
        replace_program(ROOM);
}
