#include <ansi.h>
inherit NPC;
void create()
{
 set_name("御遲妄",({"sky master","master"}));
 set("long","             你發現此人身上散發出一種肅殺之氣, 原來他就
             是天梟三聖之一, 御遲妄! 傳說此人內功已到傳奇的境界, 而一
             身天嘯匕法更是所向無敵, 二十二歲那年就曾經一人獨殺絕命雙
             煞, 從此創下威名, 然而在三十五歲那年因為天梟分裂而心灰意
             冷, 遠走草創天梟攻武一派"
    );
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","男性");
 set("level",35);
 set("title",HIR"天梟三聖"NOR);
 set_skill("unarmed",55);
 set_skill("blade",65);
 set_skill("force",85);
 set_skill("parry",70);
 set_skill("sky-dagger",100);
 map_skill("dagger","sky-dagger");
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say 哼! ":),
 }));
 setup();
 carry_object(__DIR__"eq/dragon_dagger")->wield();
 carry_object(__DIR__"eq/sky_cloth")->wear();
 carry_object(__DIR__"eq/sky_boots")->wear();
 carry_object(__DIR__"eq/sky_hat")->wear();
}