#include <room.h>
inherit ROOM;
void create()
{
 set("short","半山腰的平台");
 set("long",@LONG
由於整個杭山並不會很陡, 因此山路中大都有可以休息的
平台地, 有些農家在這邊耕田, 種植一些山地的蔬菜水果, 也
有些農家在這邊牧羊.
LONG
    );
 set("exits",([ "northeast":__DIR__"mountroad2_4",
                "west":__DIR__"mountroad2_6",
                "north":__DIR__"mountroad2_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}