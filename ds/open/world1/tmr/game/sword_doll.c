#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("藤條伶娃娃",({"sword death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
  一個長的很像藤條伶(sword)的帥氣公仔，濃眉大眼，嘴角帶點
邪邪的笑，不知道迷死多少年輕姑娘。
[2006/12/06 Birthday]
LONG
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然衝出擋住了這致命一擊!!\n\n"NOR);

        setup();
}


int query_autoload() { return 1; }

