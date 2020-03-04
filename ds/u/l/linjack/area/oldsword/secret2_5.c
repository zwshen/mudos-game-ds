#include <room.h>
inherit ROOM;
void create()
{
 set("short","入風口");
 set("long",@LONG
你站在這邊能感覺到那麼強列的風勢, 實在讓你感到一陣
錯愕. 因為你看到絲絲薄如光束的亮光從縫中透入, 可是受到
這麼強大的風吹襲之下, 石壁竟沒有被破壞, 令你感到十分好
奇.
LONG
    );
 set("exits",([ "east":__DIR__"secret1",
                "west":__DIR__":secret2_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
