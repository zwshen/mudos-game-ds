inherit NPC;

void create()
{
        set_name("村民",({ "villager" }) );
        set("long","一個村民，看來並無什麼過人之處。\n");
        set("race","人類");
        set("age",30);
        set("level",5);
        set("attitude","friendly");

        set_skill("dodge",10);
        set_skill("unarmed",10);
        set_skill("parry",10);
        setup();
add_money("coin",500);           
}

