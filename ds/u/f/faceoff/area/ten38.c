#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");

 set("long",@LONG
你發現一路上的行人原來都是要前往天梟一派膜拜的膜
拜者, 天梟在十萬大山有相當多的信徒, 因此, 天梟的膜拜
者相當的多.
LONG
    );
 set("exits",([	"north":__DIR__"ten39",
		"south":__DIR__"ten37",
    ]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}