#include <ansi.h>
#include <dbase.h>
#include <login.h>
int ask_shoucheng()
{
	object *ene;
	object me,ob; 
	object* ob_list;
	int i;
	
	me = this_player();
	ob = this_object();

	if( ob->query("shoucheng_start") )
	{
		tell_object(me,"郭靖對你說道：“剛才救援的英雄已去城門，你看去幫幫忙如何？”\n");
		return 1;
	}
	if(!me->query("family/family_name"))
	{
		tell_object(me,"郭靖對你笑道：“無門無派，不知尊師是誰？”\n");
		return 1;
	}
	if((int)me->query_temp("guosc_mis_flag") > 0 )
	{
		tell_object(me,"郭靖說道：“你不是已有任務了嗎？”\n");
		return 1;
	}
	if ((int)me->query("combat_exp")<100000)
	{
		tell_object(me,"郭靖笑道：“你手無縛雞之力，還是別領任務的為好！”\n");
		return 1;
	}
	if ( (int)me->query_skill("force") < 50 )
	{
		tell_object(me,"郭靖笑道：“守城是件危險工作，我看你的基本內功修為不足，不宜冒險！”\n");
		return 1;
	}
	if ((int)me->query_condition("guosc_mis")>1)
	{
		tell_object(me,"郭靖對你哼了一聲道：“你既已接下重任！怎可輕易擅離職守？快點回你的崗位去！”\n");
		return 1;
	}
	ob->set("shoucheng_start", 1);
	call_out("new_start_scjob",900,ob);
	call_out("guosc_begin",30,me);
	me->set_temp("guosc_mis_flag",1);
	me->set_temp("guosc_mis_num",1);

	ob_list = children("/d/xiangyang/task/wandao");
    for(i=0; i<sizeof(ob_list); i++) 
	{
			destruct(ob_list[i]);
    }
	switch( random(4) )
	{
		case 0:
			me->set_temp("guosc_mis_where","玄武內門");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"郭靖對你叮囑道：“現在蒙古靼子侵犯中原，請閣下速去玄武內門幫助宋軍守城吧！”\n");
			break;
		case 1:
			me->set_temp("guosc_mis_where","青龍內門");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"郭靖對你叮囑道：“現在蒙古靼子侵犯中原，請閣下速去青龍內門幫助宋軍守城吧！”\n");
			break;
		case 2:
			me->set_temp("guosc_mis_where","朱雀內門");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"郭靖對你叮囑道：“現在蒙古靼子侵犯中原，請閣下速去朱雀內門幫助宋軍守城吧！”\n");
			break;
		case 3:
			me->set_temp("guosc_mis_where","白虎內門");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"郭靖對你叮囑道：“現在蒙古靼子侵犯中原，請閣下速去白虎內門幫助宋軍守城吧！”\n");
			break;
	}
	message("channel:sys", HIR"【守衛襄陽城】"+me->query("name")+"申請守衛"+me->query_temp("guosc_mis_where")+"任務。\n"NOR, users());
	return 1;
}

int new_start_scjob()
{ 
   this_object()->delete("shoucheng_start", 1);
}

void guosc_begin(object me)
{
	object *target, robber;
	mapping my_fam = me->query("family");
	int i;
	target = users();
	if ( me->query_temp("guosc_mis_flag") == 1 && (int)me->query_condition("guosc_mis") )
	{
		me->remove_call_out("guosc_begin");
		call_out("guosc_begin",10,me);
		return;
	}
	else if ( me->query_temp("guosc_mis_flag") != 3&& (int)me->query_condition("guosc_mis"))
	{
		if ( environment(me)->query("short")!=me->query_temp("guosc_mis_where") )
		{
			me->remove_call_out("guosc_begin");
			call_out("guosc_begin",10,me);
			return;
		}
		else
		{
			for(i=0;i<sizeof(target);i++)
		{
			if(target[i]->query("family/family_name") == my_fam["family_name"] && target[i]->query("id")!=me->query("id"))
			message("vission",HIR"一只渾身鮮血的鴿子飛到你面前傳給你一張紙條：\n"HIW"�歈�����������������������������������������������������
��          蒙古靼子入侵中原，"+me->query_temp("guosc_mis_where")+"吃緊！          �鱋n�裺����������������������������������������������������� \n                              "+NOR+CYN+me->query("family/family_name")+" "+me->query("name")+"("+me->query("id")+")\n" NOR,target[i]);
		}
			robber=new(__DIR__"robber1");
			robber->do_change(me);
			robber->move(environment(me));
			message_vision(HIR"突然城下爬上來一個蒙古兵士。\n" NOR,me);
			robber->kill_ob(me);
			me->kill_ob(robber);
		}
	}
	else
	{
		me->remove_call_out("guosc_begin");
	}
}

int job_over(string arg)
{
	int job_pot,job_exp;
	object me = this_player();

	if(!arg) return 1;

	if(arg!="over") return 1;
	if(!me->query_temp("guosc_mis_flag"))
	{
		tell_object(me,"郭靖對你哼了一聲道：“你根本沒領任務，也來邀功？”\n");
		return 1;
	}
	if(me->query_temp("guosc_mis_flag")!=3)
	{
		tell_object(me,"郭靖對你哼了一聲道：“任務還沒完成，也來邀功？”\n");
		return 1;
	}
	if(me->query_temp("guosc_mis_num")<3)
	{
		tell_object(me,"郭靖對你哼了一聲道：“你殺了幾個敵人，你還來領賞？”\n");
		me->delete_temp("guosc_mis_flag");
		me->delete_temp("guosc_mis_num");
		me->delete_temp("guosc_mis_where");
		return 1;
	}
	if(me->query_temp("guosc_mis_flag")==3)
	{
		tell_object(me,"郭靖拍了拍你的肩膀說道：“為國殺敵，不錯不錯！”\n");
		job_exp=((int)me->query_temp("guosc_mis_num"))*150;
		job_pot=job_exp*1/3;
		job_exp=job_exp;
		if (job_exp>4000) 
			job_exp=4000+(job_exp-4000)/10;
		if (job_pot>1300) 
			job_pot=1300+(job_pot-1300)/2;
    if (job_pot>job_exp/2)
      job_pot=job_exp/2-500;
    log_file("mission/guo_shoucheng",sprintf("%-20s 守城殺了%3i個蒙古兵，獲得%-5i 經驗 %-5i 潛能\n",me->query("name")+"("+me->query("id")+")",me->query_temp("guosc_mis_num"),job_exp,job_pot));
		me->add("combat_exp", job_exp);
		me->add("potential",job_pot);
	me->set_temp("prize_reason","守城");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",job_exp);
	me->set_temp("prize_pot",job_pot);
		tell_object(me, HIW"你被獎勵了"+chinese_number(job_exp)+"點經驗值，"+chinese_number(job_pot)+"點潛能。\n"NOR);
		me->delete_temp("guosc_mis_flag");
		me->delete_temp("guosc_mis_num");
		me->delete_temp("guosc_mis_where");
		this_object()->delete("shoucheng_start", 1);
		return 1;
	}
}
