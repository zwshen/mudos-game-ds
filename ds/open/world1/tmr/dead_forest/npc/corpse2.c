#include <npc.h>
inherit F_BANDIT;

void create()
{
          set_name("血屍", ({ "blood corpse" , "corpse","blood" }) );
        set("long",@long
    這是一具已經腐爛見骨的屍體，但卻還是能緩步行走，一雙空洞的眼眶
不時地淌出血來，讓人覺得非常的噁心恐怖。
long
);
        set_race("human");
        set("attitude", "aggressive");
        set("age", 500 );
        set_stat_maximum("gin", 200);
        set_stat_maximum("hp", 200);
        set_attr("str",20);
        set_attr("cps",20);
		set_skill("sword",30);
		set_skill("blade",30);
		set_skill("axe",30);
		set_skill("pike",30);
        set_skill("parry",40);
        set_skill("dodge",40);
        set("title","死亡之森");
        setup();
        set_level(5);
        do_heal();
        switch(random(4) ) {
        	case 0: // 特殊斧
		        carry_object(__DIR__"obj/shortaxe")->wield();
			    break;
        	case 1: // 特殊槍
		        carry_object(__DIR__"obj/shortpike")->wield();
			    break;
        	case 2: // 特殊刀
		        carry_object(__DIR__"obj/shortknife")->wield();
			    break;
        	default: //  特殊劍
		        carry_object(__DIR__"obj/shortsword")->wield(); 
        }
}


