// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"麻油"HBK"烏骨雞"NOR,({"black-chicken soup","soup","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","碗");
                set("long",@LONG
這是一碗熱騰騰的麻油烏骨雞湯，使用烏骨雌雞做為材料，
烏骨雞為藥膳珍品，比一般肉雞或土雞的脂肪更低，優質蛋白質
更高，適合產後滋補，改善一切虛損諸病。
LONG
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n"HIG"突然衝出擋住了這致命一擊!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }

