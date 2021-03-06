// 2000/26/8 by lestia
// 靈幻教-靈修幻步
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
  "$n隨意飄動，輕易的將$N的攻擊閃過。\n",
  "$n身形一晃，一招「"+HIY"靈意隨身"+NOR"」，身形朝另一方遁去。\n",
  "$N正要擊中$n之時，忽然只見$n以極快的身法向後退去。\n",
  "$N的凌厲攻勢似乎以把$n逼入一個死角。$n一咬牙，不退反進，\n"
  "$n身形一閃，似欲向右避去。$N正待追擊，只見$n已經向左躍開。\n",
  "$n意隨念轉，腳步迅速，將$N的攻擊閃開。\n",
  "$n見$N的攻擊來勢洶洶，靈氣運轉全身，身形一晃，繞過$N。\n",
  "$n腳步謎幻，身影忽左忽右，閃過$N。\n",
});     

int exert(object me, object target, string arg)
{
        string msg;
        int add_dodge;

        if ( arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="soul-dream-step")
                        return notify_fail("你並沒有使用靈修幻步。\n");
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                        me->add_temp("apply/dodge", -me->query_temp("class_soul/soul-dream-step"));
                else me->set_temp("apply/dodge", 0);
                me->delete_temp("class_soul/soul-dream-step");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N將靈氣驅散，停止運行靈修幻步。\n"NOR,me);
    write( HIR"取消使用技能:『靈修幻步』。\n"NOR );
                return 1;
        }

        if ( me->query_skill("dodge") < 5 )
                return notify_fail("你的輕功\基礎不夠無法使用靈修幻步。\n");

        add_dodge = ((me->query_skill("dodge") * me->query_skill("soul-dream-step")) / (me->query_skill("dodge")+me->query_skill("soul-dream-step") - 4))/1.01 + random((me->query_skill("dodge")+me->query_skill("soul-dream-step"))/3);

        if ( me->query_skill_mapped("dodge")=="soul-dream-step" )
                return notify_fail("你正在使用靈修幻步。\n");

        if ( me->query("ap") < 10 )
                return notify_fail("你的身體目前狀況還無法使用靈修幻步。\n");

        if( !me->skill_active( "soul-dream-step", (: call_other, __FILE__, "delay", me :), 10) )
                return notify_fail("你的靈修幻步靈氣驅散動作還沒完成。\n");

        me->map_skill("dodge","soul-dream-step");
        me->reset_action();

        message_vision("\n"HIY"閉目沉思，將體內的靈氣運轉全身。\n"NOR,me);
        me->receive_damage("ap", 1);
        me->start_busy(1);
        if( !me->query_temp("class_soul/soul-dream-step") )
        {
                me->add_temp("apply/dodge", add_dodge);
                me->set_temp("class_soul/soul-dream-step", add_dodge);
        }
        else
        {
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                me->add_temp("apply/dodge", add_dodge - me->query_temp("class_soul/soul-dream-step") );
                else me->set_temp("apply/dodge", 0);
                me->add_temp("apply/dodge", add_dodge);
                me->set_temp("class_soul/soul-dream-step", add_dodge);
        }
        return 1;
}

void delay(object me)
{
        int main, dodge, a;
        main = me->query_skill("soul-dream-step") - 30;
        dodge = me->query_skill("dodge") - 30;
        a = main + dodge;


        if( !me ) return;

        if( me->query_skill_mapped("dodge") != "soul-dream-step" )
        {
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                        me->add_temp("apply/dodge", -me->query_temp("class_soul/soul-dream-step"));
                else me->set_temp("apply/dodge", 0);
                me->delete_temp("class_soul/soul-dream-step");
                return;
        }

        if ( me->query("ap") < 10 )
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N體內的靈氣散去，又回復到了一般的速度。\n"NOR,me);
                tell_object(me,"你的內息已亂，已無法再使用靈修幻步。\n");
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                        me->add_temp("apply/dodge", -me->query_temp("class_soul/soul-dream-step"));
                else me->set_temp("apply/dodge", 0);
                me->delete_temp("class_soul/soul-dream-step");
                return ;
        }

        if ( a > 1 ) a=1;
        if ( a < 0 ) a=0;
        if ( me->is_fighting() ) me->receive_damage("ap", 2-a);
        me->skill_active( "soul-dream-step",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        return 1;
}

int improve_limite(object ob)
{
        if( ob->query("class1")=="靈幻教" ) return 100;
        else return 115;
}

