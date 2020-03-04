#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","壩子");

 set("long",@LONG
所謂壩子就是在山脈中的平地, 所以這裡就是十萬大山中唯
一的盆地, 但是在其中農耕的農民卻都非常貧窮, 致使三天兩頭
就有人來此處討債.
LONG
    );
 set("exits",([	"southeast":__DIR__"ten26",
		"north":__DIR__"ten28",
		"west":__DIR__"ten32",
    ]));
 set("objects", ([__DIR__"npc/farmer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}