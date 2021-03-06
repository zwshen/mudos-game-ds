#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "老婆婆", ({ "old woman","woman"}));
        set("long", "一位和藹可親的老婆婆，經營著飯糰小攤子，她做的飯糰可是很好吃的喲。\n\n");
        set("level",10);
        set("title","和藹可親");
        set("gender", "女性");
        set("race", "人類");
        set("age", 60);
        set("evil",-70);           
        set("no_fight",1);
        set("attitude", "peaceful");  
        set("talk_reply","客人是外地來的吧，買些飯糰路上可以吃。");
        set("sell_list",([   
           __DIR__"eq/yaki-onigiri"  : 5, 
        ]));
        set("chat_chance", 10);  
        set("chat_msg", ({     
            "老婆婆喊道：來喲∼好吃的飯糰喲∼\n",
            "老婆婆雙手交握捏了幾次，一下子做出一個漂亮的飯糰。\n",
            "老婆婆拿起毛巾擦了擦臉上的汗。\n",
            "老婆婆朝你這邊微微一笑。\n",
           (:command("smile"):),
         }));
         setup();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
