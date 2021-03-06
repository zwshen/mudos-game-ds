#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
          set_name("酒館機械人",({"hotel robot","robot"}));
          set("long","酒館的主人自己在多年前製造的機械人，由於已經很舊了，\n"
                         "所以現在只能做一些簡單的買賣工作。\n"
          );
          set("age",50);
          set("level",1);
          set("sell_list",([
                   __DIR__"obj/water_tube"        : 3, 
                   __DIR__"obj/sandwich"        : 3, 
                 __DIR__"obj/iron_shovel"        : 5, 
                   __DIR__"obj/a_lighter"        : 5, 
        ]));
          set("chat_chance",2);
        set("chat_msg", ({
                "機械人將飲品和食物送到客人的桌上。\n",
                "機械人到處在清理桌上的垃圾。\n",
        }));
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
