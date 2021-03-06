//code by wilfred, wp_long by wilfred...Promise@DS 2004/06/07
#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void speed(object me, object target);

void create()
   {
  set_name(HIW"混元"BLK"六合劍"NOR, ({ "mix six sword", "sword" }) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", @LONG
此劍為上古神兵－『六合劍』所分離出來的一把劍，性屬陰，
劍身平板，黝黑至極，連劍柄也是以烏木製成，佩帶此劍時，
渾身散發著極為陰冷的氣息，似乎連周遭事物也凍結了。
LONG
);
    set("value",20000);
    set("material", "steel");
    set("wield_msg", HIW"$N抽出六合劍後，大地裡開始不安跳動了起來。\n"NOR);
    set("unwield_msg", HIC"$N收起了六合劍後，大地之氣息開始平復了起來。\n"NOR);
  }
  set("limit_skill",100);
  set("weapon_prop/dex",4);
  set("weapon_prop/str",4);
  set("weapon_prop/con",1);
  set("weapon_prop/int",-3);
  set("class_only",({"疾風門","八極門"}));
  init_sword(70);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(6)) return;
  speed(me, victim);
  return;
}
void speed(object me, object target)
{
  int again = me->query_dex() / 60 ;
  int index = 2;
  if(!me->is_fighting()) return;

  if(me->query("ap") < 40)
  {
    message_vision(HIW"$N手中的六合劍開始不聽使喚。\n"NOR,me);
    write(HIR"現在的身體狀況不適於操縱六合劍。\n"NOR);
    me->start_busy(1);
    me->command("unwield mix six sword");
    return;
  }
  message_vision(HIW"\n\t$N劍頭朝天，逆持六合劍，心定神凝的默背混元心訣。\n\n"NOR,me,target);
  message_vision(HIW""BLK"頃刻間，劍氣緩緩的竄出六合混元之氣!!\n"NOR,me);
  call_out("speed_1",1,me,target,0,again,index);
  return;
}

void speed_1(object me, object target, int hit, int again, int index)
{
  string msg;
  int me_att, ta_def, maxhit, temp_damage, damage, i;
  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N將動作取消了。\n",me);
    return;
  }

  me_att = me->query("combat_exp");
  ta_def = target->query("combat_exp");
  again ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() / 3;

  if(environment(me) != environment(target))
  {
    message_vision("$N因為對手不在取消了攻勢。\n",me);
    return;
  }

  // 特攻部份
  for(i=1;i<maxhit;i++)
  {
    msg = HIW+BLK"$N旋轉手中的劍，迅速刺出。";

    damage = random(temp_damage)+20;
    if( (me_att > ta_def * 3 && random(7)) || (me_att > ta_def * 3 / 2 && random(6)) || (me_att * 3 / 2 > ta_def && random(3)))
    {
      hit++;
      msg += HIW+BLK"陣陣混元氣息在$n的手中竄出"NOR"( "HIW"第 "NOR+GRN +hit+HIW" 道劍氣 )。"NOR+HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
      ::attack();
    }
    else
    {
      if( me_att * 2 > ta_def && random(3))
      {
        msg += HIC"劍氣道道的被$n化解\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIY"身輕如燕子般，從容不迫的躲開攻勢!!\n\n"NOR;
        message_vision(msg,me,target);
        COMBAT_D->report_status(target);
        me->start_busy(3);
        target->start_busy(0);
        return;
      }
    }
    target->start_busy(2);
    me->start_busy(2);
    me->receive_damage("ap", 10, me);
    if(me->query("ap") < 40)
    {
      message_vision(HIG"強大的混元氣息在$N脫穎而出，使得$N楚於毫無招架之力狀態！\n"NOR,me);
      me->start_busy(2);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(again > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(NOR+BLU"$N的體內的混元六合氣消失殆盡，攻勢暫緩了下來!!\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N蓄勢待發，混元氣息灌注在六合劍中，快速的射出數道劍氣\n\n"NOR,me,target);
    message_vision(HIR"射出第"+chinese_number(index)+"道混元六合劍氣。\n"NOR,me);
    again--;
    index++;
    call_out("speed_1",1,me,target,hit,again,index);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(NOR+GRN"\n$N再次遭受到劍氣的傷害，不知倒地。"HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 10, me);
  COMBAT_D->report_status(target);
  return;
}

