#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIG"史賴格"NOR, ({ "meat-eat worm","worm" }) );
        set("race", "野獸");
        set("age", 1);
        set("level",2);
        set("long", "成天在垃圾堆中打滾的臭蟲，長得滿嘴利牙。\n");
        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("chat_chance", 10);
        set("chat_msg", ({
           (: this_object(), "random_move" :),
           "史賴格在路邊的垃圾堆裡翻來翻去。\n" }) );
        setup();
}

int special_attack(object me,object victim,int hitrole)
{
        if(!me || !victim) return 0;
        if(random(5)) return 0;
        
        message_vision(HIW"$N滿嘴利牙對$n一陣亂咬，"NOR,me,victim);
        if(hitrole > 100)
        {
                victim->apply_condition("poison", victim->query_condition("poison")+3);
                message_vision(HIW"$n閃躲不及而被咬中，傷口發紫。\n"NOR,me,victim);
                victim->receive_damage("hp",20+random(20),me);
                return 1;
        }
        else message_vision(HIW"但被$n機警的閃了過去。\n"NOR,me,victim);
        return 0;
}
