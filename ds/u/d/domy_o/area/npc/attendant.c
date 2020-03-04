inherit NPC;

void create()
{
        set_name("服務員",({"attendant"}) );
        set("long","一位非常有禮貌的的服務員。\n");
        set("race", "人類");
        
        set("unit","位");
        set("age",1);
        set("level",15);
        set("str",10);
         set("dex",10);
         set("attitude","heroism");
         set("chat_chance",5);
        set("chat_msg",({
        (:command("bow"):),
        (:command("smile"):),
        }) );

        setup();
        add_money("coin",30);
}
