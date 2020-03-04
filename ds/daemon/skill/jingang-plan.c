//ª÷­èÃ¹º~°}(jingang-plan.c)  -By Tmr- 2002/1/26
// ¤£°Ê¡B«ã·N¡B¤j¤O¡B©àªá

#include <ansi.h>
#define BASIC 4 //°ò¥»¤H¼Æ
string type() { return "knowledge"; }


inherit SKILL;
inherit SSERVER;

int do_perform(object *obj,object env);

string *attck_msg = ({
        "$N¤@Ánªø¼S¡A±µ³s¤K´x©ç¦V$n¡I¡I\n",
});

string *start_msg = ({
     HIC   "¤Æ°µ¡u¤j¤Oª÷­èÃ¹º~¡v§Î¬Ûªº$Nµo°Ê§ð¶Õ¡I¡I\n" NOR,
     HIC   "¤Æ°µ¡u«ã·Nª÷­èÃ¹º~¡v§Î¬Ûªº$Nµo°Ê§ð¶Õ¡I¡I\n" NOR,
     HIC   "¤Æ°µ¡u©àªáª÷­èÃ¹º~¡v§Î¬Ûªº$Nµo°Ê§ð¶Õ¡I¡I\n" NOR,
     HIC   "¤Æ°µ¡u¤£°Êª÷­èÃ¹º~¡v§Î¬Ûªº$Nµo°Ê§ð¶Õ¡I¡I\n" NOR,
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
                    return notify_fail("§A¨Ã¨S¦³¦b¾Ô°«¡AµLªk¨Ï¥Î³o­Ó°}ªk¡C\n");
      

        if(me->is_busy() )
                return notify_fail("§A¥¿¦£µÛ¡A¨SªÅ§G°}¡C\n");
        t=me->query_team();
        env=environment(me);

        //±qteam ¤¤¡A§ä¥X¥i¥H¨Ï¥Î°}ªkªº¤Hª«
        //¶·ÄY®æ¦b¦¹³]¦n±ø¥ó¡C
        for (i=0;i<sizeof(t);i++)
        {
			ob=t[i];
			// ¤H¼Æ°÷¤F
			if( sizeof(ct)==BASIC ) break;
			// ¨S¦³³o­Ó¤H
			if( !ob ) continue;
			// ¦¹¤H¦£¸L¤¤
			if( ob->is_busy() ) continue;
			// ¤£¦b¦P¤@­Ó©Ð¶¡
			if( env != environment(ob) ) continue;
			// ¤w¸g·Ç³Æµo°Ê°}ªk¤F
			if( ob->query_temp("doing_jingang_plan") )  continue;

                        if( !ob->is_fighting() ) continue;
                        if( !ob->query_skill("jingang-plan") ) continue;
                if( ob->query("ap") < 300 || ob->query("hp") < 300 ) continue;


			ct += ({ob});
			if(wizardp(me) )
				write( ob->query("name")+"("+ob->query("id")+")\n");
        }
        if(sizeof(ct) < BASIC)
			return notify_fail("§A¨S¦³¨¬°÷ªº¶¤¤Í¯à¨Ï¥Î³o­Ó°}ªk¡C\n");
        else 
		{
	        message_vision(HIG "\n$N©¹«á¸õ¥X¤F¾Ô°é¡A°ªÁnªø¼S¡G¡u§G¡yª÷­èÃ¹º~°}¡z¡I¡I¡v\n" NOR,ct[0]);
		    message_vision("$Nµ¥¥|¤HÀH§Y¦û¾Ú¦X¾Aªº¤è¦ì¡A·Ç³Æµo°Ê°}ªk¡I¡I\n",ct[0]);
			for(i=0;i<BASIC;i++)
			{
				ct[i]->start_busy(1);
				ct[i]->set_temp("doing_jingang_plan",1);
			}
			call_out("do_perform",3,ct,env); //¤Þµo°}ªk
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
			message_vision(CYN"¥Ñ©ó¨S¦³¥i¥H§ðÀ»ªº¹ï¹³¡A¾ã­Ó°}ªk°±¤F¤U¨Ó¡C\n" NOR,ct[0]);
			delete_all(ct);
			return 1;
		}
    
        for (i=0;i<sizeof(ct);i++)
        {
        ob=ct[i];
		sk_lv=ob->query_skill("jingang-plan");
		
		// ¨M©w§ðÀ»ªººØÃþ
		if( sk_lv < 25) attack_lv=0;
		else if( sk_lv < 50) attack_lv=1;
		else if( sk_lv < 75) attack_lv=2;
		else attack_lv=3;
		
		// ¶Ã¼Æ¨M©w§ðÀ»ªººØÃþ
		attack_lv=random(attack_lv+1);

        message_vision(start_msg[attack_lv],ob);

	    if(		!ob
                                     )
		{
			message_vision(CYN"$N¨­§Î¤@º¢¡A¾ã­Ó°}ªk°±¤F¤U¨Ó¡C\n"NOR,ob);
			delete_all(ct);
			return 1;
        }

		if( env != environment(ob) )
		{
			tell_object(env,CYN +"¥Ñ©ó"+ob->query("name")+"¤£¦b²{³õ¡A¾ã­Ó°}ªk°±¤F¤U¨Ó¡C\n" NOR);
			delete_all(ct);
			return 1;
		}

		
		// ¦U¤H§ðÀ»target code....
		switch(attack_lv)
		{
			case 0:	// ¤j¤Oª÷­è-ªþ¥[bar
				ob->add_temp("apply/bar",2);
					message_vision(HIB "$Nµo¥X¡u¤j¤Oª÷­è§q¡v¡A¥þ¨­ªº¤O¶q©¿µM¼W±j¤F¼Æ­¿¡I¡I\n" NOR,ob);
					ob->attack();
				ob->add_temp("apply/bar",-2);
				break;
			case 1:	// «ã·Nª÷­è-attack 3 ¦¸
				// ¼W¥[©R¤¤²v
				ob->add_temp("apply/bio",1);
				ob->add_temp("apply/hit",20);
				message_vision(HIR "$N¤âµ²¡u«ã·Nª÷­è¡v¦ò¦L¡Aµn®É§ð¶Õ¼@¼W¡I¡I\n" NOR,ob);
				ob->attack();
				ob->attack();
				ob->attack();
				ob->add_temp("apply/bio",-1);
				ob->add_temp("apply/hit",-20);
				break;
			case 2:	// ©àªáª÷­è-¸É¦å
				message_vision(HIG "$N­±ÅS·L¯º¡A¨³³t¦a¥H¡u©àªáª÷­è«ü¡vÀ°¶¤¤ÍÀø¶Ë¸É¦å¡C\n" NOR,ob);
				for(j=0;j<sizeof(ct);j++)
				{
					ct[j]->receive_heal("hp",200);
					ct[j]->receive_heal("ap",200);
					tell_object(ct[j],CYN "¡]§AÄ±±o¨­¤Wªº¶Ë¶Õ«ì´_¤F¤£¤Ö¡^\n" NOR);
				}
				break;
			case 3:	// ¤£°Êª÷­è- Attack all emeny
				// bonze ¤Þµo¦p¨Ó²Ä¥|¦¡
				/*
				if(ob->query("class2")=="­â¶³¦x" && 
					ob->query_skill("buddha-skill") > 90)	{
					message_vision("¦p¨Ó²Ä¥|¦¡...",ob);
				}
				else 
				*/
				{
					message_vision(HIW "$N§CÀY©À¤F¼Æ¹M¡u¤£°Êª÷­è©G¡v¡Aµn®É¥X²{¤@ÀY¯«Às¡ÐµL¶q¬Û¡I¡I\n" NOR,ob);
					message_vision(@LONG
                                    ¢¨  ¢¨¢©                                   
                                   ¢¨¢i¢¨¢i¢i                                   
                               ¢¨¢i¢i¢i¢i¢i¢i                                   
                       ¢¨¢i¢i¢i¢i¢i¢i¢i¢i  ¢«                                   
                     ¢¨¢i¢«[0;1;5;34m¡[1;5m´[0m ¢¨¢i¢i¢i¢i¢«¢©                                    
              ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«   ¢l                                 
              ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«  ¢l                                
                ¢ª  ¢ª ¢ª ¢i¢i¢i¢i¢i¢i¢«  ¢w ¢l                                 
[0;1;5;31m [1;5m [1;5m [1;5m [1;5m¢[1;5m¨[1;5m¢[1;5mi[1;5m¢[1;5mh[1;5m¢[1;5mg[1;5m¢[1;5mf[1;5m¢[1;5me[1;5m¢[1;5mc[1;5m¢[1;5mb[1;5m¢[1;5mb[1;5m¢[1;5mb[1;5m¢[1;5mb[1;5m¢[1;5mb[0m¢i¢i¢i¢i¢i¢i¢© ¢w ¢l                                
[0;1;5;31m¡[1;5m][1;5m [1;5m [1;5m¢[1;5mª[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mg[1;5m¢[1;5mf[1;5m¢[1;5me[1;5m¢[1;5md[1;5m¢[1;5mc[1;5m¢[1;5mb[1;5m¢[1;5mb[1;5m¢[1;5mb[0m¢i¢i¢ª¢i¢i¢i¢© ¢w ¢l                                
[0;1;5;31m [1;5m [1;5m¡[1;5m^[1;5m¢[1;5m¨[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[0m¢¨¢¨¢¨¢i¢i¢i¢i¢i¢ª ¢w ¢w ¢l                                 
[0;1;5;31m [1;5m [1;5m [1;5m [1;5m¢[1;5mª[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[0m  ¢i¢i¢«¢i  ¢i ¢w ¢w ¢w ¢l                                    
[0;1;5;31m¡[1;5m][1;5m [1;5m [1;5m¢[1;5m¨[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[0m¢«  ¢i¢i¢«  ¢w ¢w ¢w ¢l                                         
[0;1;5;31m [1;5m [1;5m¡[1;5m^[1;5m¢[1;5mª[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5mi[1;5m¢[1;5m«[0m¢ª¢i¢i¢«   ¢i¢i ¢w ¢w ¢w ¢l                                       
                           ¢i¢i ¢w ¢w ¢w ¢l                                     
                           ¢i¢i¢w ¢w ¢w ¢w¢l                                    
                           ¢i¢i ¢w ¢w ¢w  ¢m          

LONG
					,ob);
					message_vision(HIW "$NµL¶q¬Û¤@±i¤f¡A¼Q¥X¤@¹Dª¥¼öºµ¯Pªº¤T¨ý¯u¤õ¿N¦V¼Ä¤H¡I¡I\n" NOR,ob);
                                          for(i=0;i<sizeof(targets);i++)
					{
						if(!ob->can_fight(targets[i]))	//¡@¬O§_¥i§ðÀ»¦¹¹ï¤â
							continue;
						if( random(100) > -COMBAT_D->dodge_factor(targets[i],"dodge") ) // °{Á×¤£¤Î
						{
							targets[i]->receive_damage("hp",200);
							targets[i]->start_busy(1);
							message_vision(RED "$N«zªº¤@ÁnºG¥s¡A³Q¤õ®ü¥]¦í¤F¡I¡I\n" NOR,targets[i]);
						} else {
							message_vision(GRN "$NÅåÀI¦a°k¤F¶}¥h¡I¡I\n" NOR,targets[i]);
						}
					}			
				}
	
				break;
			default:
				message_vision(CYN"$N¨­§Î¤@º¢¡A¾ã­Ó°}ªk°±¤F¤U¨Ó¡C\n"NOR,ob);
                        delete_all(ct);
				return 1;
		}

        if(!ob->is_fighting(target) )   ob->kill_ob(target);
        if(!target->is_fighting(ob) )	target->kill_ob(ob);
		//®ø°£mark
		ob->receive_damage("hp",100);
		ob->receive_damage("mp",100);

		ob->set_temp("doing_jingang_plan",0);
             ob->improve_skill("jingang-plan",random(ob->query_int()));
        }       
                        delete_all(ct);
        return 1;
}


