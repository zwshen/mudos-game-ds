#include <ansi2.h>

//inherit COMBINED_ITEM;
inherit ITEM;

void create()
{
    set_name(HIW"好人卡"NOR, ({ "nice guy card", "card" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit","張");
        set("value",78);
        set("base_unit", "張");
        set("base_value", 78);
        set("base_weight", 1);
        set("long", 
@LONG
 ╭──┬───────┬──╮
 │０４│  好人的宣判  │F-99│
 ├──┴───────┴──┤
 │�歈����������������������腡x
 │�� 好人!         好人!  �齰x
 │��         好人!        �齰x
 │��    好人!  ///   好人!�齰x
 │��       ___OTZ___      �齰x
 │�裺����������������������憓x
 ├─────────────┤
 │ "對不起，你真是一個好人" │
 ╰─────────────╯
LONG);
    }
    setup();

}
int query_autoload() { return 1; }
