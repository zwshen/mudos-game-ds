#include <ansi.h>

inherit NPC;

void create()
{
          set_name(HIY"蚩"HIW"尤"NOR,({ "tsz joaur","joaur" }));
          set("long","滿口暴牙,尖嘴猴鰓,面貌極為恐怖\n", );
             
              set("level",60);
              set("age",1452687);
              set("combat_exp",30000);
            //set("max_hp",25000);
              set("chat_chance_combat",10);
              set("chat_msg_combat",({
              ( :command("wield blade"):),
                "蚩尤說:你最好不要讓我出去,要不然.........\n",
                "蚩尤說:你就完了....!!\n",
                }) );
              set("title","太古帝王");
              set("nickname",HIY"虎魄稱皇"NOR);
              set_skill("blade",100);
              set_skill("dodge",100);
              set_skill("combat",100);
              set_skill("parry",100);
              set_skill("unarmed",100);
              setup();
              carry_object("/u/t/tako/tiger^^blade.c")->wield();
              

}

