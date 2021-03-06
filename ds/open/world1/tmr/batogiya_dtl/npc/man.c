#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("趕路人", ({ "man" }) );
    set_race("human");
    set("age", 6);
    set("long", "一位滿頭大汗，不知道要趕去哪的路人。\n");
    setup();
    set_level(2);

    switch( random(5) ) {
       case 0: carry_object(__DIR__"obj/cloth")->wear(); break;
       case 1: carry_object(__DIR__"obj/armor")->wear(); break;
       case 2: carry_object(__DIR__"obj/belt")->wear(); break;
       case 3: carry_object(__DIR__"obj/boots")->wear(); break;
       case 4: carry_object(__DIR__"obj/gloves")->wear(); break;
    }
 
    switch( random(5) ) {
        case 0: carry_money("coin", 500); break;
        case 1: carry_money("coin",1000); break;
        case 2: carry_money("coin",1500); break;
        case 3: carry_money("coin",2000); break;
        case 4: carry_money("coin",2500); break;
    }
       carry_object("/d/obj/sword")->wield();
}

int accept_fight(object ob)
{
    do_chat("趕路人說道：「我正在趕路，你找別人吧。」\n");
      return 0;
}

