#include <room.h>
inherit ROOM;
void create()
{
 set("short","大墳墓");
 set("long",@LONG
你一走過來, 差點嚇了一跳, 原來是一個兩旁有刻石雕的大型
墳墓. 雖然這邊陰氣滿重的, 不過你仔細體會, 發現陰氣之中隱隱
透出一股高潔的氣息, 看來墓中所埋之人, 生前必定不是泛泛之輩.
LONG
    );
 set("exits",([ "southwest":__DIR__"mountroad1_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}