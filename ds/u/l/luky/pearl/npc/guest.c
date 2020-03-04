//sightseer.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("客人",({"guest"}));
set("level",30);
set("age",28);
set("long","你看到一位正在專心吃飯的女客人。\n");
set("gender", "女性");
set("combat_exp",20000+random(3000));
set("coin",600+random(200));
set("chat_chance",2);
set("chat_msg",({
  (:command,"hmm":),
  (:command,"say 嚼嚼..嗯...真好吃..":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
setup();
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n客人大叫: 「 搶飯啊∼﹗不會自己買啊﹗」\n"NOR,
HIW"\n客人想逃可是被攔住了...跑不掉\n"NOR,
     }) );
carry_object(__DIR__"wp/fork")->wield();
}
