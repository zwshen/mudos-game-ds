#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 你可以看到
有許多園丁正和細心的照顧花草, 有些園丁對於你的到來有
些訝異. 這邊種了一些花花綠綠的植物, 沒有幾種是你認識
的, 仔細看一看地上長了一些不知名的藥草.
LONG
    );
 set("exits",(["north":__DIR__"inroom8",
                "east":__DIR__"garden6",
                "west":__DIR__"garden7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
