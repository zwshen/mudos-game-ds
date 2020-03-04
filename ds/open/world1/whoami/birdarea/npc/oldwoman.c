#include <ansi.h>

inherit NPC;
void create()
{
        set_name("老婆婆",({ "old woman","woman" }) );
        set("long","一個居住在獵狐村的老婆婆，看她手上也有著被狐狸咬傷的痕跡\n"
                   "，你便了解這獵狐村的名號果然不是白來的•\n");
        set("gender","女性");
        set("race","human");
        set("title",HIR"獵狐村"NOR);
        set("age",50+random(30));
        set("level",35);
        set("attitude","friendly");
        set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                                (:command,"say 我可是老當益壯呢！想試試看嗎？":),
        }));
        set("chat_chance",20);
        set("chat_msg", ({
                          (:command("yawn") :),
                          (:command("zzz"):),
        }));

      
   setup();
   add_money("coin",400 + random(400));           
}

