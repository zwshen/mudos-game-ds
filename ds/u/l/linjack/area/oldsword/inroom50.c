#include <room.h>
inherit ROOM;
void create()
{
 set("short","第二代弟子鋪");
 set("long",@LONG
這邊是向雲堂第二代弟子平時休息的地方, 房間還算寬敞,
可以容下七八個人休息. 裡面只有三名第二代弟子在這邊練功,
為了避免蚊蟲侵擾, 他們都有擺蚊香在裡面.
LONG
    );
 set("exits",(["south":__DIR__"inroom49",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
