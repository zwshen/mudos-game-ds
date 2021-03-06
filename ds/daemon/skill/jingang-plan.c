//金剛羅漢陣(jingang-plan.c)  -By Tmr- 2002/1/26
// 不動、怒意、大力、拈花

#include <ansi.h>
#define BASIC 4 //基本人數
string type() { return "knowledge"; }


inherit SKILL;
inherit SSERVER;

int do_perform(object *obj,object env);

string *attck_msg = ({
        "$N一聲長嘯，接連八掌拍向$n！！\n",
});

string *start_msg = ({
     HIC   "化做「大力金剛羅漢」形相的$N發動攻勢！！\n" NOR,
     HIC   "化做「怒意金剛羅漢」形相的$N發動攻勢！！\n" NOR,
     HIC   "化做「拈花金剛羅漢」形相的$N發動攻勢！！\n" NOR,
     HIC   "化做「不動金剛羅漢」形相的$N發動攻勢！！\n" NOR,
});

void delete_all(object* ct)
{
	int i;
	for(i=0;i<sizeof(ct);i++)
                ct[i]->delete_temp("doing_jingang_plan");
}

int form_array(object me)
{
        int i;
        object *t,ob,env;
        object *ct=({});

	if(!me)
			me=this_player();
      if(!me->is_fighting() ) 
                    return notify_fail("你並沒有在戰鬥，無法使用這個陣法。\n");
      

        if(me->is_busy() )
                return notify_fail("你正忙著，沒空佈陣。\n");
        t=me->query_team();
        env=environment(me);

        //從team 中，找出可以使用陣法的人物
        //須嚴格在此設好條件。
        for (i=0;i<sizeof(t);i++)
        {
			ob=t[i];
			// 人數夠了
			if( sizeof(ct)==BASIC ) break;
			// 沒有這個人
			if( !ob ) continue;
			// 此人忙碌中
			if( ob->is_busy() ) continue;
			// 不在同一個房間
			if( env != environment(ob) ) continue;
			// 已經準備發動陣法了
			if( ob->query_temp("doing_jingang_plan") )  continue;

                        if( !ob->is_fighting() ) continue;
                        if( !ob->query_skill("jingang-plan") ) continue;
                if( ob->query("ap") < 300 || ob->query("hp") < 300 ) continue;


			ct += ({ob});
			if(wizardp(me) )
				write( ob->query("name")+"("+ob->query("id")+")\n");
        }
        if(sizeof(ct) < BASIC)
			return notify_fail("你沒有足夠的隊友能使用這個陣法。\n");
        else 
		{
	        message_vision(HIG "\n$N往後跳出了戰圈，高聲長嘯：「佈『金剛羅漢陣』！！」\n" NOR,ct[0]);
		    message_vision("$N等四人隨即佔據合適的方位，準備發動陣法！！\n",ct[0]);
			for(i=0;i<BASIC;i++)
			{
				ct[i]->start_busy(1);
				ct[i]->set_temp("doing_jingang_plan",1);
			}
			call_out("do_perform",3,ct,env); //引發陣法
		}

        return 1;
}

