// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("天燈娃娃",({"wish_lamp doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
天燈又稱為孔明燈，相傳為三國諸葛亮的發明，也被公認為熱氣球的始祖
，起初是為了傳遞訊息之用，但目前通常則被當成節慶祈福許願(wish)的工具。
而這個是一個提著天燈的洋娃娃，非常的喜氣洋洋。
LONG
                );
                set("undead_msg",HIY"\n\t就在千鈞一髮之際，$N身上的$n突然冒出刺眼的光芒，抵消住了這致命一擊!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }


