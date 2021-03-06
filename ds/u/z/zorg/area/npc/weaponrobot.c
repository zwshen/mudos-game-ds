inherit NPC;
#include <ansi.h>
inherit SELLMAN;

void create()
{
        set_name(WHT "武器機械人"NOR, ({ "weapon robot","robot" }) );
        set("level",10);
        set("race","機器人");   
        set("age", 22);
        set("long",
                "一個正在忙碌地工作著的機械人。\n"
                "如果你想買一些武器﹐可以用 list 看有哪些東西﹐用 buy 向機械人購買。\n"
        );
        set("combat_exp", 50);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                "機械人正在點算武器。\n",
                "機械人說道: 朋友多買一點，我給你一個折扣。\n",
                "機械人慘叫一聲﹕天呀！點解有那麼多客人呢？\n",
                "機械人洋洋得意地說道﹕我這間店是全城最好的。\n",
        }));
        set("sell_list",([      
                 "/u/m/mulder/area/npc/wp/lasersword"        : 15, 
                 "/u/m/mulder/area/npc/wp/longsword"   : 23, 
                 "/u/m/mulder/area/npc/wp/shortaxe"     : 20, 
                     ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}




