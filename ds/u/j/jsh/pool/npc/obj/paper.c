#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("牛皮紙",({"paper"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
               HIY"一張氾黃的牛皮紙，上面寫著密密麻麻的字，上面寫 ==>\n"
               "┌────────────────────────┐\n"
               "│　　恭喜你！！　　　　　　　　　　　　　　　　　│\n"
               "│　　　　　　　因為你找到了這張紙。　　　　　　　│\n"
               "│　　　　　　　所以你可以跟魚老大挑戰。　　　　　│\n"
               "│　　　　　　　　　　　　　                      │\n"
               "│　　　遊戲設計者：　　　　　　　　　　　　　　　│\n"
               "│　　　　　　　　　魚老大　　　　　　　　　　　　│\n"
               "└────────────────────────┘\n"NOR 
);
             }
        set("value", 500);
        set_weight(100);     
        setup();
}

