inherit NPC;
void create()
{
        set_name("護城守衛",({ "guard" }) );
        set("long","一位保護連接磐龍城對外交通的人，沒有什麼特別的。\n");
        set("race","人類");
        set("age",35);
        set("level",30);
        set("attitude","friendly");
        set_skill("dodge",60);
        set_skill("unarmed",60);
      set_skill("parry",50);
        setup();
add_money("silver",10);           
}

