#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SSERVER;

// 弧月.
void do_arc() 
{
        object me,target,wp;
        me=this_player();
        target = offensive_target(me);  // 敵人
        if(!me || !target) return;
        wp=target->query_temp("weapon");
        if(!wp) {
                command("exert sorgi_sword");
                return ;
        }

        message_vision(HIW "左手一揮，赫然出現一道弧月疾攻向$n"HIW"拿武器的雙手！！\n" NOR,me,target);
        if( (target->is_busy() || random(100)<30  )  && wp->unequip()  ) {
                message_vision(HIC"「鏘」"NOR"地一聲響，"HIC"弧月"NOR"撞得$N脫落了手中的武器！！\n" NOR ,target);
                target->start_busy(1);
        } else {
                message_vision(CYN "「鏘」"NOR"地一聲響，弧月一撞上$N手中的武器反而被震碎了！！\n" NOR,target);
        }
}

void create()
{
        set_name("瘋漢",({ "madman","man" }));
        set("long" ,@LONG
一個披頭散髮的老人，整張臉都被毛髮鬍子遮去大半，只露出空洞而
呆滯的雙眼，不時地低吼鬼叫，似乎是個神經錯亂的瘋子似。
LONG
        );
        set("attitude","friendly");
        set("age", 60);
        set("level", 30);
        set("gender","男性");
        set("race","人類");
        set_temp("sorgitimes",12);

        set_skill("sword", 90);
        set_skill("dodge", 95);
        set_skill("force", 100);
        set_skill("parry", 80);
        set_skill("sorgi_sword",85);
        set_skill("fogseven",100);
        set_skill("moon_force",100);
        map_skill("sword","sorgi_sword");
        map_skill("dodge","fogseven");

        set("chat_chance",10);
        set("chat_msg", ({
                (: command("crazy madman") :),
                "瘋漢忽然瘋狂般的扯起自已的鬍子，不知在氣腦什麼...\n",
                "瘋漢雙眼一翻，嘴裡不知在咕噥些什麼....\n",

        }));
        set_temp("class_wind/power",250);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
  		(: command,"exert sorgi_sword" :),
                (: do_arc :),
        }));
        setup();
        carry_object(__DIR__"wp/half-sword")->wield();
          carry_object(TMR_PAST"bagi/npc/obj/left-leg");
}

