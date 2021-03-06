#include <ansi.h>

inherit NPC;

void create()
{
        set_name("歲氿", ({ "swe gui","gui" }) );
        set("race","human");
        set("gender", "男性");
        set("level",28);
        set("age",20);
        set("evil",-15);
        set("title",HIR"聖炎刃使"NOR);
        set("long",@LONG
年僅二十就擁有了「聖炎使者」的稱號，擅長的是將火炎化
成刀刃使用。聖炎使者是使用炎術者的最高稱號，千年以來
僅有極少數人能得到此一稱號。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/gs_waist")->wear();
        carry_object(__DIR__"../wp/flame_blade")->wield();
}

int special_attack(object me,object target,int hitchance)
{

    int tdex; 
    if(!me || !target) return 0;
    if(random(4)) return 0;
    tdex=target->query_dex();
    if(random(hitchance/3) > tdex)
    {
      message_vision("\n"
                    +HIR"$N喃喃念了幾句咒文，將火炎緩緩凝聚成炎刀......\n"
                    +"$N大喝一聲，瞬間出現在$n面前，狠狠砍了$n一刀......\n"
                    +"$n同時受到刀傷跟燒傷，痛苦不已......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",80+random(30));
      target->apply_condition("blooding", target->query_condition("blooding")+1);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N喃喃念了幾句咒文，將火炎緩緩凝聚成炎刀......\n"
                    +"$N大喝一聲，瞬間出現在$n面前，$n一個翻身躲過了攻擊......\n"
                    +"$n險險躲過了攻擊，但也嚇出了一身冷汗......\n\n"NOR
                    ,me,target);      
      target->add_busy(1);
      return 1;
    }
}