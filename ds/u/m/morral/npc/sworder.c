// sworder.c
    inherit NPC;

    void create()
{set_name("劍客",({"swordsman","man"}) );
set("gender", "男性");
set("age",34);
set("long", "他是一個來自東方的劍客，不知為何來，
也不知往何去•••\n");
set("level",250);
set_skill("dodge",100);
set_skill("blade",100);
set_skill("parry",100);
set_skill("block",100);
   setup();
add_money("coin",12000); 
carry_object("/u/m/morral/obj/sorblade.c")->wield();
}
