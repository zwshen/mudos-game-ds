#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("鐵匠", ({ "smith" }) );
        set("gender", "男性" );
        set("level",1);
        set("age", 22); 
        set("title",HIY"暇日谷"NOR);        set("long", 
            "暇日谷內武器舖的老闆,聽說舖內的武器都是上等貨，\n"            "一定要購買(buy)了才知道!!\n"                        );
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
             "鐵匠說:來喔!!我們賣的武器是夢幻七域裡最便宜的喔!!\n",
                       }));
        set("sell_list",([      
                 __DIR__"wp/watersword"  : 30, 
                 __DIR__"wp/fireblade"   : 30, 
                 __DIR__"wp/woodaxe"     : 30, 
                 __DIR__"wp/goldwhip"    : 30,         
                 __DIR__"wp/tofist"      : 30,     
                 __DIR__"wp/bigcape"     : 30,  

        ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

