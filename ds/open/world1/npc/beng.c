#include <ansi.h>

inherit NPC;
void create()
{
        set_name("閍", ({ "beng","beng" }) );
        set("race","human");
        set("gender", "男性");
        set("level",30);
        set("age",32);
        set("evil",-15);
        set("title",HIR"聖炎虎使"NOR);
        set("long",@LONG
使用鞭子的聖炎使者，融合了火炎的威力以及鞭子的靈動，
創造出能撕裂空氣造成真空的技巧，殺人於無形之中。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/bh_leg")->wear();
        carry_object(__DIR__"../wp/cv_whip")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(100) > 10) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if( !me->query_temp("weapon") ) return 0;
    if( environment(me) != environment(this_object()) ) return 0;
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIC"$N一抖鞭子，化出一道真空波衝向$n......\n"
                    +"$n並沒有察覺到真空波的無形攻擊，被正面擊中了......\n"
                    +"$n鮮血狂噴，傷口深及見骨......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",100+random(30), this_object());
      target->receive_wound("body",5);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N一抖鞭子，化出一道真空波衝向$n......\n"
                    +"$n警覺到$N的可怕攻擊，快速往旁邊閃去......\n"
                    +"$n及時的迴避，只讓真空波擦破皮肉，不致受重傷......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",random(50), this_object());
      return 1;
    }
}