inherit NPC;

void create()
{
        set_name("農夫",({ "farmer" }) );
        set("long","一個愁眉苦臉的農夫，似乎在煩惱什麼事情。\n");
        set("race","人類");
        set("age",36);
        set("level",5);
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
         (:command("say 真該死，麻雀一年比一年多了。"):),
         (:command("say 天氣愈熱，麻雀反而愈愛出來。"):),
         (:command("think"):),
         (:command("hmm"):),
        }) );

        set_skill("dodge",12);
        setup();
        add_money("coin",240);           
}

int talk_action()
{
command("hmm");
command("say 你很閒的話，就去幫忙抓麻雀吧。");
command("say 抓多一點，我會給你一些小小獎勵的。");
return 1;}
