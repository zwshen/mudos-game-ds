#include <ansi.h>

inherit NPC;

void create()
{
        set_name("老礦工", ({ "old worker","worker" }) );
        set("race","human");
        set("gender", "男性");
        set("level",10);
        set("age",65);
        set("evil",-10);
        set("long",@LONG
已經快要退休的老礦工，不過看他偷偷摸摸地，不知道在做
些什麼見不得人的勾當。
LONG
);
        set("chat_chance",30); 
        set("chat_msg",({
                (:command("hehe"):),
                "老礦工小聲地說：「趁現在多藏一些金礦到我的百寶袋......」\n",
                "老礦工偷偷跟你說：「黃金拿了就快走，這裡已經受到詛咒了......」\n",
                "老礦工偷偷跟你說：「這裡根本不是礦坑，下面是可怕的地方，別再下去了......」\n",
        }) );
        setup();
        carry_object(__DIR__"../obj/ts_bag");
}
