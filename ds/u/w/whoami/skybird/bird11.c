#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"眷園"NOR);

 set("long",@LONG
這裡是天梟弟子的家人所居住的地方, 別以為天梟弟子都是
王老五, 像江清流等人都是有家屬的, 而且天梟並沒有弟子不可
結婚的規定, 因此有家眷的弟子並不在少數, 所以殺某一個弟子
的家眷, 可是會引起公憤的......
LONG
    );
 set("exits",([ "south":__DIR__"bird10",
    ]));
set("objects", ([__DIR__"npc/woman" : 2+random(3),
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

