inherit NPC;
void create()
{
        set_name("小孩",({ "child" }) );
        set("long","一個居住在獵狐村的小孩，看來並無什麼過人之處。\n");
        set("race","人類");
        set("title","獵狐村");
        set("age",5);
        set("level",2);
        set("attitude","friendly");
        set_skill("dodge",2);
        set_skill("unarmed",2);
        set_skill("parry",2);
      
   setup();
add_money("silver",2);           
}

