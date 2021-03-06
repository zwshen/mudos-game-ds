#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

int HelpMoxibustion()
{

    write(@HELP
      炙穴針灸使用方法:       exert moxibustion <功能> on <某人>

          非戰鬥功能：
          《療氣訣》rekee       消耗內勁點數(AP)來回覆生命點數(HP)
          《療精訣》regin       消耗魔法點數(MP)來回覆內勁點數(AP)
    《療神訣》resen       消耗內勁點數(AP)來回覆魔法點數(MP)
    《善世訣》advkee      消耗內勁點數(AP)來持續性回覆生命點數(HP)
    《�
}
天訣》sky         消耗魔法點數(MP)來回覆全格玩家的內勁點數(AP),生命點數(HP)
《癒民訣》heal        消耗魔法點數(MP)來治癒受傷處
《陰心訣》addint      消耗大量內勁點數(AP)，魔法點數(MP)使智慧(INT)提升
《三焦訣》addcon      消耗大量內勁點數(AP)，魔法點數(MP)使體質(CON)提升
《逸飄訣》adddex      消耗大量內勁點數(AP)，魔法點數(MP)使敏捷(DEX)提升
《太陽訣》addstr      消耗大量內勁點數(AP)，魔法點數(MP)使力量(STR)提升
《鬼陰世精訣》ghost   消耗內勁點數(AP)，魔法點數(MP)，生命點數(HP)使物理攻擊力和物理防禦力提升
戰鬥功能：
《神悲鬼泣訣》attack  消耗大量內勁點數(AP)，魔法點數(MP)對敵人的要穴發出
致命的一擊
HELP);
return 1;
       }

       void ShowMessage(object me, object target, string msg)
       {
           message_vision( msg, me, target);
       }

       void MoxibustionFail(object me, object target, string msg)
       {
           if( target != me )
           {
               msg += HIB "$N"HIB"一個分心，針就插錯了穴位，讓$n"HIB"感到一陣昏厥•\n" NOR;
           }
           else
           {
               msg += HIB "$N"HIB"一個分心，針就插錯了穴位，自己感到一陣昏厥•\n" NOR;
           }
           ShowMessage(me, target, msg);
       }

       void ShowDamage(object me, object target,int damage)
       {
           if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
               tell_object(me,HIY"("+damage+")"NOR);
           if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
               tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
           if(wizardp(me) && me->query("env/debug"))
               tell_object(me, HIR"  ("+damage+")\n"NOR);
       }

       void SkillImporving(object me, int Bonus)
       {
           me -> improve_skill("moxibustion", 1+Bonus);
           me -> improve_skill("acupuncture_cognition", random(Bonus));
       }

       void rekee(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"的臉由蒼白毫無血色，漸而恢復了不少血氣。\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*4/5);
           target -> receive_heal("hp", effect);
       }

       void regin(object me, object target, int effect, string msg)
       {
           msg += HIC"$N"HIC"紊亂的內息似乎有所控制，逐漸穩定了下來。\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("mp", effect*4/5);
           target -> receive_heal("ap", effect);
       }

       void resen(object me, object target, int effect, string msg)
       {
           msg += HIM"精神萎靡不振的$N"HIM"，頓時容光煥發，精神奕奕。\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*4/5);
           target -> receive_heal("mp", effect);
       }

       void advkee(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"蒼白的臉色，因為血氣的運行，漸漸紅潤了起來。\n"NOR ;
           target -> apply_condition("advkee", effect*me->query_tec());
           target -> set_temp("advkee", effect);
       }

       void sky(object me, object target, int effect, string msg)
       {
           object *s_target = all_inventory(environment(me));
           int x,y = sizeof(s_target);
           for(x=0;x<y;x++)
           {
               if( !userp(s_target[x]) || !living(s_target[x]))
                   continue;
               if( s_target[x] == me )
                   continue;
               if( random(me->query_skill("acupuncture_cognition")) > 40 )
               {
                   message_vision("$N感覺到一股氣從「命門穴」及「勞宮穴」衝出，頓時血氣的運行及內息都穩定了不少。", s_target[x]);
                   me -> receive_damage("mp", effect*19*y/20);
                   s_target[x] -> receive_heal("hp", effect);
                   s_target[x] -> receive_heal("ap", effect);
               }
               else
               {
                   message_vision(HIB"$N"HIB"一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR, me, s_target[x]);
                   me -> receive_damage("mp", effect*19*y/20);
                   s_target[x] -> receive_damage("mp", random(20));
                   s_target[x] -> receive_damage("ap", random(20));
               }
           }
           SkillImporving(me, x*(me->query_int()/8));
       }

       void heal(object me, object target, int effect, string msg)
       {
           msg += HIC"$N"HIC"身上的傷口，血漸漸止住了，傷口也以緩慢的的速度慢慢的瘉合起來。\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("mp", effect*5);
           target -> receive_curing("all", effect);
       }

       void addAttribute(object me, object target, int effect, string msg, int x)
       {
           string Attr;
           switch( x )
           {
           case 0:
               msg += HIY"$N"HIY"的身影也漸漸變得高大強壯，肌肉糾結百髯交錯！！\n"NOR ;
               Attr = "str";
               break;
           case 1:
               msg += HIG"$N"HIG"的身體感覺有了些許的改變，似乎強健了不少。\n"NOR ;
               Attr = "con";
               break;
           case 2:
               msg += HIW+BLK"$N"HIW+BLK"忽然覺得整個人沉穩了下來，腦中的思緒似乎更清楚了一些。\n"NOR ;
               Attr = "int";
               break;
           default:
               msg += HIW"$N"HIW"忽然覺得身體的沉重感消失了不少，有種輕飄飄的感覺。\n"NOR ;
               Attr = "dex";
               break;
           }
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*15);
           me -> receive_damage("mp", effect*15);
           target -> start_busy(effect/5);
           target -> set_temp("add"+Attr, effect);
           target -> apply_condition("add"+Attr, effect*me->query_tec());
           target -> add_temp("apply/"+Attr, effect);
           target -> add_temp("e_"+Attr, 1);
       }

       void ghost(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"的手勁忽然增強了些許，對於外界的攻擊也多了不少抵抗能力。\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*18);
           me -> receive_damage("mp", effect*18);
           target -> set_temp("ghost", effect);
           target -> start_busy(effect/5);
           target -> apply_condition("ghost", effect*me->query_tec());
           target -> add_temp("apply/damage", effect);
           target -> add_temp("apply/armor", effect);
           target -> add_temp("d_a_up",1);
       }

       void attack(object me, object target, int damage, string msg)
       {
           int BusyTime, HitRate, DodgeRate;


           damage = (me->query_damage()) * (me->query_tec()/2);
           damage -= target->query_armor();
           damage += random((me->query_int())/25 * me->query_skill("moxibustion"));
           damage = COMBAT_D->Merits_damage(me, target, damage, "tec");
           if( damage < 0 )
               damage = 0;

           HitRate = (me->query_skill("acupuncture_cognition"))*2 + me->query_dex();
           DodgeRate = (target->query_dex())/2 + target->query_skill("acupuncture_cognition");

           if( HitRate > DodgeRate )
           {
               msg += HIB"身上十二個要害的穴位都被寒氣瞬間侵入，頓時無力招架，體內氣勁爆走，五臟六腑都受到嚴重的傷害。"NOR ;
               BusyTime = me->query_tec()/3;
               target -> start_busy(BusyTime);
           }
           else
           {
               msg += CYN"機靈的閃過半數寒氣，但不免還是受到小小的波及。"NOR ;
               damage /= 4;
           }
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", 150);
           me -> receive_damage("mp", 250);
           me -> start_busy(random(2));
           target -> receive_damage("hp", damage);
           target -> receive_damage("ap", damage*4);
           ShowDamage(me, target, damage);
           COMBAT_D->report_status(target);
       }

       int cast_skill(object me, object target, string arg)
       {
           object weapon = me->query_temp("weapon"), *s_target;
           string msg;
           int HitRate, DodgeRate, effect, sk1, sk2, Bonus, x;
           if( !target )
               target = me;
           sk1 = me->query_skill("acupuncture_cognition");
           sk2 = me->query_skill("moxibustion");

           if( arg == "?" || arg == "help" )
               return HelpMoxibustion();

           if( !weapon )
               return notify_fail("你手上沒針是不能施展炙穴針灸的。\n");
           if( weapon->query("skill_type")!="needle" )
               return notify_fail("你手上沒針是不能施展炙穴針灸的。\n");
           if( !target )
               return notify_fail("你沒有可以施展的目標。\n");
           if( me->query("class2") )
           {
               if( target != me && me->query("class2") != "skyowl_med" )
                   return notify_fail("你對別人身上的穴道位置的掌控還不熟練，不能對他人施展此招。\n");
           }
           if( me->is_busy() )
               return notify_fail("你現在正在忙，無法使用炙穴針灸！\n");

           switch( arg )
           {
           case "rekee":
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 5 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 5 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"療氣訣"NOR"》•\n");
               if( target->query("hp") >= target->query("max_hp") )
                   return notify_fail(target->query("name")+"並沒有受傷，似乎不需針灸•\n");

               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"療氣訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"身體上督脈的「命門穴」。\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   rekee(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "regin":
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 5 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 5 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIG"療精訣"NOR"》•\n");
               if( target->query("ap") >= target->query("max_ap") )
                   return notify_fail(target->query("name")+"的內勁充沛，似乎不需針灸•\n");

               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIG"療精訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"手掌上「勞宮穴」。\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   regin(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "resen":
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 5 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 5 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"NOR+MAG"療神訣"NOR"》•\n");
               if( target->query("mp") >= target->query("max_mp") )
                   return notify_fail(target->query("name")+"仍精神亦亦，似乎不需針灸•\n");

               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"NOR+MAG"療神訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"身體上任脈的「神闕穴」。\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   resen(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "advkee":
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 10 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 15 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"善世訣"NOR"》•\n");
               if( target->query("hp") >= target->query("max_hp") )
                   return notify_fail(target->query("name")+"並沒有受傷，似乎不需針灸•\n");
               if( target->query_temp("advkee") )
                   return notify_fail(target->query("name")+"身體內已經有一股暖暖氣流正在緩緩的流動著。\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"善世訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"心臟之後的「神道穴」。\n"NOR ;
               if( random(sk1) > 35 )
               {
                   effect = sk2/2;
                   me -> start_busy(2);
                   Bonus = me->query_int()/4;
                   advkee(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "sky":
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 15 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 30 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIR"開天訣"NOR"》•\n");
               message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIR"開天訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入身邊所有人的「命門穴」及「勞宮穴」。\n"NOR, me, target);
               if( random(sk1) > 45 )
               {
                   effect = sk2;
                   me -> start_busy(2);
                   sky(me, target, effect, msg);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "heal":
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 20 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 40 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"癒民訣"NOR"》•\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"癒民訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"身上的傷口四周。\n"NOR ;
               if( random(sk1) > 45 )
               {
                   effect = sk2/5;
                   me -> start_busy(2);
                   Bonus = me->query_int()/4;
                   heal(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addint":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"的身體已經無法再接受肉體上的強化了。\n");
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 30 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 50 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIW+BLK"陰心訣"NOR"》•\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"BLK"陰心訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"頭頂的「百會穴」。\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 2);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addcon":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"的身體已經無法再接受肉體上的強化了。\n");
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 30 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 50 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIG"三焦訣"NOR"》•\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIG"三焦訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"身體上中下焦三部份。\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 1);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "adddex":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"的身體已經無法再接受肉體上的強化了。\n");
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 30 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 50 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIW"逸飄訣"NOR"》•\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-逸飄訣，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"腿上的「風市穴」。\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 3);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addstr":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"的身體已經無法再接受肉體上的強化了。\n");
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 30 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 50 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIY"太陽訣"NOR"》•\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIY"太陽訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"背部的「長強穴」。\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 0);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "ghost":
               if( target->query_temp("d_a_up") )
                   return notify_fail(target->query("name")+"的身體已經無法再接受肉體上的強化了。\n");
               if( me->is_fighting() )
                   return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
               if( me->query("level") < 30 )
                   return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
               if( sk2 < 55 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HBWHT+BLK"鬼陰世精訣"NOR"》•\n");
               msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HBWHT+BLK"鬼陰世精訣"NOR"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"丹田下「中極穴」、頸下「天突穴」、肩頭「肩井穴」等十二處穴道上。\n"NOR ;
               if( random(sk1) > 65 )
               {
                   effect = sk2/4;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   ghost(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "attack":
               if( target == me )
                   return notify_fail("用 suicide 指令會比較快:P。\n");
               if( sk2 < 70 )
                   return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIR"神悲鬼泣訣"NOR"》•\n");
               if(!me->can_fight(target))
                   return 0;

               if(!me->is_fighting(target))
                   me->kill_ob(target);
               if(!target->is_fighting(me))
                   target->kill_ob(me);

               msg+= HIC"$N"HIC"悟出蒼生萬物死傷輪迴的天地循環真理，神色悲淒。" ;
               msg+=    "\n    隨即一陣狂猛的寒氣自$N"HIC"手中的針鋒竄出，向$n"HIC"十二命門直飆而去！！\n" ;
               Bonus = me->query_int()/2;
               attack(me, target, 1, msg);
               SkillImporving(me, Bonus);

               break;
           }
           return 1;
       }

       int valid_learn(object me)
       {
           return 1;
       }
       int practice_skill(object me)
       {
           return 1;
       }
       int improve_limite(object ob)
       {
           return 100;
       }

