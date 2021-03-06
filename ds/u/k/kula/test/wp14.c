#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;
void create()
{
  set_name( "克倫•斐厄" , ({ "longsword+3:Crom Feary","sword" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "長劍+3：克倫•斐厄，俱有復仇的力量" HIR "\n死之輪舞(whirl dance of death)" NOR "\n指令：wdod\n");
    set("material", "wood");
    set("value",10000);
    set("volume",1);
  }
    set("limit_str",40);
    set("limit_level",30);
  init_sword(65);
  setup();
}

void init()
{
        add_action("do_wdod","wdod");
}

int do_wdod(string arg)
{
        object me, target;
        int time
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        if (( this_object()->query("equipped"))!="wielded")
                return notify_fail("你並沒有裝備冰之刃!\n") ;
        if(!me->is_fighting())
                 return notify_fail("你並不在戰鬥中！\n");
        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
        if( me->query_temp("wdod"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision( HIR "\n$N大喊：「接受我的血之仇恨吧！！\n\n"NOR,me);

        me->set_temp("wdod",1);
        me->start_busy(1);
        call_out("do_crazy",2, me, target, time);
        call_out("do_clean",4,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( me->query("hp")<150)
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("hits");
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIC"\n$N眼裡流出血淚，全身發出血光，對著"+target->query("name")+"施展出「死之輪舞」！！\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
    }
          me->receive_damage("hp",100);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N復仇的時機還未成熟。\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("wdod");
          return 1;
}