int do_perform(object *ct,object env)
{
		object *targets,ob;
		object target;
         int i,sk_lv,attack_lv;
		int j;
		
		target = offensive_target(ct[0]);
          if( !target || !arrayp(targets = ct[0]->query_enemy()) )
		{
			message_vision(CYN"由於沒有可以攻擊的對像，整個陣法停了下來。\n" NOR,ct[0]);
			delete_all(ct);
			return 1;
		}
    
        for (i=0;i<sizeof(ct);i++)
        {
        ob=ct[i];
		sk_lv=ob->query_skill("jingang-plan");
		
		// 決定攻擊的種類
		if( sk_lv < 25) attack_lv=0;
		else if( sk_lv < 50) attack_lv=1;
		else if( sk_lv < 75) attack_lv=2;
		else attack_lv=3;
		
		// 亂數決定攻擊的種類
		attack_lv=random(attack_lv+1);

        message_vision(start_msg[attack_lv],ob);

	    if(		!ob
                                     )
		{
			message_vision(CYN"$N身形一滯，整個陣法停了下來。\n"NOR,ob);
			delete_all(ct);
			return 1;
        }

		if( env != environment(ob) )
		{
			tell_object(env,CYN +"由於"+ob->query("name")+"不在現場，整個陣法停了下來。\n" NOR);
			delete_all(ct);
			return 1;
		}

		
		// 各人攻擊target code....
		switch(attack_lv)
		{
			case 0:	// 大力金剛-附加bar
				ob->add_temp("apply/bar",2);
					message_vision(HIB "$N發出「大力金剛吼」，全身的力量忽然增強了數倍！！\n" NOR,ob);
					ob->attack();
				ob->add_temp("apply/bar",-2);
				break;
			case 1:	// 怒意金剛-attack 3 次
				// 增加命中率
				ob->add_temp("apply/bio",1);
				ob->add_temp("apply/hit",20);
				message_vision(HIR "$N手結「怒意金剛」佛印，登時攻勢劇增！！\n" NOR,ob);
				ob->attack();
				ob->attack();
				ob->attack();
				ob->add_temp("apply/bio",-1);
				ob->add_temp("apply/hit",-20);
				break;
			case 2:	// 拈花金剛-補血
				message_vision(HIG "$N面露微笑，迅速地以「拈花金剛指」幫隊友療傷補血。\n" NOR,ob);
				for(j=0;j<sizeof(ct);j++)
				{
					ct[j]->receive_heal("hp",200);
					ct[j]->receive_heal("ap",200);
					tell_object(ct[j],CYN "（你覺得身上的傷勢恢復了不少）\n" NOR);
				}
				break;
			case 3:	// 不動金剛- Attack all emeny
				// bonze 引發如來第四式
				/*
				if(ob->query("class2")=="凌雲寺" && 
					ob->query_skill("buddha-skill") > 90)	{
					message_vision("如來第四式...",ob);
				}
				else 
				*/
				{
					message_vision(HIW "$N低頭念了數遍「不動金剛咒」，登時出現一頭神龍－無量相！！\n" NOR,ob);
					message_vision(@LONG
                                    ◢  ◢◣                                   
                                   ◢█◢██                                   
                               ◢██████                                   
                       ◢████████  ◤                                   
                     ◢█◤[0;1;5;34m�[1;5m�[0m ◢████◤◣                                    
              ◢████████████◤   ▍                                 
              ██████████████◤  ▍                                
                ◥  ◥ ◥ ██████◤  ─ ▍                                 
[0;1;5;31m [1;5m [1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mh[1;5m�[1;5mg[1;5m�[1;5mf[1;5m�[1;5me[1;5m�[1;5mc[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[0m██████◣ ─ ▍                                
[0;1;5;31m�[1;5m][1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mg[1;5m�[1;5mf[1;5m�[1;5me[1;5m�[1;5md[1;5m�[1;5mc[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[0m██◥███◣ ─ ▍                                
[0;1;5;31m [1;5m [1;5m�[1;5m^[1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[0m◢◢◢█████◥ ─ ─ ▍                                 
[0;1;5;31m [1;5m [1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[0m  ██◤█  █ ─ ─ ─ ▍                                    
[0;1;5;31m�[1;5m][1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[0m◤  ██◤  ─ ─ ─ ▍                                         
[0;1;5;31m [1;5m [1;5m�[1;5m^[1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5m�[0m◥██◤   ██ ─ ─ ─ ▍                                       
                           ██ ─ ─ ─ ▍                                     
                           ██─ ─ ─ ─▍                                    
                           ██ ─ ─ ─  ▌          

LONG
					,ob);
					message_vision(HIW "$N無量相一張口，噴出一道炙熱熊烈的三味真火燒向敵人！！\n" NOR,ob);
                                          for(i=0;i<sizeof(targets);i++)
					{
						if(!ob->can_fight(targets[i]))	//　是否可攻擊此對手
							continue;
						if( random(100) > -COMBAT_D->dodge_factor(targets[i],"dodge") ) // 閃避不及
						{
							targets[i]->receive_damage("hp",200);
							targets[i]->start_busy(1);
							message_vision(RED "$N哇的一聲慘叫，被火海包住了！！\n" NOR,targets[i]);
						} else {
							message_vision(GRN "$N驚險地逃了開去！！\n" NOR,targets[i]);
						}
					}			
				}
	
				break;
			default:
				message_vision(CYN"$N身形一滯，整個陣法停了下來。\n"NOR,ob);
                        delete_all(ct);
				return 1;
		}

        if(!ob->is_fighting(target) )   ob->kill_ob(target);
        if(!target->is_fighting(ob) )	target->kill_ob(ob);
		//消除mark
		ob->receive_damage("hp",100);
		ob->receive_damage("mp",100);

		ob->set_temp("doing_jingang_plan",0);
             ob->improve_skill("jingang-plan",random(ob->query_int()));
        }       
                        delete_all(ct);
        return 1;
}


