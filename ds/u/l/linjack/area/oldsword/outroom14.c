#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹叢中");
 set("long",@LONG
這邊不知道暗藏什麼玄機, 你覺得渾身不對勁.
仔細一看... 哇!!眼前站了兩隻不知道是什麼東西,
因為太黑了! 你覺得你可能離死期不遠了. 你驚慌
之間, 仍注意到似乎有塊大石頭立在旁邊. 
LONG
    );
 set("exits",(["south":__DIR__"outroom13",
               "north":__DIR__"outroom15",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}