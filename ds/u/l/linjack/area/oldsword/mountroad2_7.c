#include <room.h>
inherit ROOM;
void create()
{
 set("short","半山腰的平台");
 set("long",@LONG
由於整個杭山並不會很陡, 因此山路中大都有可以休息的
平台地, 有些農家在這邊耕田. 你眼前就有一塊小小的梨樹園,
裡邊有三兩個農夫在耕作.
LONG
    );
 set("exits",([ "south":__DIR__"mountroad2_5",
                "west":__DIR__"mountroad2_8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}