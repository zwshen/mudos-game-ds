
inherit NPC;

void create()
{
        set_name("魔炎鬥氣", ({ "magic flame","flame" }) );
        set("race","monster");
        set("gender", "無性");
        set("level",34);
        set("age",0);
        set("evil",5);
        set("long",@LONG
擁有生命力的氣體生物，僅靠著一個生命核來維持平衡，平
時都縮在一個盔甲內，只有戰鬥時才會出來攻擊。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/mf_armor")->wear();
}


