#include <room.h>
inherit ROOM;
void create()
{
 set("short","右側平臺");
 set("long",@LONG
你從這邊往下看, 可以看到向雲堂正廳上方的屋頂花園,
往對面望去, 對面那邊還有一座天橋. 屋頂花園上面有些園
丁正在細心的照顧著這邊的花草樹木.
LONG
    );
 set("exits",(["west":__DIR__"inroom58"]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
