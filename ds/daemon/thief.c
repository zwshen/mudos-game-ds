// 現代公會職業信物核心 (小偷公會-Thief)
// 編寫者: Luky 1999.9.5
// Last update by Tmr 2006/11/10
//
#include <weapon.h>
#include <combat.h>
#include <door.h>
#include <box.h>
#include <ansi.h>

mapping default_dirs = ([
                            "north":		"北",
                            "south":		"南",
                            "east":			"東",
                            "west":			"西",
                            "northup":		"北邊",
                            "southup":		"南邊",
                            "eastup":		"東邊",
                            "westup":		"西邊",
                            "northdown":		"北邊",
                            "southdown":		"南邊",
                            "eastdown":		"東邊",
                            "westdown":		"西邊",
                            "northeast":		"東北",
                            "northwest":		"西北",
                            "southeast":		"東南",
                            "southwest":		"西南",
                            "up":			"上",
                            "down":			"下",
                            "enter":		"內",
                            "out":			"外",
                        ]);

void create()
{
    seteuid(getuid());
}

void show_damage(object me,object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
}

int do_backstab(object me,string arg)
{
    object target,weapon;
    int sk,cost;

    if(!me)
        return 0;
    if(!arg)
        return notify_fail("你要偷刺誰﹖\n");
    sk=me->query_skill("backstab");
    cost=5+me->query("level");
    if(!weapon=me->query_temp("weapon"))
        return notify_fail("你沒有拿武器如何背刺?\n");
    if(!weapon->can_stab() )
        return notify_fail(weapon->name()+"並不適合用來背刺。\n");
    if(me->is_busy() || me->is_block())
        return notify_fail("你的上一個動作還沒完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正在戰鬥沒空背刺。\n");
    if(sk<1)
        return notify_fail("你的還沒學過背刺。\n");
    if((int)me->query("ap")< cost )
        return notify_fail("你的精神體力不佳，無法背刺。\n");
    target = present(arg, environment(me));
    if(!target)
        return notify_fail("你要偷刺誰﹖\n");
    if(!living(target) )
        return notify_fail("看清楚一點, 那並不是活的.\n");
    if(!me->can_fight(target))
        return me->can_fight(target);
    if(target->visible(me))
        return notify_fail("對方正注視著你，你沒有機會背刺。\n");
    if(me->query("evil")<-700)
        return notify_fail("你太善良了，不忍心下手。\n");

    if(random(target->query_dex()/4+target->query_skill("perception")/3)
            > random(sk/2+me->query_dex()/3+me->query_temp("hide")*4)
      )
    {
        me->delete_temp("hide");
        message_vision(HIW"$N"HIW"想從背後偷襲$n"HIW"，但是卻被$n"HIW"發現了!!\n"NOR,me,target);
        me->improve_skill("backstab",2+random(2+me->query_int()/10));
        target->kill_ob(me);
        if(me->query_skill("free_action")>49)
            me->add_busy(1); //技能 free_action 用來減少忙碌時間
        else
            me->add_busy(2);
        return 1;
    }
    tell_object(me,HIY"你緊握"+weapon->name()+HIY"，小心翼翼地向"+target->name()+HIY"的背後接近...\n"NOR);
    //	me->receive_damage("mp",cost/2);
    me->receive_damage("ap",cost);
    me->add_busy(1);
    call_out("bs",2,me,target);
    return 1;
}


