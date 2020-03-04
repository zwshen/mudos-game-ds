#include <ansi.h>
inherit NPC;
void create()
{
 set_name("御遲妄",({"sky master","master"}));
  set("long",@LONG
你發現此人身上散發出一種肅殺之氣, 原來他就是天梟三聖之一,
御遲妄! 傳說此人內功已到傳奇的境界, 而一身天嘯匕法更是所
向無敵, 二十二歲那年就曾經一人獨殺絕命雙煞, 從此創下威名
, 然而在三十五歲那年因為天梟分裂而心灰意冷, 遠走草創天梟
攻武一派....
LONG
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
 carry_object(__DIR__"eq/sky_helm")->wear();
}
void init()
{
        ::init();
        add_action("do_join","join");
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")=="天梟教") return notify_fail("你已是天梟教教眾了。\n");
     if(arg!="天梟教") 
		return notify_fail("你要拜入那一個門派?\n");
     say("尉遲妄說: 要拜天梟?。\n");
     say("尉遲妄說: 去找趙師弟吧...。\n");
        return 1;   
}