#include <room.h>
inherit ROOM;
void create()
{
 set("short","右偏廳");
 set("long",@LONG
你通過了一個走道來到了右偏廳, 右偏廳的窗簾被徐徐微風吹動,
由於這邊地勢較平地來的高, 視野又廣, 是十分適合看日出的風景點.
這邊的內部擺設沒有正廳那麼毫華, 但是卻也給人清雅高尚的感覺,
如果你想要進一步的到外面吹吹風看看風景, 外面還有一條小走廊,
而你的上面有個塔不知道是作什麼用的, 但是有個高高的樓梯可以上去.
LONG
    );
 set("exits",([ "east":__DIR__"inroom9",
                "west":__DIR__"inroom66",
                  "up":__DIR__"inroom10",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