void bs(object me,object target)
{
    int damage,exp,sk,c;
    int stillhunt_sk;
    object weapon;
    string msg;
    if(!me || !target)
        return;
    if(!weapon=me->query_temp("weapon"))
    {
        tell_object(me,"你臨時卸下武器，放棄了這次的行動。\n");
        return;
    }
    else if(!weapon->can_stab())
    {
        tell_object(me,"你不小心拿錯了武器，放棄了這次的行動。\n");
        return;
    }

    if(environment(me) != environment(target) || !me->visible(target))
    {
        tell_object(me,"你放棄了這次的行動。\n");
        return;
    }
    me->delete_temp("hide");
    sk=me->query_skill("backstab");
    c = target->query_armor();
    damage = me->query_damage()*3+sk;
    if(weapon->query("backstab_bonus")!=0)
        damage = damage*(100+weapon->query("backstab_bonus"))/100;
    
    damage = damage/2+random(damage/2);
    damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
    damage = damage-c/5-random(c/2);
    if(damage < 20)
        damage = 20+random(10);
 //   damage += damage*(me->query("evil")/700);
    exp = damage/2+random(damage/4);
    
    if(damage>200)
        msg=RED"$n"RED"慘叫一聲!! 身上還發出一聲『喀!!』似乎是骨頭碎裂的聲音。"NOR;
    else if(damage > 130)
        msg=HIR"$n"HIR"一聲哀嚎!! 傷口深可見骨。"NOR;
    else if(damage > 60)
        msg=HIM"$n"HIM"大叫一聲!! 鮮血濺了一地。"NOR;
    else
        msg=HIM"痛的$n"HIM"哇哇大叫，幾乎快要昏死過去。"NOR;
    
    me->kill_ob(target);
    target->kill_ob(me);
    message_vision(HIW"\n$N"HIW"突然出現在$n"HIW"的身後，舉起"+weapon->name()+HIW"用力的往$n"HIW"背上刺了下去!!"NOR,me,target);

    show_damage(me,target,damage);
    target->receive_damage("hp",damage,me);
    message_vision("\n"+msg+"\n",me,target);
    COMBAT_D->report_status(target);

    /* 進階背刺 (stillhunt)
     * tmr 2006/11/10
     */
    stillhunt_sk = me->query_skill("stillhunt");
    if( stillhunt_sk >= 1 )
    {
        message_vision(HIY"$N"HIY"偷襲成功\，趁著$n"HIY"身心受損下，又猛刺一下！！"NOR,me,target);
        
        damage = damage*stillhunt_sk/100;
        show_damage(me, target, damage);
        target->receive_damage("hp",damage,me);
        message_vision("\n",me);
        COMBAT_D->report_status(target);
        
        if( stillhunt_sk >= 20 )
            target->start_busy(1);
        if( stillhunt_sk >= 40 )
            target->add_busy(1);
        
        if( stillhunt_sk > 40 ) {
            message_vision(HIR"$N"HIR"趁勢翻絞還在$n"HIR"體內的"
                           +weapon->name() +HIR"，結果造成更大的肉體傷害。\n"NOR,me,target);
            target->receive_wound("body", 4 + random(3));
        }
        if( stillhunt_sk > 60 )
            me->attack();
        if( stillhunt_sk > 80 )
            me->attack();
        if( stillhunt_sk == 100 )
            me->attack();
         me->improve_skill("stillhunt",1+random(me->query_dex()));
    }

    tell_object(me,HIG"你的這次行動得到了"+exp+"點經驗值。\n"NOR);
    me->add("exp",exp);
        me->add("evil", 1 + exp%10 );
    weapon->attack(me,target); 	//武器可能有特攻.
    me->improve_skill("backstab",2+random(me->query_int()/2+me->query("level")/2));
    return;
}
int do_team_backstab(object me,string arg)
{
    object target,weapon,weapon2,*members=({}),*attacker=({});
    int i,k,sk,sk2;
    string false="",me_name,v_name,attacks_name="",temp_name;
    if(!me)
        return 0;
    if(!arg)
        return notify_fail("你要偷刺誰﹖\n");
    sk=me->query_skill("backstab");
    sk2=me->query_skill("organization");
    if(!me->is_team_leader())
        return notify_fail("只有領隊可以下達聯合攻擊命令。\n");
    if(!weapon=me->query_temp("weapon"))
        return notify_fail("你沒有拿武器如何背刺?\n");
    if(!weapon->can_stab() )
        return notify_fail(weapon->name()+"並不適合用來背刺。\n");
    if(me->is_busy() || me->is_block())
        return notify_fail("你的上一個動作還沒完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正在戰鬥沒空背刺。\n");
    if(sk<1)
        return notify_fail("你的還沒學過背刺。\n");
    if(sk2<1)
        return notify_fail("你的團隊行動不夠熟練。\n");
    if(me->query("evil")<-700)
        return notify_fail("你太善良了，不忍心下手。\n");
    if((int)me->query("ap")< 50 || (int)me->query("mp")< 50 )
        return notify_fail("你的精神體力不佳，無法進行聯合背刺。\n");
    target = present(arg, environment(me));
    if(!target)
        return notify_fail("你要偷刺誰﹖\n");
    if(!living(target))
        return notify_fail("看清楚一點, 那並不是活的.\n");
    if(!me->can_fight(target))
        return me->can_fight(target);
    if(target->visible(me))
        return notify_fail("對方正注視著你，你沒有機會背刺。\n");

    members=me->query_team();
    k=0;

    for(i=0;i<sizeof(members) && k<4;i++)
    {
        if(members[i]==me)
            continue;
        if(environment(members[i])!=environment(me))
            continue;
        if(!members[i]->can_fight(target))
        {
            false+=members[i]->name(1)+"無法攻擊敵人。\n";
            continue;
        }
        if(members[i]->is_busy() || members[i]->is_block())
        {
            false+=members[i]->name(1)+"正在忙。\n";
            continue;
        }
        if(members[i]->query_skill("backstab")<1)
        {
            false+="  "+members[i]->name(1)+"沒學過背刺不知道該怎麼做。\n";
            continue;
        }
        if(random(sk2/15+members[i]->query_skill("organization")/10)<1)
        {
            false+="  "+members[i]->name(1)+"似乎沒聽到你的指示。\n";
            continue;
        }
        if(!weapon2=members[i]->query_temp("weapon"))
        {
            false+="  "+members[i]->name(1)+"沒拿武器。\n";
            continue;
        }
        if(!weapon2->can_stab())
        {
            false+="  "+members[i]->name(1)+"拿錯了武器。\n";
            continue;
        }
        if(members[i]->is_fighting())
        {
            false+=members[i]->name(1)+"正忙著戰鬥。\n";
            continue;
        }
        if(members[i]->query("mp")<20 || members[i]->query("ap")<25 )
        {
            false+="  "+members[i]->name(1)+"身體虛弱難以背刺。\n";
            continue;
        }
        if(target->visible(members[i]))
        {
            false+="  "+members[i]->name(1)+"被敵人發現了。\n";
            continue;
        }

        attacks_name+=members[i]->name(1)+"，";
        attacker+=({members[i]});
        k++;
    }

    if(k < 1 )
    {
        if(false!="")
            return notify_fail("你比了一個攻擊的手勢...結果..\n"+false+"\n你只好取消這次攻擊行動。\n");
        else
            return notify_fail("你比了一個攻擊的手勢，但是似乎沒有人注意到你的命令。\n");
    }
    me_name=me->name();
    v_name=target->name();
    tell_object(me,HIY"你比了一個攻擊的手勢，然後小心翼翼地向"+target->name()+HIY"的背後接近...\n"NOR);
    for(i=0;i<sizeof(attacker);i++)
    {
        temp_name = attacks_name;
        temp_name = replace_string( temp_name, attacker[i]->name(1)+"，", "");
        tell_object(attacker[i],me_name+"比了一個攻擊的手勢，"+temp_name+"和你同時悄悄移向"+v_name+"的背後。\n");
        attacker[i]->add_busy(2);
//        attacker[i]->receive_damage("mp",10);
        attacker[i]->receive_damage("ap",20);
    }
    write("(這次的行動總人數為: "+(string)(sizeof(attacker)+1)+" 人。)\n");
  //  me->receive_damage("mp",45);
    me->receive_damage("ap",40);
    me->add_busy(2);
    call_out("team_bs",4,me,target,attacker);
    return 1;
}

