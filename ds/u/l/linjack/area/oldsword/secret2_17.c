#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
咦? 地上似乎有些積水? 不知道這水是從哪裡滲進來的,
你最好小心一點前進.
LONG
    );
 set("exits",([ "northeast":__DIR__"secret2_16",
                "south":__DIR__"secret2_18",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
