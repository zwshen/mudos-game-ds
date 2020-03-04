#include <room.h>
inherit ROOM;
void create()
{
 set("short","大少堂主寢室");
 set("long",@LONG
這裡正是向雲堂大少堂主的寢室. 你不禁覺得一陣訝異,
堂主連自己的兒子也撇到這麼遠的地方. 大少堂主一直在前
廳那邊忙碌著堂中大小事情, 所以這房間現在是空蕩蕩的.
LONG
    );
 set("exits",([ "north":__DIR__"inroom40",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
