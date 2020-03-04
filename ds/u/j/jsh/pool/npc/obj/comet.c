#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"彗星反擊•破"NOR,({"comet_strick back-pou","pou"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顆");
                set("long",
               "此乃天地之石，神聖彗星所製，在固定的時間會發出神蹟般的力量，也可使用累積起來的力量(back)。\n");
             }
        set("value", 42000);
        set_weight(6000);     
  
        setup();
}
void init()
{
     add_action("do_back","back");
}
int do_back(string arg)
{
    object me,ob,victim;
    me=this_player(); 
    ob=this_object();
    if(!me->is_fighting())
    return notify_fail("你沒有在戰鬥！\n"); 
    victim = me->select_opponent();
    message_vision(HIW"$N"HIC"高高的舉起"+ob->name(1)+"並大喊：神聖力量！！彗星•破！！\n"NOR,me);
    me->start_busy(3);
    if(random(10) >5)
    {
    message_vision(HIR"一道火紅的光芒籠罩著"+victim->query_name(1)+"，同一時間，一股巨大的紅光從"+victim->query_name(1)+"身體爆發出來！\n"NOR,me);
    COMBAT_D->do_attack(me,victim,this_object(),5);
    COMBAT_D->report_status(victim);
    victim->add_busy(8);
    victim->receive_damage("hp",500+random(500));
    victim->receive_damage("ap",400+random(400));
    victim->receive_damage("mp",300+random(300));
    } 
    else{
    message_vision(HIW""+victim->query_name(1)+"閃過了紅光的籠罩！！\n"NOR,me); 
    me->add_busy(2);
    }    
    destruct(this_object());
    return 1;
}
void attack(object me, object victim) 
{    int damage,tk_one;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("force") > 80 && me->query_con() > 60 && random(10)<3 )
    {
      message_vision(HIW "\n『鏘』的一聲響！"HIY"彗星反擊•破"HIW"的秘密力量瞬間爆發！！\n" NOR,me,victim);
      damage += me->query_skill("force")+me->query_con()+random(50);
      tk_one += victim->query_skill("parry")+victim->query_dex();
      tk_one = tk_one/3;
      if(damage-tk_one>0 && random(10)>5)
      {
        damage=damage+random((damage-tk_one));
        message_vision(HIR "無垠的天邊，咻∼地降下一顆鐵石，砸向"+victim->query_name(1)+"，只見紅光四爆！\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else 
      message_vision(HIG "$N向旁一跳，閃過了這致命的一擊。\n"NOR,victim);
    }
    return;
}

