#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("¤uÀY", ({ "work king", "king" }) );
        set("long",
                "¨¾¨ãÅuªº¦ÑÁó¡A°µ¥X¨Óªº¨¾¨ã³£¦³µÛ·¥°ªªº¤ô¥­¡C\n"
                        );  
        set("nick",HIM"¨¾"NOR);        set("chat_chance",10);
        set("chat_msg",({ 
"¤uÀY®³°_¤@¥ó¥óªº¨¾¨ã¥X¨Ó«G¹³¬ ~ ~\n",
(: command,"cac" :),
(: command,"say §Ú°µªº¨¾¨ã³£¬O¤@¬yªº ~ ~" :),
}));
        set("sell_list",([
__DIR__"iron_helmet": 5, 
__DIR__"iron_mask": 5,
__DIR__"iron_neck": 5,
__DIR__"iron_armor": 5,
__DIR__"iron_surcoat": 5,
__DIR__"iron_hands": 5,
__DIR__"iron_cloth": 5,
__DIR__"iron_waist": 5,
__DIR__"iron_pants": 5,
__DIR__"iron_legging": 5,
__DIR__"iron_boots": 5,
__DIR__"iron_gloves": 5,
]));
        set("level", 20);
        set("no_fight",1);
        set("age", 42);
        set("storeroom", __DIR__"/store6.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

