//u/c/chiaa/world2/blackly_forest/road8.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "森林外處");
        set("long",@LONG
你走進了這塊森林之中的小區域,感覺到空氣的新鮮,
樹上有一些蛇類纏繞,似乎還有眼鏡蛇的樣子,
在你的腳下有一株株寄生在樹幹上的香菇,
不過看起來鮮豔,或許帶有劇毒也說不一定!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "west"  : __DIR__"trail2",     //幽徑2
  ]));
       
            setup();
replace_program(ROOM);
}


