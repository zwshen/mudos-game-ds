#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中茅廬");
set("long",@LONG
你來到茅廬中的其中一間房間，這裡看來佈置的比較像是
男人的房間，牆上有著刀劍以及獵弓等武器，房間主人該是頗
為好武，可是卻好像許久未曾有人動過，上面都有一些蒙塵了
，可能外出許久。
LONG
    );
 set("exits",([
"west":__DIR__"yu_home",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             




