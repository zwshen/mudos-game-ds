// smith.c

#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("亞卡司", ({ "yakasi smith","smith" }) );
        set_race("human");
        set_attr("str", 20);
        set_attr("cor", 20);
        set_attr("cps", 15);
        set_attr("dex", 18);
        set("age",35);
        set("title","武器商");
        set("long",@long
亞卡司是一個身強體健的中年打鐵匠，他所販賣的武器品質，在這附
近可是非常有名聲的。如你有意向他購買武器，可以利用list指令查
詢可購買的種類。
long
);

        set("merchandise", ([
                __DIR__"obj/longsword": 5,
                    "/d/obj/axe": 5,
                 __DIR__"obj/bigblade": 5,
                    "/d/obj/longpike": 5,
                    __DIR__"obj/electric-stick": 2,
                      __DIR__"obj/wood-axe": 5,
                      __DIR__"obj/wood-blade": 5,
                
        ]));

        set("chat_chance", 5);
        set("chat_msg", ({
                "亞卡思用力伸了伸懶腰，說道：「每天都這麼忙，真是累壞了。」。\n",
                "亞卡思點起了一根香煙，用力深深地吸了一口。\n",
        }));
        setup();
	advance_stat("gin",200);
	advance_stat("hp",200);
     set_level(10);
	 do_heal();
     carry_object(__DIR__"obj/flysky-dagger")->wield();
}

int accept_fight()
{
        do_chat("亞卡思用鼻子哼了一聲，理也不理你...\n");
        return 0;
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

