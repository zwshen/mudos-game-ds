#include <npc.h>
inherit F_VILLAGER;
void create()
{
        set_name("格鬥家", ({ "fighter" }) );
        set("long",@long
一個極平凡的格鬥家，不知在那兒學到一些武術，看模樣身手倒還靈活。
long
);
        set_race("human");
        set("age", 24);
        advance_stat("gin",50);
        advance_stat("hp",50);
        set_attr("str",25);
        set("chat_chance", 5);
        set("chat_msg", ({
                "格鬥家右揮一拳、左劈一掌的練起功夫來....\n",
                "格鬥家「喝」地一聲，似乎在練什麼打氣的功夫，結果嚇到路邊的人..\n",
                "格鬥家喃喃自語道：「這套功夫再練一陣子，應該就能劈碎磚塊了吧。」\n",
        }));

        //set("title","");
        setup();
		set_level(3);
        carry_object(__DIR__"obj/fighter-cloth")->wear();
}

int accept_fight(object ob)
{
        do_chat("格鬥家擺了個架勢，說道：「還請指導一二，來吧。」\n");
        return 1;
}

