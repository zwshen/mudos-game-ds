#include <ansi.h>
inherit NPC;

void do_fire() 
{
        object target;
        int dmg;
        if( is_busy() ) return;

        target = this_object()->query_opponent();
        if(!objectp(target)) return;
        message_vision(HIW"$N"HIW"伸出手指，招喚出一枚骨箭擲向$n"HIW"...\n"NOR,this_object(),target);
        dmg = this_object()->query_damage() - target->query_shield();
        if(dmg<10) dmg = 10 + random(30);
       	dmg = COMBAT_D->Merits_damage(this_object(), target, dmg, "bio");
        if( random(200) > target->query_skill("dodge") ) {
                message_vision(HIR"刷地一聲，骨箭刺穿$n"HIR"的要害！！！\n"NOR,this_object(),target);
                target->receive_damage("hp", dmg, this_object());
        } else {
                message_vision(CYN"但是骨箭歪歪斜斜的射歪了。\n"NOR,this_object(),target);
        }
}
void create()
{
        set_name("土人祭師", ({ "fetish wizard","fetish","wizard","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
有些像教徒般的生物，會以和他們身軀差不多的刀來攻擊，小土人原
本是叢林中的居民，一般稱為他們為食人族，身體較小、十分聰明的生物
，單獨的小土人十分脆弱而且可以輕易打倒。而土人族群中的祭師更是自
然元素的擅長者，具有控制火攻擊敵人的能力。
long
);
        set("title","血腥荒野");
		set("race","evil");
		set("level", 28 + random(5));
        set("age", 120);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: do_fire :),

        }) );

        set("attitude", "aggressive");
        setup();
        switch(random(4)) {        
        case 0:
                carry_object(__DIR__"obj/boots")->wear();
        break;
        case 1:
                carry_object(__DIR__"obj/belt")->wear();
        break;
        case 2:
                carry_object(__DIR__"obj/ring")->wear();
        break;
        case 3:
                carry_object(__DIR__"obj/armor")->wear();
        break;
        }        
        carry_object(__DIR__"obj/staff")->wield();        
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");

}