void team_bs(object me,object target,object *attacker)
{
      int damage,exp,sk,c,i;
    object weapon;
    string msg;

    if(!me || !target)
        return;
    if(!weapon=me->query_temp("weapon"))
    {
        tell_object(me,"你臨時卸下武器，放棄了這次的行動。\n");
        return;
    }
    if(environment(me) != environment(target) || !me->visible(target))
    {
        tell_object(me,"目標消失了，你只好放棄了這次的行動。\n");
        for(i=0;i<sizeof(attacker);i++)
        {
            tell_object(attacker[i],"目標消失了，你只好放棄了這次的行動。\n");
        }
        return;
    }

    if(target->query_skill("perception")/20+random(target->query_dex()/7)
            > sk/15+random(sk/10+me->query_dex()/4)+me->query_temp("hide")*3
      )
    {
        me->delete_temp("hide");
        message_vision(HIW"$N"HIW"一群人想從背後偷襲$n"HIW"，但是卻被$n"HIW"發現了!!\n"NOR,me,target);
        me->improve_skill("backstab",1+random(1+me->query_int()/10));
        target->kill_ob(me);
        me->add_busy(2-(me->query_skill("free_action")/50)); //技能 free_action 用來減少忙碌時間
        for(i=0;i<sizeof(attacker);i++)
        {
            attacker[i]->delete_temp("hide");
            target->kill_ob(attacker[i]);
            attacker[i]->add_busy(2-(attacker[i]->query_skill("free_action")/50));
        }
    }
    else
    {
        me->delete_temp("hide");
        sk=me->query_skill("backstab");
        c=target->query_armor();
        damage=me->query_damage()*4+sk;
        damage=damage/2+random(damage/3);
        if(weapon->query("backstab_bonus")!=0)
            damage=damage*(100+weapon->query("backstab_bonus"))/100;
        damage=damage-c/4-random(c/5);
        if(damage<20)
            damage=20+random(10);
        damage += damage*(me->query("evil")/700);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
        exp=damage/2;
        if(damage>200)
            msg=RED"$n"RED"慘叫一聲!! 身上還發出一聲『喀!!』似乎是骨頭碎裂的聲音。"NOR;
        else if(damage > 130)
            msg=HIR"$n"HIR"一聲哀嚎!! 傷口深可見骨。"NOR;
        else if(damage > 60)
            msg=HIM"$n"HIM"大叫一聲!! 鮮血濺了一地。"NOR;
        else
            msg=HIM"痛的$n"HIM"哇哇大叫，幾乎快要昏死過去。"NOR;
        message_vision(HIW"\n$N"HIW"突然出現在$n"HIW"的身後，舉起"+weapon->name()+HIW"用力的往$n"HIW"背上刺了下去!!"NOR,me,target);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
        message_vision("\n"+msg+"\n",me,target);
        target->receive_damage("hp",damage,me);
        target->add_busy(2);
        if(target->query("hp") > 0)
            COMBAT_D->report_status(target);
        tell_object(me,HIG"你的這次行動得到了"+exp+"點經驗值。\n"NOR);
        me->add
        ("exp",exp);
        weapon->attack(me,target); //武器可能有特攻.
        me->improve_skill("backstab",1+random(me->query_int()/2+me->query("level")/2));
        me->improve_skill("organization",1+random(me->query_int()/2+me->query("level")));
        me->kill_ob(target);
        if(target->query("hp") > 0)
            target->kill_ob(me);
        message_vision(HIC"\n\n$N"HIC"一擊得手之後，$n"HIC"的身後隨即又竄出幾道黑影!!"NOR,me,target);
        for(i=0;i<sizeof(attacker);i++)
        {
            attacker[i]->delete_temp("hide");
            weapon=attacker[i]->query_temp("weapon");
            if(!weapon)
                continue;
            sk=attacker[i]->query_skill("backstab");
            damage=attacker[i]->query_damage()*4+sk;
            if(weapon->query("backstab_bonus")!=0)
                damage=damage*(100+weapon->query("backstab_bonus"))/100;
            damage=damage/2+random(damage/3);
            damage=damage-c/3-random(c/5);
            if(damage<20)
                damage=20+random(10);
            damage += damage*(attacker[i]->query("evil")/700);
            damage = COMBAT_D->Merits_damage(attacker[i],target,damage,"bar");
            exp=damage/2;
            if(damage>200)
                msg=RED"$n"RED"慘叫一聲!! 身上還發出一聲『喀!!』似乎是骨頭碎裂的聲音。"NOR;
            else if(damage > 130)
                msg=HIR"$n"HIR"一聲哀嚎!! 傷口深可見骨。"NOR;
            else if(damage > 60)
                msg=HIM"$n"HIM"大叫一聲!! 鮮血濺了一地。"NOR;
            else
                msg=HIM"痛的$n"HIM"哇哇大叫，幾乎快要昏死過去。"NOR;
            message_vision(HIW"\n$N"HIW"突然出現在$n"HIW"的身後，舉起"+weapon->name()+HIW"用力的往$n"HIW"背上刺了下去!!"NOR,attacker[i],target);
            if(attacker[i]->query_temp("apply/show_damage") || attacker[i]->query_temp("show_damage") )
                tell_object(attacker[i],HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
            message_vision("\n"+msg+"\n",attacker[i],target);
            target->receive_damage("hp",damage,attacker[i]);
            if(target->query("hp") > 0)
                COMBAT_D->report_status(target);
            tell_object(attacker[i],HIG"你的這次行動得到了"+exp+"點經驗值。\n"NOR);
            attacker[i]->add
            ("exp",exp);
            weapon->attack(attacker[i],target); //武器可能有特攻.
            attacker[i]->improve_skill("backstab",1+random(attacker[i]->query_int()/2+attacker[i]->query("level")/2));
            attacker[i]->improve_skill("organization",1+random(attacker[i]->query_int()/2+attacker[i]->query("level")));
            attacker[i]->kill_ob(target);
            if(target->query("hp") > 0)
                target->kill_ob(attacker[i]);
        }
        return;
    }

    return;
}

int do_sneak(object me,string arg)
{
    object env,obj,ride,defender,protecter;
    string dest, dir,*busy_type;
    mapping exit=([ ]),h_exit=([ ]),is_busy=([ ]);
    int wound=0,i=0,sk,h;

    if( !arg )
        return notify_fail("你要往哪個方向走﹖\n");
    sk=me->query_skill("sneak");
    if(sk<1)
        return notify_fail("你的還沒學過潛行。\n");
    if( me->over_encumbranced() )
        return notify_fail("你的負荷過重，動彈不得。\n");
    if( me->is_fighting() )
        return notify_fail("你正在戰鬥沒空潛行。\n");
    if( me->is_busy() )
        return notify_fail("你的動作還沒有完成。\n");
    if((int)me->query("ap")<10 || (int)me->query("mp")<10 )
        return notify_fail("你的精神體力不佳，無法潛行。\n");
    if(mapp(is_busy=me->query_temp("is_busy")))
    {
        busy_type=keys(is_busy);
        for(i=0;i<sizeof(is_busy);i++)
        {
            if(stringp(is_busy[busy_type[i]]))
                return notify_fail(is_busy[busy_type[i]]+"\n");
            if(!is_busy[busy_type[i]])
                return notify_fail("你暫時無法移動。\n");
        }
    }
    if(ride=me->query_temp("ride"))
        return notify_fail("你正坐在"+ride->name()+"上，無法潛行。\n");
    if(wound = me->query("wound/foot") )
    {
        wound/=10;
        if( wound > 2)
            return notify_fail(HIC"你的雙腳傷勢過重，無法潛行。\n"NOR);
    }
    env = environment(me);
    if(!env)
        return notify_fail("你哪裡也去不了。\n");

    exit = env->query("exits");
    h_exit = env->query("hide_exits");

    if( mapp(exit) && !undefinedp(exit[arg]) )
        ;
    else
        if( !mapp(h_exit) || undefinedp(h_exit[arg]) )
        {
            return notify_fail("這個方向沒有出路。\n");
        }

    if(!mapp(exit))
        dest = h_exit[arg];
    else if( !exit[arg])
        dest = h_exit[arg];
    else
        dest = exit[arg];

    if( !(obj = find_object(dest)) )
        call_other(dest, "???");

    if( !(obj = find_object(dest)) )
        return notify_fail("無法移動。\n");

    if( !env->valid_leave(me, arg) )
        return 0;

    if( !undefinedp(default_dirs[arg]) )
        dir = default_dirs[arg];
    else
        dir = arg;

    if(defender=me->query_temp("defender"))
    {
        defender->delete_temp("protecter");
        me->delete_temp("defender");
    }
    if(protecter=me->query_temp("protecter"))
    {
        protecter->delete_temp("defender");
        me->delete_temp("protecter");
    }
    tell_object(me,"你小心翼翼的開始往"+dir+"潛行。\n");
    if(random(10+sk/5+me->query_dex()/5) < 7 )
        h=0;
    else
        h=1;
    me->set_temp("hide",h);
    me->delete_temp("visible_ob");
    me->receive_damage("ap",3);
//    me->receive_damage("mp",5);
    me->add_busy(2);
    call_out("go_sneak",3,me,obj,env,dir,arg);
    return 1;
}

void go_sneak(object me, object obj,object env,string dir,string arg)
{
    string mout,min;

    if(!me || !obj || !env || !dir)
        return;
    if( me->query_temp("invis") < 1 && me->query_temp("hide") < 1)
    {
        mout = "偷偷的往" + dir + "爬了過去。\n";
        if(me->query("race")=="人類")
            min = "偷偷摸摸的爬了過來。\n";
        else
            min = "悄悄的來到此處。\n";

        message( "vision", me->name() + mout, environment(me), (
                     {
                         me
                     }
                 ) );
    }

    if( me->move(obj) )
    {
        me->remove_all_enemy();
        if(me->query_temp("invis") < 1 && me->query_temp("hide") < 1 )
        {
            message("vision", me->name() + min, environment(me), ({me}) );
            //			all_inventory(env)->follow_me(me, arg);
            //			sneak 失敗, player不能夠follow, by -alickyuen@ds-
            //			以防止player follow thief 靠sneak fail 去一些原本有檔路之地方
            me->add_busy(2);
        }
        else
        {
            tell_object(me,HIG"你悄悄的溜了過來，沒有被人發現。\n"NOR);
            me->improve_skill("sneak",1+random(me->query_int()/2+me->query("level")/2));
        }
        me->set_temp("pending", 0);
        if(random(3)==1)
            me->delete_temp("visible_ob");
        return;
    }

    return ;
}

int do_hide(object me,string arg)
{
    object env;
    int sk,i;
    string *busy_type;
    mapping is_busy=([ ]);

    sk=me->query_skill("hide");
    if(sk<1)
        return notify_fail("你還沒學過埋伏躲藏之術。\n");
    if( me->is_fighting() )
        return notify_fail("你正在戰鬥沒空潛行。\n");
    if( me->is_busy() )
        return notify_fail("你的動作還沒有完成。\n");
    if((int)me->query("ap")<10 || (int)me->query("mp")<10 )
        return notify_fail("你的精神體力不佳，無法躲藏。\n");
    if(mapp(is_busy=me->query_temp("is_busy")))
    {
        busy_type=keys(is_busy);
        for(i=0;i<sizeof(is_busy);i++)
        {
            if(stringp(is_busy[busy_type[i]]))
                return notify_fail(is_busy[busy_type[i]]+"\n");
            if(!is_busy[busy_type[i]])
                return notify_fail("你暫時無法移動。\n");
        }
    }
    if(! env = environment(me) )
        return notify_fail("這裡沒有地方可躲。\n");
    if( env->query("no_hide") )
        return notify_fail("這裡沒有地方可以供你藏身。\n");

    if(!me->query_temp("hide") && me->query_temp("invis"))
        message( "vision", me->name() + "開始找地方躲藏。\n", environment(me), ({me}) );

    tell_object(me,"你閉住呼吸，開始找地方躲藏。\n");

    me->set_temp("is_busy/hide","你正在躲藏。");
    me->receive_damage("ap",2);
//    me->receive_damage("mp",2);
    me->start_busy(2);
    call_out("finish_hide",3,me,sk);
    return 1;
}

void finish_hide(object me,int sk)
{
    int result;
    result=random(9+sk/5);
    me->delete_temp("is_busy/hide");
    me->add_temp("hide",result);
    if(result>5)
    {
        tell_object(me,"你偷偷的躲了起來。\n");
        ROOM_D->moveout(environment(me),me); //add by luky
        me->improve_skill("hide",2+random(me->query_int()/2+me->query("level")/2));
        me->delete_temp("visible_ob");
    }
    if( me->query_temp("hide") > 10)
        me->set_temp("hide",2+random(9));
    me->improve_skill("hide",2+random(1+me->query_int()/2));
}

int sort_item(object ob1, object ob2)
{
    string file1,file2;
    file1=base_name(ob1);
    file2=base_name(ob2);
    if(file1==file2)
    {
        return getoid(ob2)-getoid(ob1);
    }
    return strcmp(file1,file2);
}

int do_peep(object me,string arg)
{

    int i,j,sk;
    object *inv=({}), *obj=({}) ,ob;
    string str;
    if( !arg )
        return notify_fail("你要偷窺誰﹖\n");
    if( me->is_fighting() )
        return notify_fail("你正在戰鬥沒空偷窺。\n");
    if( me->is_busy() )
        return notify_fail("你的動作還沒有完成。\n");
    if((int)me->query("ap")<10 || (int)me->query("mp")<10 )
        return notify_fail("你的精神體力不佳，無法偷窺別人。\n");
    sk=me->query_skill("peep");
    if(sk<1)
        return notify_fail("你的還沒學過偷窺之術。\n");
    ob = present(arg, environment(me));
    if(!ob)
        return notify_fail("這裡沒有這個人。\n");
    if(!me->visible(ob))
        return notify_fail("這裡沒有這個人。\n");
    if( !ob->is_character() )
        return notify_fail(ob->name()+"並不是人。\n"); // add by alick
    me->add_busy(1);
    me->receive_damage("ap",4);
    if(sk/2+random(sk/2) < random(ob->query_skill("perception")))
    {
        tell_object(me,"你想偷窺"+ob->name()+"可是被發現了。\n");
        tell_object(ob,"你突然發現"+me->name()+"想偷窺你。\n");
        me->delete_temp("hide");
        me->add_busy(1);
        if(!userp(ob) && random(ob->query("evil"))>10)
            ob->kill_ob(me);
        return 1;
    }
    tell_object(me,"你開始仔細的觀察"+ob->name()+"...\n你發現");
    obj = all_inventory(ob);
    for(i=0;i<sizeof(obj);i++)
    {
        if(obj[i]->query_temp("riden"))
            continue;
        if(obj[i]->query_temp("invis"))
            continue;
        if(random(2+sk/15))
            inv+=({obj[i]});
    }
    if( !sizeof(inv) )
    {
        write( ob->name() + "身上沒有攜帶任何東西。\n");
        me->improve_skill("peep",1+random(me->query_int()/2));
        return 1;
    }
    inv = sort_array(inv, "sort_item", this_object());
    str="";
    j=1;
    for(i=0; i<sizeof(inv); i++)
    {
        if( i+1 < sizeof(inv) )
        {
            if( inv[i]->query("name") == inv[i+1]->query("name")
                    && inv[i]->query("secured") == inv[i+1]->query("secured")
                    && !inv[i+1]->query("equipped")
                    && !inv[i+1]->query_temp("has_light")
                    && !inv[i]->query_temp("no_combine")
                    && !inv[i+1]->query_temp("no_combine")
              )
            {
                if(inv[i]->query("equipped") || inv[i]->query_temp("has_light"))
                {
                    str += inv[i]->item_describe(0)+"\n";
                }
                else
                    j++;
            }
            else
            {
                if(j>1)		//luky 兩個以上再顯示數量
                {		//luky
                    str += chinese_number(j);
                    str += inv[i]->query("unit")  ? inv[i]->query("unit"):"個";
                }		//luky
                str = sprintf("%s%-32s  \n",str,inv[i]->item_describe(0));
                j = 1;
            }
        }
        else
        {
            if(j>1)		//luky 兩個以上再顯示數量試試
            {		//luky
                str += chinese_number(j);
                str += inv[i]->query("unit")  ? inv[i]->query("unit"):"個";
            }		//luky
            str = sprintf("%s%-32s  \n",str,inv[i]->item_describe(0));
        }
    }


    printf("%s身上帶著下列這些東西﹕         \n"+
           "=========================================\n",
           ob->name(),
          );
    str += "\n";
    me->start_more(str);
    me->improve_skill("peep",1+random(me->query_int()/2+me->query("level")/2));
    return 1;
}

int do_steal(object me,string arg)
{
    string what, who;
    object ob, victim,env;
    int sp, dp, sk, error, cost;

    if(!me)
        return 0;
    if(!living(me))
        return 0;
    if(!env=environment(me))
        return 0;
    if( me->is_busy() )
        return notify_fail("你的動作還沒有完成。\n");
    if( me->is_fighting())
        return notify_fail("你正在作戰，沒空偷東西。\n");
    if( me->query("mp")<10)
        return notify_fail("你精神不佳，無法集中精神偷東西。\n");
    if( me->query("ap")<15)
        return notify_fail("你體力不佳，沒有力量偷別人的東西。\n");
    if( me->query("thief"))
    {
          // adv tf stealing > 70 可免前科限制
          if( me->query("adv_class") == 1 )
                return notify_fail("在你的前科未消除之前，暫時無法偷東西。\n");
           if( me->query_skill("stealing") < 70 )
                return notify_fail("在你的前科未消除之前，暫時無法偷東西。\n");

           // 消除前科
            me->delete("thief");
    }


    //判斷環境
    if( env->query("no_steal") )
        return notify_fail("這裡禁止行竊。\n");
    //是否正在行竊
    if( me->query_temp("stealing") )
        return notify_fail("你已經在找機會下手了﹗\n");
    //指令是否正確
    if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
        return notify_fail("指令格式﹕steal <物品> from <人物>\n");
    //對象是否正確
    victim = present(who, environment(me));
    if(!me->visible(victim))
        return notify_fail("你想行竊的對象不在這裡。\n");
    if( !victim || victim==me)
        return notify_fail("你想行竊的對象不在這裡。\n");
    if( !victim->is_character())
    {
        notify_fail(who+"似乎沒有什麼好偷的。\n");
        return victim->be_stolen(me,what);	//准許物件可以有被偷的動作函式.
    }
    if( victim->is_corpse() )
        return notify_fail("看清楚點？這是屍體耶，直接拿就行了呀！\n"); // add by alick
    if( !wizardp(me) && wizardp(victim) )
        return notify_fail("玩家不能偷巫師身上的東西。\n");
    if( !me->can_fight(victim) || victim->query("no_steal"))
        return notify_fail("似乎有一股力量讓你無法對"+victim->name()+"下手。\n");
    if( victim->is_shopman() )
        return notify_fail("因為Bug之關係，暫時關閉偷當舖的功\能。\n");// alick
    sk=me->query_skill("stealing");
    //偷什麼? 技術不夠可能會偷錯東西..
    if(userp(victim))
    {

        //OK, 開始花點精神找東西吧...

        if( !ob = present(what, victim) )
        {
            //			return notify_fail(" 你實在看不出來" + victim->name() + "的 "+ what + " 放在哪裡。\n");
            return notify_fail("似乎沒有這個東西可偷。\n");
        }

        if( random(20+sk) < 10 )
        {
            me->receive_damage("ap",2);
            me->add_busy(1);
            return notify_fail("你的技巧不夠熟練，手忙腳亂不知該如何下手。\n");
        }
        //偷錯東西囉~~
        if(random(10+sk) < 5)
        {
            object *inv;
            inv = all_inventory(victim);
            if( !sizeof(inv) )
                return notify_fail("你實在看不出來"+ victim->name() + "的 "+what+" 放在哪裡。\n");
            ob = inv[random(sizeof(inv))];
            if( !ob->id(what) )
                error = 1;
        }

         if(ob->query_autoload() || ob->query("no_give") || ob->query("no_steal") || ob->query("no_get") )
            return notify_fail("你不能偷取那樣東西。\n");
        if(ob->query("equipped"))
            return notify_fail("你無法偷取正在裝備中的東西。\n");

        me->receive_damage("ap",5);

        sp = sk * 2 + (int)me->query_dex()*2 + me->query("level") + me->query_temp("hide")*5; //max=200+2*dex
        if( sp < 1 )
            sp = 1;

        dp = (int)victim->query_skill("perception") * 2 + (int)ob->weight()/100 + victim->query("level");
        dp += victim->query_dex()+victim->query_int();
        if( victim->is_fighting() )
            dp /= 2;

        cost=10;
        if(ob->value())
            cost+=5;
        else
            cost+=ob->weight()/1000;
        me->add_busy(3);
        me->receive_damage("ap",cost);
        if(wizardp(me) && me->query("env/debug"))
            write("SP-> "+sp+"  DP->"+dp+"\n");
        write("你悄悄地慢慢靠近" + victim->name() + "，等待機會下手 ...\n\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp , error);
        return 1;
    }
    else
    {
        if(victim->be_stolen(me,what))
            return 1;
        //OK, 開始花點精神找東西吧...
        if( !ob = present(what, victim) )
        {
            if(victim->is_sellman() || victim->is_lottery_npc() )
            {
                mapping list;
                string *file;
                object item;
                int j;

                if(!mapp(list = victim->query("sell_list")) )
                    return notify_fail("你實在看不出來"+ victim->name() + "的 "+what+" 放在哪裡。\n");
                file=keys(list);
                for(j=0;j<sizeof(file);j++)
                {
                    item=new_ob(file[j]);
                    if(item->id(what))
                    {
                        ob=item;
                        break;
                    }
                }

            }
            else if(victim->is_shopman())
            {
                object stroom;
                if(!stroom=load_object(victim->query("storeroom")))
                    return notify_fail("你實在看不出來"+ victim->name() + "的 "+what+" 放在哪裡。\n");
                if( !ob = present(what, stroom) )
                    return notify_fail("你實在看不出來"+ victim->name() + "的 "+what+" 放在哪裡。\n");
            }

            if(!ob)
                return notify_fail("你實在看不出來"+ victim->name() + "的 "+what+" 放在哪裡。\n");

        }

        if(ob->query_autoload() && ob->query("no_drop"))
            return notify_fail("你不能偷取那樣東西。\n");
        if(ob->query("equipped"))
            return notify_fail("你無法偷取正在裝備中的東西。\n");

        //偷錯東西囉~~
        if(random(10+sk) < 5)
        {
            object *inv;
            inv = all_inventory(victim);
            if( !sizeof(inv) )
                return notify_fail("你實在看不出來"+ victim->name() + "的 "+what+" 放在哪裡。\n");
            ob = inv[random(sizeof(inv))];
            if( !ob->id(what) )
                error = 1;
        }

        /*		把improve_skill()部份搬後 by -alickyuen@ds-
        		以免明明player不能Steal東西,也有機會加到戰熟	*/
        if( random(20+sk) < 10 )
        {
            me->receive_damage("ap",2);
            me->add_busy(1);
            me->improve_skill("stealing", me->query_int()/3+random(me->query_int()/2));
            return notify_fail("你的技巧不夠熟練，手忙腳亂不知該如何下手。\n");
        }

//        me->receive_damage("mp",5);

        sp = sk * 2 + (int)me->query_dex() * 2 + me->query("level"); //max=300+2*dex
        if( sp < 1 )
            sp = 1;

        dp = (int)victim->query_skill("perception") + (int)ob->weight()/200 + victim->query("level");
        dp += victim->query_dex()+victim->query_int();
        if( victim->is_fighting() )
            dp /= 2;

        cost=10;
        if(ob->value())
            cost+=5;
        else
            cost+=ob->weight()/1000;
        me->add_busy(3);
        me->receive_damage("ap",cost);
        if(wizardp(me) && me->query("env/debug"))
            write("SP-> "+sp+"  DP->"+dp+"\n");
        write("你悄悄地慢慢靠近" + victim->name() + "，等待機會下手 ...\n\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp , error);
        return 1;
    }
}

void compelete_steal(object me, object victim, object ob, int sp, int dp,int error)
{
    object ob2;
    int amount,total,sk;
    if(!me)
        return;
    me->delete_temp("stealing");
    sk=me->query_skill("stealing");
    if(!victim)
    {
        tell_object(me, "太可惜了，你下手的目標已經走了。\n");
        return;
    }

    if( environment(victim) != environment(me) )
    {
        tell_object(me, "太可惜了，你下手的目標已經走了。\n");
        return;
    }

    if( !living(victim) || (random(sp+dp) > dp) )
    {
        if( total=ob->query_amount() )
        {
            ob2=new_ob(base_name(ob));
            amount=1+(total*sk/300);
            amount+=random(amount/2);
            ob2->set_amount(amount);

            if( !ob2->can_move(me) )
            {
                tell_object(me, "你摸到一" + ob2->query("unit") + ob2->name()
                            + "﹐可是你拿不動，只好放棄。\n");
                return;
            }
            total-=amount;
            ob->set_amount(total);
            ob2->move(me);
            tell_object(me, HIW "得手了﹗\n\n" NOR);
            tell_object(me, "你成功\地偷到一" + ob2->query("unit") + ob2->name() + "﹗\n");
            if( living(victim) )
                me->improve_skill("stealing", me->query_int()/2+random(me->query_int()));
//          if( random(sp) < dp/2 )  // 暫時mark 掉，讓小偷每次偷到東西時，其它人都能看到訊息
                message("vision", "你看到" + me->name() + "鬼鬼祟祟地從"
                        + victim->name() + "身上偷走了一" + ob2->query("unit")
                        + ob2->name() + "﹗\n", environment(me), ({ me, victim }) );
            return;
        }
        else
        {
            if( !ob->can_move(me) )
            {
                tell_object(me, "你摸到一" + ob->query("unit") + ob->name()
                            + "﹐可是你拿不動，只好放棄。\n");
                return;
            }
            ob->move(me);
            ob->set
            ("value",ob->query("value")/5);
            tell_object(me, HIW "得手了﹗\n\n" NOR);
            tell_object(me, "你成功\地偷到一" + ob->query("unit") + ob->name() + "﹗\n");
            if( living(victim) )
                me->improve_skill("stealing", me->query_int()/2+random(me->query_int()));
            if( random(sp) < dp/2 )
                message("vision", "你看到" + me->name() + "鬼鬼祟祟地從"
                        + victim->name() + "身上偷走了一" + ob->query("unit")
                        + ob->name() + "﹗\n", environment(me), ({ me, victim }) );
            return;
        }
    }
    else
    {
        if( random(sp) > dp/2 )
        {
            tell_object(me, victim->name() + "不經意地一轉頭﹐你急忙將手縮了回去﹗\n"
                        "還好﹐沒有被發現。\n");
            me->improve_skill("stealing", 1+me->query_int()/2+random(me->query_int()/2));
            return;
        }
        me->add_busy(5-(me->query_skill("free_action")/30));
        me->add
        ("thief",1);
        tell_object(me, HIR "糟糕﹗你失手了﹗\n\n" NOR);
        me->improve_skill("stealing", me->query_int()/2+random(me->query_int()));
        message_vision("$N一回頭﹐正好發現$n的手正抓著$P身上的" + ob->name() + "﹗\n\n"
                       + "$N喝道﹕「幹什麼﹗」\n\n", victim, me);
        victim->improve_skill("perception", 2+random(victim->query_int()/4));
        //		if( userp(victim) ) victim->fight_ob(me);
        //		else victim->kill_ob(me);
        if(!userp(victim))
        {
            victim->kill_ob(me);
            me->fight_ob(victim);
        }
        return;
    }
}

int do_pick(object me,string arg)
{
    mapping doors;
       string *dirs, dir;
    int i,sk,power;
      object env, obj;

    if( !arg )
        return notify_fail("你要開什麼鎖﹖\n");
    env = environment(me);
    if(!env)
        return 0;
    if(me->is_busy())
        return notify_fail("你的上一個動作還沒完成。\n");
    if(me->query("mp")<10)
        return notify_fail("你精神不佳，無法集中注意力來開鎖。\n");
    if(obj=present(arg, env))
    {
        if(obj->is_box())
        {
            switch(obj->query_cover_status())
            {
            case COVER_NONE :
                return notify_fail(obj->name()+"並沒有地方可以讓你開鎖。\n");
            case COVER_OPENED :
                return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經是開著的啦。\n");
            case COVER_SMASHED :
                return notify_fail(obj->name()+"的"+obj->query("cover_name")+"都已經壞了還開什麼鎖?!\n");
            }
            switch(obj->query_lock_status())
            {
            case LOCK_NONE :
                return notify_fail(obj->name()+"並沒有地方可以讓你開鎖。\n");
            case LOCK_OPENED :
                return notify_fail(obj->name()+"的"+obj->query("cover_name")+"並沒有上鎖。\n");
            case COVER_SMASHED :
                return notify_fail(obj->name()+"的鎖已經壞了無法打開。\n");
            }

            sk=me->query_skill("pick_lock");
            power=random(2+sk/10);
            if(power>9)
                power=9;
            if(power >= obj->query_lock_level())
            {
                if(obj->open_lock())
                {
                    me->add_busy(1);
                    me->receive_damage("ap",5+power);
                    message_vision("『..喀啦!!』$N成功\的將$n的鎖打開了。\n",me,obj);
                    me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                    return 1;
                }
                else
                    return notify_fail("『..啪!!』你似乎把"+obj->name()+"的鎖給弄壞了。\n");
            }
            else
            {
                me->add_busy(1);
                me->receive_damage("ap",5+power);
                message_vision("$N努力的想把$n的鎖打開，但是失敗了。\n",me,obj);
                obj->pick_lock_fail(me,arg); //可以有失敗的代價
                me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
                return 1;
            }
        }
        else
            return notify_fail("那個東西沒有辦法讓你開鎖。\n");
    }

    doors = env->query_doors();
    if( mapp(doors) )
    {
        dirs = keys(doors);
        if( member_array(arg, dirs)!=-1 )
            dir = arg;
        else
            for(i=0; i<sizeof(dirs); i++)
                if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 )
                {
                    dir = dirs[i];
                    break;
                }
        if( !dir )
            return notify_fail("這個方向沒有門。\n");
        //key=env->query_door(dir,"key");
        //if(!key ) return notify_fail("這個門並沒有上鎖!\n");

        if( doors[dir]["status"] == DOOR_SMASHED )
            return notify_fail("這個" + doors[dir]["name"] + "已經壞了。\n");
        if( doors[dir]["status"] == DOOR_OPENED  )
            return notify_fail( doors[dir]["name"] + "已經是開著的了。\n");
        if( !(doors[dir]["status"] == DOOR_LOCKED)  )
            return notify_fail(doors[dir]["name"] + "並沒有上鎖。\n");
        if( env->query("no_pick") )
            return notify_fail(doors[dir]["name"] + "的鎖是特製的你不會開。\n");
        i=env->query("pick_level");
        power=1+random(40+me->query_skill("pick_lock"))-i;
        if(power >= 30)
        {
            if(env->unlock_door(dir))
            {
                me->add_busy(1);
                me->receive_damage("ap",5+power/8);
                message_vision("『..喀.啦!!.』"+"$N成功\的將" + doors[dir]["name"] + "的鎖打開了。\n", me);
                me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                return 1;
            }

        }
        else
        {
            me->add_busy(1);
            me->receive_damage("ap",5+power/8);
            message_vision("$N努力的想把" + doors[dir]["name"] + "的鎖打開，但是失敗了。\n",me);
            env->pick_lock_fail(me,dir); //可以有失敗的代價
            me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
            return 1;
        }
    }
    else
        return notify_fail("這裡沒有門。\n");
    return 0;
}
