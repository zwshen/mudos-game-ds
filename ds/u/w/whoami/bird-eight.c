#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string *dodge_msg = ({
 HIR"\n突然$n血紅的雙眼放出殺氣，像老鷹一般，嚇的$N不趕靠近$n。\n"NOR,
 "\n$n突然像背後插了雙翅膀一樣的活動迅速，讓$N無從攻擊起。\n",
 "\n$n突然像鴕鳥般的急衝起來，讓$N攻擊的時間大亂，因此避過此招。\n",
 "\n$n閉上雙眼，腦中想著踩石樁陣的情形，腳也踩起石樁陣式，讓$N無從下手。\n",
 "\n$n雙腳一蹬，直衝上天，一式"+HIC+"【驚弓之鳥】"+NOR+"漂亮的落在$N身後。\n",
 "\n突然$n腳步變輕，一招"+HIM+"【返樸歸真】"+NOR+"，在$N的攻勢中遊走四方。\n",
 "\n突然$n放慢了腳步，忽進忽退，使$N完全摸不著頭腦。\n",
 "\n煞那間，$n的雙眼發出異樣的光芒，動作比平常要快上數倍，使$N完全碰不到$n一根寒毛。\n",
});

int exert(object me, object target, string arg)
{
        string msg;

        int temp = me->query_skill("bird-eight"),
            temp2 = me->query_temp("bird/temp");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="bird-eight")
                        return notify_fail("你並沒有使用『靈翼八步訣』。\n");
                me->map_skill("dodge");
                me->reset_action();
                me->add_temp("apply/dodge",- temp2);
                me->delete_temp("bird/temp");
                message_vision("\n"CYN"$N的眼睛慢慢轉為平常的顏色。\n"NOR,me);
                write("技能『靈翼八步訣』已取消。\n");
                return 1;
        }

        if(me->query_skill("dodge")<20) 
                return notify_fail("以你的輕功\基礎無法使用『靈翼八步訣』。\n");

        //錯1. if(me->query_skill_mapped("dodge")=="mirage-steps")
        if(me->query_skill_mapped("dodge")=="bird-eight")  //luky更正
                return notify_fail("你已經在使用『靈翼八步訣』。\n");

        if(me->query("ap")<50 || me->query("hp")<50)
                return notify_fail("你的身體狀無法使用『靈翼八步訣』。\n");

        if(!me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10))
          return notify_fail("你的靈翼八步訣收招動作還沒完成。\n");

        // 錯2. me->map_skill("dodge", "mirage-steps");
        me->map_skill("dodge", "bird-eight"); //luky 更正
        me->reset_action();
        me->add_temp("apply/dodge",temp);
        me->set_temp("bird/temp",temp);
        
message_vision("\n"HIR"$N的雙眼突然轉為血紅色，捕捉敵人的一舉一動，準備使出傳說中的『靈翼八步訣』。\n"NOR,me);
        me->receive_damage("ap",2);
        me->start_busy(1);
        //錯3. call_out("delay",10,me);
        return 1;
}

void delay(object me)
{
        int temp = me->query_temp("bird/temp");
        if(!me) return;
        
        if(me->query_skill_mapped("dodge")!="bird-eight")
        {
                //免. remove_call_out("delay");
                 return;
        }   
        
        if(me->query("ap")<10)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N的眼光漸漸恢復為正常顏色了。\n"NOR,me);
                me->add_temp("apply/dodge",- temp);
                me->delete_temp("bird/temp");
                tell_object(me,"你的體力不足無法繼續使用靈翼八步訣。\n");
                //免. remove_call_out("delay");
                return ;
        }
        if ( me->is_fighting() ) me->receive_damage("ap",2); //沒加戰鬥判斷
        //錯. call_out("delay",10,me);
        me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        int mysk,mydex,myhp,myap,mydo,mylv;
        object me,target;
       
        me   = this_player();
        target = offensive_target(me);
        mylv = target->query("level");
        myhp = target->query("hp");
        myap = target->query("ap"); 
        mysk   = target->query_skill("bird-eight");
        mydo   = target->query_skill("dodge");
        mydex  = target->query("dex"); 

        if( target->query_temp("use_do") < 1 && !target->is_busy() &&            myap > myhp*2/5 && random(mydex) > mylv && (mysk+mydo)/2 > 60 )
        {        
        target->set_temp("use_do",1);
        message_vision(CYN"\n$N"CYN"奇幻的身法讓$n"CYN"的攻擊一時失去了原有的節奏•\n"NOR,target,me); 
        me->start_busy(random(mydex/70+mysk/60)); 
        target->receive_damage("ap",mydex/2+mysk/10); 
        target->delete_temp("use_do");
        }
        return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me) { return 1; }

int improve_limite(object ob) 
{
        int a;
        a=ob->query_dex()+ob->query_int()+40;
        if(a>100) a=100;
        return a;
} 

