inherit NPC;

void create()
{
        set_name("香客",({"pilgrim man","man"}) );
        set("long",@LONG
一個慕「寒澈道」之名而來的香客，他正在廂房裡整理隨身的行李，
似乎要在這住上好一段日子呢。
LONG
);
        set("age",25);
        set("race","人類");
        set("level",2);
        set("attitude", "peaceful");
        set("gender", "男性" );
        setup();
        receive_money(100);
}

