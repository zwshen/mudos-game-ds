#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;
void berserk(object me, object target);
void create()
{
  set_name(MAG"詭譎鞭"NOR, ({ "strange whip", "whip" }) );
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", @LONG
此鞭乃是當年妙法仙尊在西疆修行時，在一個名為【萬毒窟】處發現一
塊不知名的礦石，堅硬之極，因此妙法仙尊就以西安城鞭王之最的「烏金絲
鞭」，配合自身的元精，共同煉製而成這條冠絕今古的詭譎鞭。
LONG
);
    set("value", 20000);
    set("material", "gold");
    set("wield_msg", "$N小心翼翼的從腰間抽出一條$n，附近的鬼魅好像都向你聚來了。\n"NOR);
    set("unwield_msg", "$N提起$n一抖，$n像是有生命一般纏回腰上去了。\n"NOR);
  }
  set("replica_ob", __DIR__"whip5.c");
  set("limit_skill",60);
  set("weapon_prop/dex", 2);
  set("weapon_prop/con", 2);
  set("weapon_prop/str", 2);
  set("weapon_prop/int", 3);
  set("class_only",({"情城池"}));
  init_whip(75);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if( !me ) return;
  if( !victim ) return;
  if( me->is_busy() ) return;
  if( random(8) ) return;
  berserk(me, victim);
  return;
}


void berserk(object me, object target)
{
  int atts = me->query("dex") / 60 ;
  int time = 2;
  if(!me->is_fighting()) return;
  if(me->query("ap") < 40)
  {
    message_vision("$N提起手邊的鞭子，似乎想使用啥絕招。\n"NOR,me);
    write(WHT"[你目前的狀況支撐不了詭譎鞭的絕招]\n"NOR);
    me->start_busy(1);
    return;
  }
  message_vision(HIW"\n\t$N突然一揚手中詭譎鞭，天地間的鬼魅全被吸取過來了！\n"NOR,me,target);
  call_out("berserk_1",1,me,target,0,atts,time);
  return;
}

void berserk_1(object me, object target, int hit, int atts, int time)
{
  string msg;
  int me_att, ta_def, maxhit, temp_damage, damage, i;
  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N將動作取消了。\n",me);
    return;
  }

  atts ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() / 3;

  if(environment(me) != environment(target))
  {
    message_vision("$N因為對手不在取消了攻勢。\n",me);
    return;
  }

  for(i=1;i<maxhit;i++)
  {
    msg = "$N的詭譎鞭上爆出一隻魑魅魍魎！";
    damage = random(temp_damage)+17;
    if( random(me->query_dex()*3) > target->query_dex() )
    {
      hit++;
      msg += MAG"魑魅魍魎貫穿了$n的身體？！ "NOR""WHT"(第"HIW +chinese_number(hit)+ WHT"隻的攻擊)。"HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
      ::attack();
    }
    else
    {
      if( random(me->query_dex()*2) > target->query_dex() )  //提昇閃躲率
      {
        msg += HIW"可惜被$n"HIW"躲過了。\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIR"「噹」的一聲響，魑魅魍魎被$n"HIR"的正直之氣震散了!!\n\n"NOR;
        message_vision(msg,me,target);
        COMBAT_D->report_status(target);
        me->start_busy(3);
        target->start_busy(0);
        return;
      }
    }
    
    target->start_busy(1);
    me->start_busy(1);
    me->receive_damage("ap", 40, me);
    
    if(me->query("ap") < 40) {
      message_vision(HIG"$N的內氣不足，全身一軟，跪倒在地上！"HIR"(有走火入魔的可能)\n"NOR,me);
      me->start_busy(5);
      return;
    }
  }
//  COMBAT_D->report_status(target);

  if(atts > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(MAG"$N附近的鬼魅不夠，後續攻擊停了下來。\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N噴了一口鮮血，試圖吸引更多鬼魅到來，又朝著$n衝了過去。\n\n"NOR,me,target);
    message_vision(WHT"使出第"+time+"次"HIW"的魑魅魍魎!!\n"NOR,me);
    atts--;
    time++;
    call_out("berserk_1",2,me,target,hit,atts,time);
    return;
  }

  message_vision(HIR"殘餘在$N"HIR"體內的"MAG"邪氣"HIR"一口氣爆發開來，霎時血花四濺，慘不忍睹！！ "HIR"("+damage+")\n"NOR,target);
  damage = random(temp_damage) * 2 +temp_damage;
  target->receive_damage("hp", damage, me);
  COMBAT_D->report_status(target);
  return;
}

