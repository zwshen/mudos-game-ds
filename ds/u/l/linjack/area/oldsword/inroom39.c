#include <room.h>
inherit ROOM;
void create()
{
 set("short","左側平臺");
 set("long",@LONG
這個平臺才是比較接近整個向雲堂的正中央, 你往左下側
看過去, 會發現茶樓外面的一片綠油油的屋頂花園! 雖然這蠻
難以置信的, 不過事實卻擺在你眼前. 這邊有一兩個守位在輪
流看守.
LONG
    );
 set("exits",(["east":__DIR__"inroom37",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
