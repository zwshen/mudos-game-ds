#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","壩子");

 set("long",@LONG
你看到這裡有一個債主正在逐家逐戶的收取債務, 但是這些
農人所得要糊口都很難, 更不用說要去還債了, 你的同情心不禁
使你想要幫助他們...
LONG
    );
 set("exits",([	"south":__DIR__"ten28",
		"west":__DIR__"ten30",
    ]));
 set("objects", ([__DIR__"npc/rich" : 1,
                  __DIR__"npc/guard":2,
		  __DIR__"npc/farmer3":1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}