inherit NPC;

void create()
{
        set_name("村民",({ "villager" }) );
        set("long","愛門村的純樸村民，正在討論事情。\n");
        set("race","人類");
        set("age",28);
        set("level",4);
        set("attitude","friendly");

        set_skill("dodge",10);
        setup();
        add_money("coin",200);           
}

