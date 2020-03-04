#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路上");
 set("long",@LONG
這整條路的行進方向是往偏西南而去, 但是路上人群稀少,
偶爾能看到幾個旅人經過已屬稀奇了. 附近有幾家商店都因為
太少人光顧而紛紛倒閉了. 不過這幾家店的建築物都還算新,
可見這邊是最近才開始發展的.
LONG
    );
 set("exits",([ "northeast":__DIR__"road1",
                "west":__DIR__"road3",]));
 set("objects",([ __DIR__"npc/p_vendor" : 1 ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}
