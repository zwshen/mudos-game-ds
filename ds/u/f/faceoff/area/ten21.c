#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","羊腸道入口");

 set("long",@LONG
如果從這裡再往北行就會進入羊腸道之中, 傳說羊腸道中道
路相當迂迴, 就算是有相當旅行經驗的旅人, 也不敢輕易跨入這
裡, 看來你來是往南回到滅骨峰吧.
LONG
    );
 set("exits",([	"northeast":__DIR__"ten22",
		"south":__DIR__"ten20",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}