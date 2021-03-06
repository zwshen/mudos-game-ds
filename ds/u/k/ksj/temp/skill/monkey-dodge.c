#include <ansi.h>
inherit SKILL;

void remove_add_dodge(object me);

string *dodge_msg = ({
        HIM"$n察覺$N的攻勢，立即屈身跳躍到一旁，閃過$N的攻擊。\n"NOR,
        HIM"$n凌空躍起，在空中一個翻轉，落地時已在$N身後。\n"NOR,
        HIM"$n忽左忽右幾個蹦跳，逃離了$N招式的範圍。"NOR,
        HIM"$n右手抵地一個翻滾，險險躲過$N的攻擊。\n"NOR,
        HIM"$n身形不動，向正後方滑步，使得$N的招式落空。\n"NOR,
});

int exert(object me, object target, string arg)
{
  int tmp;
  if ( arg=="off" )
  {
    if( me->query_skill_mapped("dodge")!="monkey-dodge")
      return notify_fail("你並沒有使用猿飛之術。\n");
    me->map_skill("dodge");
    me->reset_action();
    message_vision("\n"HIW"$N又恢復回原來的速度了。\n"NOR,me);
    remove_add_dodge(me);
    write("取消使用技能 - 閃避之技猿飛之術。\n");
    return 1;
  }
  if( me->query_skill("dodge") < 5 )
    return notify_fail("你的輕功\基礎不夠無法使用猿飛之術。\n");
  if( !me->skill_active("monkey-dodge", (: call_other, __FILE__, "delay", me :), 12) )
    return notify_fail("你正在使用猿飛之術。\n");
  if( me->query("ap") < 10 )
    return notify_fail("你的身體目前狀況還無法使用猿飛之術。\n");
  me->map_skill("dodge","monkey-dodge");
  me->reset_action();
  message_vision("\n"HIB"$N眼觀八面，舒緩筋骨，開始使用猿飛之術。\n"NOR,me);
  me->receive_damage("ap", 1);
  me->start_busy(1);
  if( me->query_temp("class_blade/monkey-dodge") )
    remove_add_dodge(me);
  me->add_temp("apply/sk_dodge", (tmp = me->query_skill("monkey-dodge",1)*2/5 + me->query_skill("dodge", 1)/5 + random(me->query_skill("dodge",1)/4)));
  me->set_temp("class_blade/monkey-dodge", tmp);
//      me->skill_active("fogseven", (: call_other, __FILE__, "delay", me :), 12);
  return 1;
}

void delay(object me)
{
  if( !me ) return;
  if( me->query_skill_mapped("dodge")!="monkey-dodge" )
  {
    remove_call_out("delay");
    remove_add_dodge(me);
    return;
  }

  if( me->query("ap")<10 )
  {
    me->map_skill("dodge");
    me->reset_action();
    message_vision("\n"HIW"$N又回復到了一般的速度。\n"NOR,me);
    tell_object(me,"你的內息已亂，已無法再使用猿飛之術。\n");
    remove_add_dodge(me);
    remove_call_out("delay");
    return ;
  }

  if( me->is_fighting()  )
  {
    if( (me->query_skill("monkey-dodge") + me->query_skill("dodge") - 30) > 1 ) me->receive_damage("ap", 1);
    else me->receive_damage("ap", 2);
  }
  me->skill_active("monkey-dodge",(: call_other, __FILE__, "delay", me :), 10);
}

void remove_add_dodge(object me)
{
  int ar1 = (int)me->query_temp("class_blade/monkey-dodge");

  if( ar1 < 0 ) return;
  me->add_temp("apply/sk_dodge", -ar1);

  me->delete_temp("class_blade/monkey-dodge");
  return; 
}

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob) { return 100; }
int valid_learn(object me) { return 1; }
