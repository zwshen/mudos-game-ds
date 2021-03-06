// consider cmds
// changed By Tmr 2002/04/10
// merits-based damage -tmr 2007/07/23
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob,me_weapon,ob_weapon;
          int opp_damage,me_damage,me_hit,ob_hit,me_def,opp_def;
        string output,me_attack_skill,ob_attack_skill;
        
        seteuid(getuid(me));
 
        if(!arg)
                return notify_fail("你要評估誰的強度﹖\n");
        ob = present(arg, environment(me));
        if(!ob) 
                return notify_fail("這裡沒有你要評估的對象。\n");
        if(!me->visible(ob))
                return notify_fail("這裡沒有你要評估的對象。\n");
        if(!living(ob))
                return notify_fail("這個東西不具威脅性。\n");
        if(ob==me)
                return notify_fail("你自己的狀態你自己最清楚吧。\n");
        if(me->query("mp")<5 )
                return notify_fail("你精神不佳, 無法正確判斷對手的強度。\n");
        me_def=me->query_armor();
        opp_def=ob->query_armor();
        
        //敵人的傷害程度=傷害力-我的抵抗力
        opp_damage = ob->query_damage() - me_def;
        //我的傷害程度 = 傷害力-敵人的抵抗力
        me_damage = me->query_damage() - opp_def;

        if( opp_damage<1) opp_damage = 1+(ob->query("str")<1?1:ob->query("str"))/2;
        if( me_damage<1) me_damage = 1+(me->query("str")<1?1:me->query("str"))/2;
        
        if( objectp(me_weapon=me->query_temp("weapon")) )
                me_attack_skill = me_weapon->query("skill_type");
        else    me_attack_skill = "unarmed";
        if( objectp(ob_weapon=ob->query_temp("weapon")) )
                 ob_attack_skill = ob_weapon->query("skill_type");
        else     ob_attack_skill = "unarmed";
                 
        me_hit = COMBAT_D->attack_factor(me,me_attack_skill);
        me_hit += COMBAT_D->dodge_factor(ob,"dodge");
        me_hit = (150 + me_hit)/3;
        if(me_hit<3) me_hit = 3;
        else if(me_hit>97) me_hit = 97;

        ob_hit=COMBAT_D->attack_factor(ob,ob_attack_skill);
        ob_hit+=COMBAT_D->dodge_factor(me,"dodge");
        ob_hit=(150+ob_hit)/3;
        if(ob_hit<3) ob_hit=3;
        else if(ob_hit>97) ob_hit=97;
                
        output = sprintf("你仔細地評估了%s(%s)"NOR"的強度之後發現：\n\n", ob->name(),  ob->query("id") );
        output = sprintf("%s 你對%s(%s)"NOR"的命中率: %5d%%    對方對你的命中率: %5d%% \n",
                        output, ob->name(), ob->query("id"), me_hit, ob_hit);
        output = sprintf("%s 你能造成%s(%s)"NOR"的獸性傷害: %5d    對方對你的獸性傷害: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "bar"), COMBAT_D->Merits_damage(ob, me, opp_damage, "bar") );
        output = sprintf("%s 你能造成%s(%s)"NOR"的生物傷害: %5d    對方對你的生物傷害: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "bio"), COMBAT_D->Merits_damage(ob, me, opp_damage, "bio") );
        output = sprintf("%s 你能造成%s(%s)"NOR"的魔法傷害: %5d    對方對你的魔法傷害: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "wit"), COMBAT_D->Merits_damage(ob, me, opp_damage, "wit") );
        output = sprintf("%s 你能造成%s(%s)"NOR"的心靈傷害: %5d    對方對你的心靈傷害: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "sou"), COMBAT_D->Merits_damage(ob, me, opp_damage, "sou") );
        output = sprintf("%s 你能造成%s(%s)"NOR"的科技傷害: %5d    對方對你的科技傷害: %5d \n",
                        output, ob->name(), ob->query("id"), COMBAT_D->Merits_damage(me, ob, me_damage, "tec"), COMBAT_D->Merits_damage(ob, me, opp_damage, "tec") );
        output = sprintf("%s 你對%s(%s)"NOR"的暴擊率為: %3d%%    對方對你的暴擊率為: %3d%% \n",
                        output, ob->name(), ob->query("id"), 
                        me->query_hit()-ob->query_hit_against(),
                        ob->query_hit()-me->query_hit_against()
                        );
        
        /*
        if( me_round < 5 )
                output+=HIW+"  對付"+ob->name()+"？！..就憑你？我看是你活的不耐煩了!\n"+NOR; 
        else
        {
                output+="  "+ob->name()+"比起你來，擁有的";
        
                if( me_round< 3)      output+=HIR"戰鬥力非常恐怖，"+NOR;
                else  if(me_round< 5) output+=HIM"戰鬥力十分強大，"+NOR;
                else  if(me_round<11) output+=   "戰鬥力頗強，"; 
                else  if(me_round<20) output+=   "戰鬥力不弱，";
                else  if(me_round<35) output+=   "戰鬥力不強，";
                else                  output+=   "戰鬥並不足以威脅你，";
                
                if( opp_round < 3)     output+=HIG"你應該可以在一瞬間取勝。\n"NOR;
                else  if(opp_round< 5) output+=HIG"你應該可以輕輕鬆鬆地獲勝。\n"NOR;
                else  if(opp_round<11) output+=   "雖然你有相當的勝算，但最好不要輕敵。\n"; 
                else  if(opp_round<20) output+=   "你大概要花一番功\夫才打的贏。\n";
                else  if(opp_round<35) output+=   "你得要有萬全的準備才能取勝。\n";
                else                   output+=   "這將會是很辛苦的一戰。\n";
        }
                */
                output += "\n";
        write(output);
        me->receive_damage("mp", 5);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : consider <對象名稱>

這個指令可以讓你(妳)或評估指定對象(含怪物)的強度。

see also : score
HELP
    );
    return 1;
}


