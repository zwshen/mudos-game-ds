inherit NPC;

void create()
{
        set_name("第十四代弟子",({"trainee"}) );
        set("long",@long
這是一個萬斧莊的年青弟子，看起來就是一副少經江湖經驗的樣子。
long
);
        set("age",20);
        set("race","人類");
        set("level",5);
        set("attitude", "peaceful");
        set("title","萬斧莊");
        set("gender", "男性" );
        set_skill("axe",20);
        setup();
        carry_object(__DIR__"eq/cloth")->wear();
          carry_object(__DIR__"wp/axe")->wield();
}

