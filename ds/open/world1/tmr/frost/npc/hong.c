#include <ansi.h>
inherit NPC;

void create()
{
        set_name("洪凌波", ({ "hong lingbo", "hong", "lingbo" }));
        set("long", "洪凌波是赤鍊仙子李莫愁大弟子，長相甜美，深得師尊的喜愛。\n");
        set("gender", "女性");
        set("attitude","heroism");

        set("level", 30);
        
        set_skill("whip",100);
        set_skill("block",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("sword",100);

        create_family("古墓派", 4, "弟子");

        setup();
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 50);
        carry_object(__DIR__"wp/steel-sword")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon;
    if(!me || !target)
        return 0;
    if(random(10)<7) return 0;

    message_vision(HIC"\n$N"HIC"嬌喝一聲，擲出一道慘白色的光芒沒入$n"HIC"手臂裡，竟然是冰魄銀針！！\n" NOR,this_object(), target);
    target->receive_damage("hp", query_damage()/2 + random(query_damage()), this_object());
    target->apply_condition("poison", 5);
    target->add_busy(1);
    return 1;
}

