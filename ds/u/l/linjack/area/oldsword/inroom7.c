#include <room.h>
inherit ROOM;
void create()
{
 set("short","前廳");
 set("long",@LONG
這邊就是向雲堂的前廳了, 你看到附近有一些特別的擺飾品,
看起來不會過份奢華, 不過讓人感覺很舒適. 你可以看到右邊有
個通道通往貴賓的專用客房, 通常都只給有一定地位的人去裡邊
休息. 向雲堂主的長子正在這裡忙著處理一些事務, 不過旁邊的
僕人正微笑的望著你, 看起來很樂意幫你一些忙. 左邊還有一條
通道, 右側也有一條通道.
LONG
    );
 set("exits",([ "north":__DIR__"inroom4",
                 "east":__DIR__"inroom17",
                "south":__DIR__"inroom18",
                 "west":__DIR__"inroom40",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
