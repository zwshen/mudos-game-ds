#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","交岔路口");

 set("long",@LONG
這裡是一處交岔路口, 往北會通往分裂後的天梟冶藥一派
, 往東則是他們栽培藥引和藥方的天梟植藥園, 往西則會回到
羊腸道.
LONG
    );
 set("exits",([	"north":__DIR__"ten36",
		"west":__DIR__"ten26",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}