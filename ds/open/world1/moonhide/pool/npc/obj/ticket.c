#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("經驗票",({"exp ticket","ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
               "經驗票，可以到對換器換取經驗值。\n");
             }
        set_weight(100);     
        set("no_give",1);
        setup();
} 

