#include <room.h>
inherit ROOM;
void create()
{
 set("short","死路");
 set("long",@LONG
這個死巷中不知道又暗藏了什麼玄機, 你決定要好好搜查一
下, 才不會遺漏什麼重要的物品....
LONG
    );
 set("exits",([ "east":__DIR__"secret2_10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
