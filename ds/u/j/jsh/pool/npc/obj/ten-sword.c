#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
  set_name(HIC"十方俱滅"NOR , ({ "ten-destruct sword","sword" }) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "乍看是把普通的舊劍，劍刃上還龜裂了許\多地方，但瞧著瞧著突然領悟到\n"
                "也許\這些裂痕是特意製造出來的，或許\可以..[break_sword]\n");
    set("material", "gold");
    set("value",30000);
    set("weapon_prop/str",1);
    set("weapon_prop/con",1);
    set("weapon_prop/dex",1);
    set("weapon_prop/bar",-1); 
    set("weapon_prop/wit",1);
    set("weapon_prop/parry",-5);
}
    init_sword(50); 
  setup();
}
void init()
{
    add_action("do_break_sword","break_sword");
}
int do_break_sword(string arg)
{
    object me,victim;
    me = this_player();  
    if( !me->is_fighting() )
    return notify_fail("你沒有在戰鬥。\n");
    victim = me->select_opponent();
    message_vision(HIR"─ $N將十方俱滅插在地上，在將劍折斷的同時，大喊『毀滅破十方』 ─\n"NOR,me);
    me->start_busy(2); 
    if(random(10) > 5)
        {
                   message_vision(HIC"十方俱滅"HIW"斷化成無數碎片，"HIR"飛向"+victim->query("name")+"！\n"NOR,me);  
                   COMBAT_D->do_attack(me, victim, this_object(), 5);
                   COMBAT_D->report_status(victim);
                   victim->add_busy(5);   
                   victim->receive_damage("hp",2000+random(1500));
        } 
        else{
                    message_vision(HIC"十方俱滅"HIW"斷的非常完整，$N的表情就是：『那Ａ安ㄟ!!??』\n"NOR,me); 
                   tell_object(me,"[對方完全沒受到毀滅破十方的傷害]\n");
                   me->add_busy(3);
        } 
      destruct(this_object());
      return 1;
}

