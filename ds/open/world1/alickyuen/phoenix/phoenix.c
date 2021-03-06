#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

mapping list = ([]);
string get = "";

int random_go();
string reply_ask();
void auto_kill(object me, object ob);

void create()
{
	set_name(HIR"火鳳凰"NOR, ({ "phoenix" }) );
	set("long",@LONG
在你眼前飛動的這次龐然巨物，就是傳說中的神獸鳳凰。它身上滿是
紅色的羽毛，全身像燃燒著紅色的火焰，非常漂亮。但它為什麼會出
現在這...?
LONG
);
	set("title", HIY"古神獸"NOR );
        set("limbs", ({
		"頭部",	"頸部",	"胸口",	"後心",	"腰間",	"腹部",	"大嘴","尾巴",
	}) );
	set("age", 50000);
	set("level", 70);
	set("exp", 0);
	set("max_hp", 40000);
	set("max_ap", 20000);
	set("max_mp", 20000);
        set("gender","雄性");
        set("race","monster");
        set("addition_armor", 105);
        set("addition_damage", 100);
        set("addition_shield", 10);
        set("Merits/wit", 8);
//        set("chat_chance", 1);
	set("chat_msg", ({
		(: return_home(load_object("/open/world1/cominging/area/boo-lin")) :),
	}));
//        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: random_go :),
       	 }) );
	set("can_speak", 1);
        set("inquiry/勇士", (: reply_ask :) );
	set_temp("fly", 1); 
	//set("fly", 1);
        setup();
        set_temp("apply/armor",200);
        set_temp("apply/shield",200);
        set_temp("apply/damage",150);
	set_living_name("phoenix");
        call_out("test", random(16)+random(16));
	call_out("home", 900);
}

void die()
{
	object ob,env,*item;
	
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	env=environment(this_object());
	if(!env) return;
	item=all_inventory(env);
/*
	if( !ob )
	{
		::die();
		return;
	}
*/
	if( ob )
	{
	message("world:world1:vision",
		HIY"\n\t古神獸"HIW"["HIR"火鳳凰"HIW"]被"+ob->name()+"("+ob->query("id")+")打敗了！\n\n"NOR
	,users());
        ob->add("popularity", 10);
        tell_object(ob, HIY"你得到了 10 點聲望。\n"NOR);
	} else {
	message("world:world1:vision",
                HIY"\n\t古神獸"HIW"["HIR"火鳳凰"HIW"]被打敗了！\n\n"NOR
	,users());
	}
	this_object()->set("hp", this_object()->query("max_hp") );
	this_object()->remove_all_killer();
	this_object()->set("no_kill", 1);
	this_object()->delete("chat_chance");
        this_object()->set("doll", random(2));
	this_object()->delete("can_speak");
	this_object()->query_list();
	command("tchat 嗯,我會實現成功\挑戰過我的勇者的一個願望,請告知你們的願望吧(reward)。");
	call_out("timeout", 60, this_object());
	remove_call_out("test");
	remove_call_out("home");
	remove_call_out("auto_kill");
	return;
}

int receive_damage(string type, int damage, object who)
{
	object plume;

	if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
	if( type!="hp" && type!="mp" && type!="ap" )
		error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
	if( objectp(who) && type=="hp")
	{
		set_temp("last_damage_from", who);
                if( damage > 100 ) 
		{
                        if( userp(who) ) list[who->query("id")] += 1;
			plume = new(__DIR__"plume");
			plume->move(environment(this_object()));
		}
//                if( this_object()->is_busy() && random(10) >= 5 )
                if( !random(2) )
		{
                        message_vision("$N"HIW"察覺到$n的攻擊，突然向$n發出反擊！\n\n"NOR, this_object(), who);
                        this_object()->add("addition_damage", 100);
			this_object()->special_attack(this_object(), who, 200);
                        this_object()->add("addition_damage", -100);
		}
	}

	::receive_damage(type, damage, who);
}

string query_list()
{
	string *id, msg;

	id = keys(list);
	msg = "";
	this_object()->delete("dollcount");
	foreach(string ppl in id)
	{
		msg += ppl+",";
		this_object()->add("dollcount", 1);
	}
	if( this_object()->query("dollcount") == 1 ) this_object()->delete("doll");

	if( sizeof(msg) ) return msg;
	else return "無";
}
void special_attack(object me, object victim, int hitrole) //自訂特攻函數, 給npc用.
   /* special_attack(<obj>攻擊者,<obj>受攻者,<int>命中計算)     */
{
	int damage;

        if( hitrole >= 135 )
	{
                damage = me->query_damage() + random(me->query_damage()) + random(me->query_damage()/4) - victim->query_armor();
		if( damage < 10 ) damage = 10;
                victim->receive_damage("hp", damage , me);
		message_vision("$N"NOR HIY"突然雙翼大力一動，一根羽毛從天而降，直飛插向$n"NOR HIY"的身上。("+damage+")\n"NOR, me, victim);
                victim->receive_wound("head", random(3));
                victim->receive_wound("body", random(3));
                victim->receive_wound("right_arm", random(3));
                victim->receive_wound("left_arm", random(3));
                victim->receive_wound("right_leg", random(3));
                victim->receive_wound("left_leg", random(3));
		me->receive_damage("mp", 20);
		me->receive_damage("ap", 20);
		COMBAT_D->report_status(victim);
		if( !random(10) )
		{
                        message_vision(HIM"\n(一不小心)"HIR"$n給$N"HIR"打飛往幾百米之遠！！！\n\n"NOR, me, victim);
                        if( ( environment(victim) == load_object("/open/world1/cominging/area/boo-lin") ) || random(2) )
			{
				victim->move("/open/world1/tmr/area/hotel");
			} else victim->move("/open/world1/cominging/area/boo-lin");

			victim->start_busy(2);
			victim->remove_killer(me);
			me->remove_killer(victim);
		}
		// else
		if( !random(10) )
		{
			int time;
			time = 5+random(10)+random(10);
			victim->add_temp("conditions/blooding", time);
			victim->apply_condition("blooding", victim->query_condition("blooding") + time);
		}
	} else {
                message_vision("$N"NOR HIY"突然雙翼大力一動，一根羽毛從天而降，直飛插向$n"NOR HIY"的身上。(0)\n"NOR, me, victim);
                message_vision("只見$N狼狽地避開了。\n\n"NOR, victim);
	}
	me->kill_ob(victim);
	return;
}

