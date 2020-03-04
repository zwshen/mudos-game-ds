#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟護木使",({"wood guard","guard"}));
 set("long",
"眼前這些高大挺拔的大個子是由天梟創教百中選一的弟子\n"
"所任他們都是經過宣誓世世代代都堅守這棵神木, 並且不\n"
"讓非天梟教的外人靠近, 但天梟的分裂使他們不再承認天\n"
"梟, 也養成了他們現在這種見人就殺的習性.....\n"
     );
 set("attitude","aggressive"); 
 set("age",31+random(5));
 set("gender","男性");
 set("level",35); 
 set("max_hp",12000+random(8000));
 set("max_mp",12000); 
 set("max_ap",12000);

 set("str",80+random(15));
 set("dex",125+random(30)); 
 set("int",85+random(5));
 set("con",85+random(5));
 set("Merits/bar",6+random(5));
 set("Merits/wit",4+random(5));

 set_temp("apply/armor",95+random(18));
 set_temp("apply/damage",85+random(22));
 set("combat_experience",1500000);

 set_skill("unarmed",100);  
 set_skill("dodge",100); 
 set_skill("parry",100); 
 set_skill("gun",100);
 set_skill("combat",100);
 set("chat_chance_combat",200);
 set("chat_msg_combat", ({
      (:command("say 哼! 天梟豈是你好欺?"):),
      (:command("shoot"):), 
      (:command("reload bolt"):),
                         }));
 setup();
 carry_object(__DIR__"eq/owl_pants")->wear();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/owl_bow")->wield();
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt"); 
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
}
 
void init()
{       
        ::init();
        command("reload bolt");
}

