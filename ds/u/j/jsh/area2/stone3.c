#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"石魔巨人"NOR, ({ "evil man-stone","stone" }) );
        set("race","beast");
        set("gender", "男性");
        set("level",40);
        set("age",2014);
        set("evil",-20); 
        set("title",MAG"迷宮守護者"NOR); 
        set("long",@LONG
 石魔巨人，是為了讓入侵古墓禁地的人所設計的，高大
 ，寬碩，全身的石子緊密地結合，為維護古墓的平衡的
 重要功臣。
LONG
);
        set_skill("bagi_fist",80); 
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set_skill("combat",90);
        set("attitude","aggressive");
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                  (: command("exert bagi_fist") :), 
                  (: command("exert bagi_fist") :), 
       }) );
        setup(); 
        carry_object(__DIR__"stone-armor")->wear();
        carry_object(__DIR__"stone-fist")->wield();
}

void die()
{
        object killer;
        int last;
        if(random(7))
        {
                if(killer=this_object()->query_temp("last_damage_from"))
                {
                        last = killer->query("max_hp")/10;
                        if(last < killer->query("hp"))
                        {
                                message_vision(HIW"  $N的身體似乎有些異常..."HIR"碰"HIW"的一聲...$n被爆射開來的石子打得渾身是傷。\n"NOR,this_object(),killer);
                                last=killer->query("hp")-last;
                                killer->receive_damage("hp",last,this_object());
                        }
                }
        }
        ::die();
}