void init()
{
	object me , ob;
	me = this_player();
	ob = this_object();

	if( !me ) return;

	add_action("do_reward", "reward");

	if( ob->query("no_kill") ) return;

	if( me->is_corpse() ) return;

	if( list[me->query("id")] )
	{
		ob->special_attack(ob, me, 300);
		return ;
	}

        if( (userp(me) && !wizardp(me) && me->query("level") > 30 && !ob->query("no_kill") && environment(me) == environment(ob)) || ( !userp(me) && !me->query("no_kill") ) ) 
		call_out("auto_kill", 1, me, ob);
}

void auto_kill(object me, object ob)
{
	if( ob->query("no_kill") ) return;
	{
//                ob->special_attack(ob, me, random(300));
//                command("kill "+me->query("id"));
                foreach(object item in all_inventory(me))
		{
			if( !item->query_autoload()
                        && strsrch(file_name(item), "open/world") != -1
			&& userp(me) )
				ob->add_temp("attackcheck", 1);
		}
                if( ob->query_temp("attackcheck") || !userp(me) )
		{
		message_vision(HIR"$N"HIR"突然向$n發動攻擊！\n\n"NOR, ob, me);
		ob->kill_ob(me);
		}
	}
	ob->delete_temp("attackcheck");
	return;
}

void timeout(object ob)
{
	if( !ob ) ob = this_object();
	command("tchat 勇士們，我要走了∼");
	command("tchat* bye");
        find_living("phoenix_asker")->clean();
        find_living("phoenix_asker")->delete("pearl");
	destruct(ob);
	return;
}

int do_reward(string arg)
{
	object me;
	string id;

	me = this_player();
	id = this_player()->query("id");

	if( !this_object()->query("no_kill") )
		return 0;

    if( strsrch(get, id) != -1 )
        return notify_fail(this_object()->name()+"說：每人只能受獎一次.\n");

//        if( strsrch(this_object()->query_list(), id) == -1 )
    if( !list[id] ) 
        return notify_fail(this_object()->name()+"說：你並沒有挑戰我成功\。\n");

    if( this_object()->query("dollcount") == 1 )
    {
        message("world:world1:vision", HIW"\t"+me->name()+"("+id+")接受了"+this_object()->name()+HIW"的超級獎勵.\n"NOR, users());
        me->add("popularity", 5);
        me->add("war_art", 10);
        me->add("exp", 100000);
        new("/open/always/phoenix_doll")->move(me);
        me->set("guild_rank", HIW"單挑"HIY"神獸"HIR"鳳凰"HIW"勇士"NOR);
        map_delete(list, id);
        get+=id+", ";
        me->delete_temp("no_quit");
        timeout(this_object());
        return 1;
    }

	switch( arg )
	{
		case "popularity" : 
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")接受了"+this_object()->name()+HIW"的獎勵∼\n"NOR, users());
                        me->add("popularity", 4);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
		case "exp" : 
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")接受了"+this_object()->name()+HIW"的獎勵∼\n"NOR, users());
                        me->add("exp", 40000);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
		case "doll" :
			if( this_object()->query("doll") )
				return notify_fail(this_object()->name()+"說：對不起，doll已經換光了。\n");
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")接受了"+this_object()->name()+HIW"的獎勵∼\n"NOR, users());
              new("/open/always/phoenix_doll")->move(me);
			this_object()->set("doll", 1);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
		default:
		return notify_fail("你可以要以下的獎勵：\n"+
                "(popularity)：聲望４點\n"+
		"(combat)：戰鬥熟練度１５００點\n"+
                "(exp)：經驗值４００００點\n"+
		"(doll)：替死娃娃一隻\n"+
		""NOR);
		break;
		case "combat" :
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")接受了"+this_object()->name()+HIW"的獎勵∼\n"NOR, users());
			me->add("combat_exp", 1500);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
	}


	return 1;
}
int random_go()
{
        object env;
        mapping exits;
        string *dirs;
        env=environment(this_object());
        if(!env) return 0;
        if( !mapp(exits = env->query("exits")) ) return 0;
        if( sizeof(exits) < 1 ) return 0; // 修正房間沒出口時之bug by -Acme-
        dirs = values(exits);
	message_vision(HIW"$N突然不知往那裡飛走了。\n"NOR, this_object());
	this_object()->move(dirs[random(sizeof(dirs))]);
	return 1;
}
void test()
{
	remove_call_out("test");

	random_go();

        call_out("test", 25+random(6));
}
void home()
{
	remove_call_out("home");
	return_home(load_object("/open/world1/cominging/area/boo-lin"));
	call_out("home", 900);
	return;
}

mapping query_ppl()
{
	return list;
}
string reply_ask()
{
	return "暫時挑戰我成功\的勇士: "+this_object()->query_list();
}
