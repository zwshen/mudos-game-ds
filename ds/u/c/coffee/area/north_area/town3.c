#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG 
正當你無聊再這裡閒逛時，發現許多新奇的玩意，旁邊的屋
子、建築都十分特別，有些房屋看起來很新，但有些看起來卻十
分破舊，連用木頭做的牆壁都被蟲蛀光了。旁邊也許多附近的小
孩子在這裡玩耍。
LONG
    );

 set("exits",(["north":__DIR__"town4",
               "south":__DIR__"town2",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
