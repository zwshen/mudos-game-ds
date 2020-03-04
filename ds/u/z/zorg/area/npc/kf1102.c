#include <ansi.h>
inherit NPC; 
inherit SELLMAN;
void create()
{
        set_name( "ＫＦ-１１０２", ({ "KF1102","kf1102"}));
        set("long", "她是新製造的機器人,具有相當高的AI,也就是我們所為的Artificial Intelligence-人工智慧。\n她可以說是最具有聲望，最具好評，最具有美女幾大特徵的一位！！！\n");
        set("level",6);
        set("gender", "女性");
        set("race", "機器人");
        set("age", 15);
        set("combat_exp",400);      
        set("evil",-20);     
        set("attitude", "friendly");  
        set("chat_chance", 1 ); 
        set("chat_msg", ({       
        (:command("smile"):), 
        "ＫＦ１１０２說道﹕要我打個折嗎！！！\n",   
        "ＫＦ１１０２說道﹕客人買點東西吧！！！\n",   
        "ＫＦ１１０２說道﹕這年頭不買點防具的是很難在社會上立足的。\n",
        }) ); 
        set("sell_list",([      
                 "/u/m/mulder/area/npc/eq/boots"       : 20,     
                 "/u/m/mulder/area/npc/eq/armor"       : 20,     
                     ]) );
        setup();
}
 void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}






