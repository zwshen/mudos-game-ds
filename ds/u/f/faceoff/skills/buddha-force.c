//凌雲寺：無上梵功(buddha-force)  
// 日期: 1999.12.11  By DS-Acme

#include <ansi.h>
inherit SKILL;

void armor(object me,int effect);
void delay(object me);

int exert(object me,object target, string arg)
{
        int force,buddha,heal;

        force=me->query_skill("force",2);
        buddha=me->query_skill("buddha-force",2);
        heal=(force+buddha)/2;

        if(arg=="off") 
        {
                if(me->query_skill_mapped("force")=="buddha-force")
                {
                   message_vision("$N站起身來，停止了修行無上梵功\。\n",me);
                   me->delete_temp("is_busy/buddha");
                   me->map_skill("force");
                   return 1;
                } else return notify_fail("你並沒有在修行無上梵功\。\n");    
        }

        if(!arg)
        {
//           if(me->is_busy() )
//                return notify_fail("你先停止你手邊的事情吧。\n");
//           if(me->is_ghost() )
//                return notify_fail("你現在是靈魂，無法修行內功\。\n");
           if( me->query_skill_mapped("force")=="buddha-force" ) 
                return notify_fail("你已正在修行無上梵功\了。\n");
           if(me->query("hp") < 10 || me->query("ap") < 10 ) 
                return notify_fail("你目前的身體狀況不好，無法修行無上梵功\。\n");
           if(me->is_fighting() )
                return notify_fail("你正忙著打架，沒空修行無上梵功\。\n");
           if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("你現在正在忙。\n");
           message_vision(HIY "$N盤膝而坐，雙手合什，閉目吐氣，開始修行無上梵功\。\n" NOR,me);
  
           me->receive_damage("hp",5);
           me->receive_damage("ap",5);
            
           me->set_temp("is_busy/buddha","你正在修行無上梵功\，暫時不能移動。");
           me->map_skill("force","buddha-force");
           me->start_busy(2);
           me->skill_active( "buddha-force",(: call_other, __FILE__, "delay", me:), 2);
           return 1;
        }

//轉AP化HP

        if(arg=="heal" )
        {
//        if(me->is_busy() )
//                return notify_fail("你正忙著....\n");
        if( me->query_skill_mapped("force")=="buddha-force" ) 
                return notify_fail("你正在修行無上梵功\。\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("你現在正在忙。\n");
        if(me->query("ap") < heal*10/25 ) 
                return notify_fail("你目前的身體狀況，不能使用療傷功\能。\n");
        if(me->query("hp") >= me->query("max_hp"))
                     return notify_fail("你現在並沒有受傷哦。\n");
        message_vision(HIR "$N雙手合什，運氣吐納，身上的傷口慢慢恢復了。\n" NOR,me);
        me->receive_damage("ap",heal*10/25);
        
        if (me->is_fighting() ) me->receive_heal("hp",heal);

        else me->receive_heal("hp",heal+heal/2);

        me->start_busy(1);
        me->improve_skill("buddha-force",random(10)+1 );
        return 1;
        }

//「無上金身」

        if(arg=="armor")
        {
                if( me->query_skill_mapped("force")=="buddha-force" ) return notify_fail("你正在修行無上梵功\。\n");
                if (buddha< 20 ) return notify_fail("你的無上梵功\不夠熟練，無法施展「無上金身」。 \n");
                if(me->query("ap") < heal*3/2 ) return notify_fail("你目前的狀態無法施展「無上金身」。\n");
                if(me->query_temp("buddha/armor")==1) return notify_fail("你已經在施展「無上金身」了。\n");

               message_vision(HIW "$N雙手合什，嘴裡唸著佛號，四週氣流狂旋，使出「無上金身」。\n" NOR,me);

                me->add_temp("apply/armor", heal/2);
                me->improve_skill("buddha-force",me->query_int()/4 );
                me->receive_damage("ap",heal*3/2);
                me->set_temp("buddha/armor",1);
                me->start_busy(2);
                me->skill_active( "buddha_force",(: call_other, __FILE__, "armor", me,heal/2:), 500);
                return 1;
        }
        if(!me->is_fighting())
        {
           if(!target) return notify_fail("無上梵功\有heal,armor,on <對方id> (幫別人療傷) 等功\能。\n");
           if(target==me) return notify_fail("你只能幫別人療傷，若要自行療傷請用heal。\n");
           if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙，無法使用療傷功\能哦。\n");
           if(me->query_skill("buddha-force") < 20 ) return notify_fail("以你無上梵功\的造詣，是無法幫別人療傷的。\n");
           if(me->query("ap") < heal*10/25 ) return notify_fail("你目前的身體狀況，無法幫別人療傷。\n");
           if(!userp(target)) return notify_fail("你只能對玩家使用療傷功\能哦。\n");

	   message_vision(HIC"$N運氣於雙掌，拍打$n胸口數下，只見$n吐出了幾口黑血。\n"NOR,me,target);
           message_vision(HIW"$N身上傷口慢慢恢復了。\n" NOR,target);

           target->receive_heal("hp",heal);
           me->improve_skill("buddha-force",random(10)+1);
           me->start_busy(1);
           me->receive_damage("ap",heal/3);

           return 1;
        } else return notify_fail("你現在正在忙著戰鬥。\n");
        return notify_fail("無上梵功\有heal,armor,等功\能。\n");
}
void armor(object me,int effect)
{
        if(!me) return;
        if(!me->query_temp("buddha/armor") ) return;
      message_vision(HIG "$N的四週氣流突然停止，$N的無上金身散功\了。\n"NOR,me);
        me->add_temp("apply/armor",-effect);
        me->delete_temp("buddha/armor");
        return;
}

void delay(object me)
{
        if ( !me 
        ||   !me->query_temp("is_busy/buddha")
        ||    me->query_skill_mapped("force")!="buddha-force"
        ||    me->is_fighting() )
        {
                me->map_skill("buddha-force");
                return;
        }

        if(me->query("hp") < 10 || me->query("ap") < 10 )
        {
                message_vision("$N站起身來，停止了修行無上梵功\。\n",me);
                me->delete_temp("is_busy/buddha");
                me->map_skill("force");
                return;
        }       

        if (!me->query("linwin/forceok") && me->query_skill("buddha-force",1)==85 && me->query("evil") <= (-1000) )
        {
               tell_object(me,HIW "經過長年的修行，你的無上梵功\更上一層了！\n" NOR );
               tell_object(me,HIY "你的力量、體質、智慧和敏捷提高了！\n" NOR );
               me->add("addition/str", 1);
               me->add("addition/con", 1);
               me->add("addition/int", 1);
               me->add("addition/dex", 1);
               me->set("linwin/forceok",1);
        }
        else {
     me->improve_skill("buddha-force",me->query_int()/3+random(6)+3);
     me->improve_skill("force",me->query_int()/3+random(6)+5);
        }

            me->receive_damage("hp",6);
            me->receive_damage("ap",6);

            me->skill_active( "buddha-force",(: call_other, __FILE__, "delay", me:), 3);

        return;
}

int valid_learn(object me)
{
        return 1;
}
int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b,c;
        b = me->query_skill("buddha-force",1);
        c = me->query("skill/buddha-force");
        
        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me,HIY "你的智慧提高了！\n" NOR );
                        me->add("addition/int", 1);
                }
                else
                {
                        tell_object(me,HIY "你的敏捷提高了！\n" NOR );
                        me->add("addition/dex", 1);
                }
                
                me->set("skill/buddha-force",b);
        }
        me->save();
        return;
}
