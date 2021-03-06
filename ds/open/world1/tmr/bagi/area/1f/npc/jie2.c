#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SSERVER;

void do_attack();

void create()
{
        set_name("周英傑",({"zhou ying jie","zhou","jie"}) );
        set("long",@long
　　周英傑長的一張黑臉，身材略壯，看起來似乎是莊傢漢的樣子，
但細瞧他腰帶上佩的一塊玉佩，上頭似乎題著「萬斧」二字，瞧他這副
年輕的模樣，倒也看不出是萬斧莊的弟子。
long
);
        set("age",25);
        set("race","人類");
        set("level",25);
        set("attitude", "peaceful");
        set("title","萬斧莊第十三代弟子");
        set("gender", "男性" );
        set("chat_chance",6);
        set("chat_msg",({
                "周英傑喃喃自語地說道：不知師兄說的到底準不準，這種鬼地方會有寶藏嗎？\n",
                (: command("shrug") :),
        }) );
        set_skill("unarmed",80);
        set_skill("axe",80);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:do_attack:),
        }) );

        setup();
        carry_object(__DIR__"wp/huge-axe")->wield();
        carry_object(__DIR__"eq/armor")->wear();
        carry_object(TMR_PAST"bagi/npc/obj/right-arm");
}



void do_attack()
{
        object me=this_object(),target,wp,target_wp;
        target = offensive_target(me);  // 敵人
        if(!me || !target) return;
        if(me->is_busy() ) return;
        if(!me->query_temp("weapon") ) command("wield axe");
        wp=me->query_temp("weapon");
        if(!wp) return;
        target_wp=target->query_temp("weapon");
        message_vision(HIW"$N大喊一聲：「一怒催山倒」，手中巨斧在急速之下帶著火花擊向$n....\n"NOR,me,target);
        if( target_wp ) {
                message_vision(HIC"「噹」地一聲巨響，$N用手中$n"HIC"擋了下來...\n"NOR,target,target_wp);
                target_wp->set_durable((target_wp->query_durable() - 1 ) );
        } else {
                message_vision(HIR"$N閃躲不及，用一雙肉掌硬是接下了這次攻擊，但也被震地吐血受傷...\n"NOR,target);
                target->receive_damage("hp",20+random(10));
        }
        return ;
}

