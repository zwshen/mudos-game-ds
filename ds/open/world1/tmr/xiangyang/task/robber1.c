// Last Modified by winder on Apr. 25 2001
// robber1 for dart
#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{ 
	set_name("蒙古兵士",({"menggu bingshi", "bingshi"}));
	set("long","這是一位侵犯中原的蒙古兵士。\n");
	set("gender", "男性" );
	set("age", random(30)+14);
	
	set("vendetta/authority", 1);
	set("attitude", "peaceful");
	set("bellicosity", 100000);
	set("max_qi", 1000);
	set("eff_qi", 1000);
	set("qi", 1000);
	set("max_jing", 900);
	set("jing", 900);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("shen_type", -10);
	set("combat_exp", 200000);
	set("no_get",1);
	set("quest_no_guard",1);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("get wan dao") :),
		(: command("wield wan dao") :),		
		(: exert_function, "recover" :),		
	}) );
        
        setup();
	carry_object(__DIR__"wandao")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

void do_change(object ob)
{
	object me;
	mapping hp_status, skill_status;
	string *sname;
	int i, temp;
	me = this_object();
	
	skill_status = me->query_skills();
	if ( mapp(skill_status) )
	{
		sname = keys(skill_status);
		temp = sizeof(skill_status);
		for(i=0; i<temp; i++)
		{
			me->delete_skill(sname[i]);
		}
	}

	skill_status = ob->query_skills();
	if ( mapp(skill_status) )
	{
		sname = keys(skill_status);
		temp = skill_status[0];
		for(i=0; i<sizeof(skill_status); i++)
		{
			if (sname[i]=="force") i++;
			if (skill_status[sname[i]] >= temp)
			{
				temp = skill_status[sname[i]];
			}
		}
	}

  me->set_skill("wuhu-duanmendao", temp-random(50));
	me->set_skill("strike",temp);
	me->set_skill("xianglong-zhang",temp-random(50));
	me->set_skill("dodge", temp);
	me->set_skill("shenkong-xing",temp-random(50));
	me->set_skill("blade", temp-random(50));
	me->set_skill("parry", temp);

	me->map_skill("blade","wuhu-duanmendao");
	me->map_skill("parry","wuhu-duanmendao");
	me->map_skill("strike","xianglong-zhang");
	me->map_skill("dodge","shenkong-xing");
	prepare_skill("strike", "xianglong-zhang");

/* copy hp */

	hp_status = ob->query_entire_dbase();
	me->set("str", hp_status["str"]+random(2));
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]+random(2));
	me->set("dex", hp_status["dex"]+random(10));
	me->set("combat_exp",hp_status["combat_exp"]/2);
  if (hp_status["neili"] >=  hp_status["max_neili"]*2)
	me->set("neili", hp_status["neili"]*5);
	if (me->query("max_neili") < hp_status["max_neili"]/2)
	{
		me->set("max_neili",hp_status["max_neili"]/2-1);
		me->set("neili",    hp_status["max_neili"]/2-1);
	}
	me->set("ygjg",ob);
}

void die()
{
	object ob;
	object robber;
	object room;
	ob=query_temp("last_damage_from");
	room = environment(ob);
	ob->start_busy(1);
	if(ob->query_temp("guosc_mis_num")>=0)
	{
		ob->add_temp("guosc_mis_num",1);
	}
       if ((int)ob->query_condition("guosc_mis")>=1 && ob->query_temp("guosc_mis_where")==room->query("short"))
       {  
            switch( random(3) )
	{
		case 0:
			message_vision(HIR"城下又爬上來一個蒙古兵士。\n"NOR,ob);
			robber=new(__DIR__"robber1");
			robber->set("owner",ob->query("id"));
                        robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
		case 1:
			message_vision(HIR"城下又爬上來一個蒙古將領。\n"NOR,ob);
			robber=new(__DIR__"robber2");
			robber->set("owner",ob->query("id"));
                        robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
		case 2:
			message_vision(HIR"城下又爬上來一個蒙古高手。\n"NOR,ob);
			robber=new(__DIR__"robber3");
			robber->set("owner",ob->query("id"));
                        robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
	}	
      }
	message_vision("$N撲在地上掙扎了幾下，口中噴出幾口"HIR"鮮血"NOR"，死了！\n",this_object());
	destruct(this_object());
	return;
}

