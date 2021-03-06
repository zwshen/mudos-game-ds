#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SSERVER;

void do_attack();

void create()
{
        set_name("周人傑",({"zhou ren jie","zhou","jie"}) );
        set("long",@long
　　周人傑長的塊頭極大，穿著一件貼身背衣，露出渾身挺拔的肌肉，只
是方方正正的國字臉上長著一對細小的眼睛，削減了幾份陽剛氣。周人傑
是萬斧莊的門下二弟子，一手斧頭功夫使得虎虎生風，在江湖上頗有名氣
，只是萬斧莊地理偏僻，不知其門人為何會遠程到此。
long
);
        set("age",40);
        set("race","人類");
        set("level",30);
        set("attitude", "peaceful");
        set("title","萬斧莊第十三代弟子");
        set("gender", "男性" );
        set("chat_chance",6);
        set("chat_msg",({
                "周人傑喃喃自語地說道：費盡千辛萬苦才尋來這兒，怎地就再也沒有其它可疑跡象...\n"
                "周人傑對著身眾的弟子喝道：別偷懶！！快給我去四處找找有沒有可疑的地方！！\n"
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
        add_money("coin",2000);
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
                 target_wp->set_durable((target_wp->query_durable() - 1 -random (3) ) );
        } else {
                message_vision(HIR"$N閃躲不及，用一雙肉掌硬是接下了這次攻擊，但也被震地吐血受傷...\n"NOR,target);
                target->receive_damage("hp",50+random(20));
        }
        return ;
}

