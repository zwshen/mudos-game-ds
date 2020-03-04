inherit NPC;

void create()
{
        set_name("老鼠", ({"mouse"}) );
        set("long", "一隻噁心的老鼠,吱吱的在你身邊爬來爬去.\n");
        set("race", "野獸");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
        set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
        set("age", 2);
        set("level", 5);
        set("con",1);
        set("str",1);
        set("dex",10);
        set("int",1);
        setup();

}

