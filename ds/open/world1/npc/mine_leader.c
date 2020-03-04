inherit NPC;

void create()
{
        set_name("礦工工頭", ({ "mine leader","leader" }) );
        set("race","human");
        set("gender", "男性");
        set("level",15);
        set("age",41);
        set("evil",-10);
        set("long",@LONG
負責監工的礦工工頭，雖然年過四十，但是因為長期的勞動
工作，練就了相當好的體格，四十歲依然是一尾活龍，所有
的礦工們都很尊敬他。
LONG
);
        set("chat_chance",5); 
        set("chat_msg",({
                (:command("addoil"):),
                "工頭大聲喊道：「大家賣力幹活啊~~~」\n",
        }) );
        setup();
        add_money("coin", 100); 
}
