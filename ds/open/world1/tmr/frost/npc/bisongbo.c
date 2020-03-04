inherit NPC;

void create()
{
        set_name("畢松柏",({"bi songbo","songbo"}) );
        set("long",@LONG
畢松柏是倚霄派有名的大弟子，由於從小住在倚霄峰頂上，體魄比一
般人還來得強健，畢松柏長得高大俊偉，一張方字臉上有著充滿自信的雙
眼，是倚霄派近一代來赫赫有名的弟子，幾近是下任掌門的繼承人。不過
他這次遠道而來，到這和倚霄派息息相關的寒澈道觀，不知是有何要事。
LONG
);
        set("age",30);
        set("race","人類");
        set("level",30);
        set("attitude", "peaceful");
        set("title","倚霄派弟子");
        set("chat_chance",10);
        set("chat_msg",({
                "畢松柏負著手走來走去，似乎憂心忡忡....\n",
                (:command("sigh"):),
        }) );
        set("gender", "男性" );
        set("inquiry", ([
                "憂心忡忡" : "唉呀...百年大劫數已經迫在眼前了，我怎能不憂心呢。",
                "大劫數"   : "萬惡之首「天妖」於數十年被家師所敗之後，帶重傷藏匿倚霄山祕處，不知何時會再出來做孽。",
                "天妖"     : "「天妖」為由天下萬物邪惡思想所凝聚而成的妖魔，人心越惡，此妖越強，待他傷瘉復出，更是不可收拾。",
		"藏匿"     : "我們天霄派和寒澈道觀已經大派人手於這數十年間仔細找尋，希望能早一步趁他有傷之際，一舉解決此禍害。"
        ]) );

        setup();
        receive_money(500);
        carry_object(__DIR__"wp/mist-tough_whip")->wield();
        carry_object(__DIR__"eq/mist-jade")->wear();
        carry_object(__DIR__"eq/green-pants")->wear();
        carry_object(__DIR__"eq/bigloves")->wear();

}




int accept_object(object who,object ob)
{
        object powder;

        if(!ob->id("_SILK_CLOTH_") ) {
             return 0;
        }
  
        destruct(ob);
        message_vision("$N給了$n一條絲娟。\n",who, this_object() );
        command("say 這...這可不是莫小姐的絲娟嗎？");
        command("thank "+who->query("id"));
        command("say 非常謝謝你的幫忙，讓我們能稍減相思之苦，這個骨粉就送給你了吧。");
        powder=new(__DIR__"obj/powder");
        powder->move(who);
        return 1;
}


