#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIC"靈劍"HIW"王"NOR, ({ "shura-sword king","king" }) );
        set("long","靈界的領導者。\n");
        set("level",50);
        set("age",300);

        set("combat_exp", 16047);  
      //set("max_hp",25000);        set("chat_chance_combat",10);
        set("chat_msg_combat",({ 
            (:command("wield sword"):),
            "靈劍王說道:練精化氣 練氣化神 ....\n",
          }) );  
          set("title","劍靈界聖王");
          set("nickname",HIC"劍靈"NOR);                set_skill("combat", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100 );
        setup();
        carry_object("/u/t/tako/power=sword")->wield();
        }

