// char.c

// #pragma save_binary
#include <race.h>
#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_FINANCE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_SPELL;
inherit F_TEAM;
inherit F_DEPOT; // add by tmr 2007/04/29 玩家個人倉庫

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
     seteuid(getuid(this_object()));
     set_heart_beat(1);
     tick = 5;
     enable_player();
     CHAR_D->setup_char( this_object() );
}

void heart_beat()
{
         int wimpy_ratio, cnd_flag;
         mapping my;
         object ob;
  


// 暫加 by -Acme-
/*
        if( !wizardp(this_object()) && userp(this_object())  )
        {
                if( !this_object()->query("wiz_test")
                        && (base_name(environment(this_object())))[0..5] !="/open/"
                        && (base_name(environment(this_object())))[0..2] !="/d/"
                )
                {
                        message_vision(HIR"遠方傳來一陣聲音 「 這 裡 不 是 $N 能 來 的 ！！」…\n"NOR,this_object());
                        message_vision("($N嚇得滾出這個地方。)\n",this_object());
                        log_file("nosave/illegal", sprintf("玩家 %s(%s) 非法進出 %s(%s) [%s]。\n",
                                query("name"),
                                query("id"),
                                environment(this_object())->query("short"),
                                base_name(environment(this_object())),
                                ctime(time())));
                        this_object()->move("/open/always/ppl_jail");
                }
                inv = all_inventory(this_object());
                i=sizeof(inv);
                while(i--)
                if( !inv[i]->query_temp("wiz_test") 
                        && (base_name(inv[i]))[0..7] != "/daemon/" 
                        && (base_name(inv[i]))[0..5] != "/open/" 
                        && (base_name(inv[i]))[0..4] != "/obj/"
                        && (base_name(inv[i]))[0..2] != "/d/" )
                {
                        write(HIR"你身上的違法物品["+inv[i]->query("name")+"]化成一陣輕煙消失了…\n"NOR);
                        log_file("nosave/illegal", sprintf("玩家 %s(%s) 非法擁有 %s(%s) [%s]。\n",
                                query("name"),
                                query("id"),
                                inv[i]->query("name"),
                                base_name(inv[i]),
                                ctime(time())));
                                destruct(inv[i]);
                }
        }
*/


	my = query_entire_dbase();
	if(query_temp("continue_damage_decay")) delete_temp("continue_damage_decay");
	// If we're dying or falling unconcious?
	if( my["hp"] < 0 )
	{
		die();
		return;
	}


	// Do attack if we are fighting.
	// 增加一個專門管理戰鬥的block (定義於F_ACTION)
	// 以便使用特技時也可以移動. Luky
	if( is_busy() || is_block() || query_player_cmds())
	{
		continue_action();

		// We don't want heart beat be halt eventually, so return here.
		return;
	}
	 else
	{
		// Is it time to flee?
		if( is_fighting()
		&&	intp(wimpy_ratio = (int)query("wimpy"))
		&&	wimpy_ratio > 0
		&&	(	my["hp"] * 100 / my["max_hp"] <= wimpy_ratio ) )
			GO_CMD->do_flee(this_object());
		// Do attack or clean up enemy if we have fleed.
		attack();
	}
	
	if( my["heart_modify"] > 0 )
	{
		if(undefinedp(my["race"])) error("[Char.c] Heart_beat : 沒有定義種族.(race) \n");
		if(!find_object(RACE_D(my["race"])) && file_size(RACE_D(my["race"])+".c") < 0 )
			error("[Char.c] Heart_beat : 沒有此 race (" + my["race"] + ")\n");
		RACE_D(my["race"])->reset_attribute(this_object());
	 	my["heart_modify"] = 0;
	}
	
        if( tick--  ) return;
                
        if(undefinedp(my["heart_beat_rate"])) my["heart_beat_rate"] = 6;
        if( my["heart_beat_rate"] > 0 ) tick = my["heart_beat_rate"] + random(2);
        else tick = 6 + random(2);
        
        cnd_flag = update_condition();

	// If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P
	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
	&&	!is_fighting() 
	&&	!interactive(this_object())
	&&	!query("chat_chance") //Add by Luky 避免老師停止教書
	&&	!query("schedule") // 避免定時動作停止
	)
	{
		if( environment() )
		{
			ob = first_inventory(environment());
			while(ob && !interactive(ob) )
				ob = next_inventory(ob);
		}
		if( !ob ) set_heart_beat(0);
	}

        // 利用玩家心跳來定時啟動room_effect -Tmr 2006/11/19
    if( environment(this_object()) )
        environment()->room_effect(this_object());

	if( !interactive(this_object()) ) return;

	// Make us a bit older. Only player's update_age is defined.
	// Note: update_age() is no need to be called every heart_beat, it
	//       remember how much time has passed since last call.
	this_object()->update_age();

	if(query_idle(this_object()) > IDLE_TIMEOUT)
		this_object()->user_dump(DUMP_IDLE);
}

int visible(object ob)
{
          int invis=0,detect=0,hide=0;
	object *who=({});
	if(!ob) return 0;
	if(ob==this_object()) return 1;
	if(invis=ob->query_temp("invis") || hide=ob->query_temp("hide"))
	{
		if(userp(this_object()) && wizardp(this_object()))
		{
			if(!userp(ob)) return 1;
			return (wiz_level(this_object())>=wiz_level(ob));
		}
		
		if(hide>invis) invis = hide;
		
		detect=this_object()->query_temp("detect");
		detect+=this_object()->query_temp("apply/detect");
		if(invis > detect)
		{
			who = ob->query_temp("visible_ob");
			if( arrayp(who) && sizeof(who) )
			{
				if(member_array(this_object(),who)!= -1 ) return 1;	
			}	
			return 0;
		}
	}
	return 1;
}


int fall_sleep(int time)
{

	if( !living(this_object()) ) return 0;

//	if( objectp(defeater = query_temp("last_damage_from")) )
//		COMBAT_D->winner_reward(defeater, this_object());

	this_object()->remove_all_enemy();

	message("system", HIR "\n你突然意識模糊，倒在地上昏睡過去....\n\n" NOR,
		this_object());
	this_object()->disable_player_cmds("你正在睡覺，不醒人事。\n");
	//this_object()->disable_player(" <不醒人事>");
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "fall_sleep");
	if(time > 0) call_out("wakeup", time);
	else call_out("wakeup", random(10) + 8);
	return time;
}

int wakeup(int quiet)
{
	remove_call_out("wakeup");
	while( environment()->is_character() )
		this_object()->move(environment(environment()));
//	this_object()->enable_player();
	this_object()->enable_player_cmds();
	if( !quiet )
	{
		COMBAT_D->announce(this_object(), "wakeup");
		set_temp("block_msg/all", 0);
		message("system", HIY "\n慢慢地你漸漸清醒了過來....\n\n" NOR,
			this_object());
		if(wizardp(this_object()) && userp(this_object())) this_object()->set("hp",this_object()->query("max_hp"));
	} else
	{
		set_temp("block_msg/all", 0);
		delete_temp("sleeping");
		this_object()->move(environment());
		//command("look");
	}
	return 1;
}

void water_effect()
{
	object *inv;
	if(!inv=all_inventory(this_object())) return;
	if(sizeof(inv)<1) return;
	inv->water_effect();
	return;
}
