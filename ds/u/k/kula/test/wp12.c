#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;
void create()
{
  set_name( "蜘蛛勀星" , ({ "tow-hand-sword+2:spider killed","sword" }) );
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由特殊金屬製成的雙手劍，具有不可思議的力量。\n");
    set("material", "iron");
    set("value",7000);
    set("volume",1);
  }
    set("weapon_prop/dodge",2);
    set("weapon_prop/hit",10);
    set("limit_str",20);
  init_sword(45,TWO_HANDED);
  setup();
}

int wield()
{
  object me;
  me = this_player();
  if(me->query("combat_exp") < 15000 )
  { return notify_fail("你經驗不足，無法使用蜘蛛勀星。"); }
  else { return ::wield(); }
}

void init()
{
        add_action("do_slash","slash");
}

int do_slash(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail( HIG " =SONIC SLASH= " NOR"只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
        if( me->query_skill("sword") < 60 )
                return notify_fail("你的劍術技巧還不足以發揮" HIG " =SONIC SLASH= " NOR "的實力。\n");
        if( me->query_temp("slash"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision( HIC "\n$N看到對手露出破綻，突然目光一閃，準備使出" HIG " =SONIC SLASH= " NOR "！！\n\n"NOR,me);

        me->set_temp("slash",1);
        call_out("do_crazy",2, me, target);
        call_out("do_clean",4,me);
        return 1;
}

int do_crazy(object me,object target)
{
  int i;
     if( random(100)>10 && me->query("ap")>80 && me->query("hp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("slash");
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIW"\n$N目光一閃，全身發出白光，對著"+target->query("name")+"使出" HIG " =SONIC SLASH= " NOR "！！"NOR,me);
      target->receive_damage("hp",random(50)+random( me->query_skill("sword"))+100);
      me->receive_damage("ap",50);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N呼吸混亂，一時間使不出" HIG " =SONIC SLASH= " NOR "。\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}

int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("slash");
          return 1;
}

