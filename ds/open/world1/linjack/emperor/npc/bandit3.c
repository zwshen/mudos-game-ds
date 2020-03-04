inherit NPC;
void create()
{
        set_name("彪形大漢",({ "big bandit","bandit" }));
        set("long",
                "這傢伙看起來一副凶神惡煞的樣子, 一看就知道不是好貨,\n"
                "而且高過你數個頭的高度, 對你來說壓迫感很大, 快閃吧..!\n"
        );
        set("age",35+random(6));
	set("attitude", "killer");
        set("level",26+random(4));
	set("battlepoint",2);
        set("guild_gifts",({ 8,6,2,4 }));
	set("evil",5+random(6));
        set("chat_chance",5);
        set("chat_msg",({
  "彪形大漢正在盯著你看。\n",
  "彪形大漢說: 嗯! 來了個找死的了!\n",
  "彪形大漢似乎正在做守衛的工作。\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "彪形大漢說: 兄弟們! 上!\n",
  (: command("say 納命來 ~~~ ! \n") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/cutless")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
}
