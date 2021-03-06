inherit NPC;
inherit SELLMAN;

void create()
{
        set_name( "鐵匠學徒", ({ "trainer" }) );
        set("gender", "男性" );
        set("level",10);
        set("age", 22);
        set("long",
                "一個正在努力學習的鐵匠學徒。\n"
                "如果你想買一些鐵器﹐可以用 list 看有哪些東西﹐用 buy 購買。\n"
        );
        set("combat_exp", 5000);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                "鐵匠學徒把一塊燒紅鐵片放入水中冷卻。\n",
                "鐵匠學徒用手中的鐵鎚在鐵砧上用力敲打。\n",
                "鐵匠學徒說道﹕小心點，別被痛著了。\n",
                "鐵匠學徒說道﹕呼∼∼希望能早點學到師傅的本領。\n",
        }));
set("sell_list",([      
                 __DIR__"wp/woodbow"        : 5, 
                 __DIR__"wp/small-hammer"   : 5, 
"/open/world1/tmr/area/npc/wp/shortsword"   : 5, 
"/open/world1/tmr/area/npc/wp/shortaxe"     : 5,         
"/open/world1/tmr/area/npc/wp/fork"         : 5,     
"/open/world1/kkeenn/love/npc/obj/whip1"    : 5,     
                 __DIR__"wp/small-blade"    : 5,        
                ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}





