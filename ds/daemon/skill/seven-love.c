/*****七夕情意(Seven-love)    Update By Kkeenn****/
// 【七夕情傷】： [exert seven-love love]  增加攻擊力
// 【耗氣歸元】： [exert seven-love reap]  損血補內力
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void reap(object me, object *tar);
void love(object me, int ar1, int ar2);

int exert(object me,object target, string arg)
{
    int heal,reheal,sk,lv;
       sk = me->query_skill("seven-love");
    if( arg == "?" )
    {
    return notify_fail("請參考help seven-love文件，取得進一步使用說明。");
          }
          if( arg=="off" )
          {
              if( me->query_skill_mapped("force")!="seven-love" )
                  return notify_fail("你並沒有在運功\。\n");
              me->delete_temp("is_busy/seven-love");
              message_vision("$N閉起的兩眼慢慢睜開，內息又盤回丹田處。\n",me);
              me->map_skill("force");
              return 1;
          }

          if( me->query_skill_mapped("force")=="seven-love" )
                return notify_fail("你還處於七夕情傷的情緒中。\n");

    if( !arg )
    return notify_fail("請參考help seven-love文件，取得進一步使用說明。");
                           if( me->query("hp") < 20 || me->query("ap") < 20 )
                               return notify_fail("你目前的狀況不佳，無法運行此功\。\n");
                   if( arg=="reap" )    // 【耗氣歸元】
                       {
                           if( me->is_fighting() )
                           return notify_fail("你現在正忙著打架, 沒空練功\。\n");

                           sk = (int)me->query_skill("seven-love");
                           sk = (sk > 50) ? 50 + (( sk-50 )/2) : sk;
                           lv = (int)me->query("level");
                           heal = (int)me->query("max_ap");
                           reheal = (heal / 15) + ((sk/5)*3) + random(9) + (lv/2);
//                           if( me->query("quest/win") < 1 ) return notify_fail(HIW"你還沒經過情城池大考驗！\n"NOR);
                           if( me->query("hp") < 30 )
                               return notify_fail("你目前於瀕死狀態, 無法恢復自身內力！\n");
                           if( me->query_skill("seven-love") < 60 )
                               return notify_fail("你的七夕情意等級不夠！\n");
                           if( me->query_skill("force") < 70 )
                               return notify_fail("你的內功\心法等級不夠！\n");
                           if( me->query("level") < 30 )
                               return notify_fail("你的等級不夠！\n");
                           if( me->query("ap") >= heal )
                               return notify_fail("你目前的內功\狀況已經是頂尖了。\n");
                           me->receive_heal("ap",reheal);
                           me->receive_damage("hp", 17 + reheal/8 + random(4));
                           me->start_busy(2);
                           message_vision("$N心一橫，張口將舌尖咬破，將精神提高到另一種境界。\n",me);

                           me->improve_skill("seven-love",me->query("int")/4 + random(4));
                           me->improve_skill("force",me->query("int")/4 + random(3));

                           return 1;
                       }
                       if( arg == "love" ) //  【七夕情傷】
                       {
                           int effect;
                           if( me->query("marry_id") )
                               return notify_fail("你已在蜜意中，哪來傷情？\n");
                           if( me->query("MKS") < 150 )
                               return notify_fail("你的血腥氣還不足以提昇本身的攻擊力！\n");
                           if( me->query_skill("force") < 50 )
                               return notify_fail("你的內功\心法不夠強！\n");
                           if( me->query_skill("seven-love") < 30 )
                               return notify_fail("你對於七夕情意還無相當的了解﹐所以無法施放七夕情傷！\n");
                           if( me->query("hp") < 100 )
                               return notify_fail("你的體力不夠喔！\n");
                           if( me->query("ap") < 100 )
                               return notify_fail("你的內力不支足以使出七夕情傷！\n");
                           if( me->query_temp("class_whip/in_love") )
                               return notify_fail("你已經使用過七夕情傷了﹐無法再繼續增強了！\n");
      message_vision(HIG"$N"HIG"輕輕地唱道：「萬千心事難寄，樓上幾日春寒」，濃郁的七夕情傷瀰漫開來。\n"NOR, me);
//                             message_vision(HIR"只見$N"HIR"身後隱隱浮現出一隻浴火鳳凰的形體，$N"HIR"攻擊力大大提昇了！！\n"NOR, me);

                           effect = sk*3/4;

                           me->add_temp("apply/damage", effect);
                           me->receive_damage("ap", 100);
                           me->receive_damage("hp", 50);
                             if( me->is_busy() || me->is_fighting() )
                               me->add_busy(2);
                           else me->start_busy(1);

                           me->set_temp("class_whip/in_love", 1);
                           me->improve_skill("seven-love",me->query_int()/4 + random(3) );
                           me->improve_skill("force",me->query_int()/4 + random(3) );
                   me->skill_active("seven-love",(: call_other,__FILE__,"seven_love",me, effect:), 60);
                           return 1;
                       }
                       else return notify_fail("七夕情意沒有這種功\能！\n");

}

void seven_love(object me, int effect)
{
    if(!objectp(me)) return;
    me->add_temp("apply/damage", -effect);
    me->delete_temp("class_whip/in_love");
      message_vision("$N從七夕情傷的低沉情緒中恢復過來了。\n", me);
    return;
}

void delay(object me)
{
    int sk_level, lv,i;
    sk_level = me->query_skill("seven-love");
    lv = me->query("level");
    i = me->query_int();

    if( !me ) return;

    if( me->query_skill_mapped("force")!="seven-love" ) return;

    if( me->query("ap") < 13 || me->query("hp") < 13 )
    {
        message_vision("$N心神如雷轟頂，瞿然停止了運功\。\n",me);
        me->delete_temp("is_busy/seven-love");
        me->map_skill("force");
        return;
    }
    else if ( sk_level < 50 )
    {
        me->receive_damage("ap",20);
        me->receive_damage("hp",10);
    }
    else if ( sk_level > 49 )
    {
        me->receive_damage("ap",22);
        me->receive_damage("hp",12);
    }
    me->improve_skill("force",1 + random(5+lv/2) + (sk_level/5) + (i/3) );
    me->improve_skill("seven-love",1 + random(5+lv/2) + (sk_level*3/8) + (i/3) );
me->skill_active( "seven-love",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}

void skill_improved(object me) // 注意, 一個skill能增加的屬性總和以 5 為上限
{
    int b,c;
    b = me->query_skill("seven-love",1);
    c = me->query("skill/seven-love");

    if( b % 20==19 && b > c)
    {
        if(random(2))
        {
            tell_object(me, HIR "你的動作由於體悟七夕情意有成而更加輕盈了。\n" NOR);
            me->add("addition/dex", 1);
        }
        else
        {
            tell_object(me, HIR "你的體質由於領悟七夕情意有成而增強了。\n" NOR);
            me->add("addition/con", 1);
        }
        me->set("skill/seven-love", b);
    }
    me->save();
}

int improve_limite(object ob)
{
    int a;
    a=(ob->query("level")*3)+(ob->query_int());
    if( a > 90 && ob->query("level") < 26 ) a=100;
    else if( a > 100 ) a =100;
    return a;
}

