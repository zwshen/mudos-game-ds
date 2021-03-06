// go.c
#include <ansi.h>
#define GO_CMD		"/cmds/std/go"
inherit F_CLEAN_UP;
inherit SSERVER;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string mout, min, dir,who,*busy_type;
	object env, obj,victim,ride,defender,protecter;
         mapping is_busy=([ ]);
          int i = 0;
	if( in_edit(me) || in_input(me) || me->query_temp("Fall_sleep")) return 0;
	if( !arg ) return GO_CMD->main(me,"enter");
	obj = present(arg, environment(me));
	if(!obj) return notify_fail("你要進入哪裡?\n");
	
	if(!obj->is_house())
	{
		dir=obj->query("short");
		notify_fail("你不會想進入"+dir+"的。\n");
		return 0;
	}

	if( me->over_encumbranced() )
		return notify_fail("你的負荷過重﹐動彈不得。\n");

	if( me->is_busy() )
		return notify_fail("你的動作還沒有完成﹐不能移動。\n");
	if(mapp(is_busy=me->query_temp("is_busy")))
	{
		busy_type=keys(is_busy);
		for(i=0;i<sizeof(is_busy);i++)
		{
			if(stringp(is_busy[busy_type[i]])) return notify_fail(is_busy[busy_type[i]]+"\n");
			if(!is_busy[busy_type[i]]) return notify_fail("你暫時無法移動。\n");
		}
	}
        env = environment(me);
        if(!env) return notify_fail("你哪裡也去不了。\n");
	dir=obj->query_short(0);
	if( !env->valid_leave(me, arg) ) return 0;
	if( !obj->valid_enter(me) ) return 0;
	if( me->is_fighting() && victim = offensive_target(me))
	{
		if(
		   victim->visible(me)
		   && !userp(victim)
		   && random(2)
		   && random(victim->query_dex()) > random(me->query_dex()*2+10)
		   && !victim->is_busy()
		   && !victim->is_block()
		)
		{
			me->add_busy(1);
			return notify_fail(HIM"正當你想離開的時候，"+victim->name()+HIM"閃身擋住了你的去路!!!\n"NOR);
		}
		mout = "逃進" + dir + "了。\n";
		if(me->query("race")=="human")
			min = "滿頭大汗, 十分慌張地跑了進來。\n";
		else min = "很狼狽的逃了進來。\n";
		if(victim) 
		{
			tell_object(me,"  【離開時你注意到"+COMBAT_D->status(victim)+"】\n\n");
		}
	} else {
		mout = "進入了" + dir + "。\n";
		if(me->query("race")=="human")
				min = "來到此地。\n";
		else min = "來到此處。\n";

	}
	if(me->query_temp("hide")) me->delete_temp("hide");
	if(me->query_temp("sneak")) me->delete_temp("sneak");
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
	who=me->name();
	ride=me->query_temp("ride");
	if(ride) who=who+"騎著"+ride->name();
	if(me->query_temp("invis") < 1 )
	{
	 	message( "vision", who + mout, environment(me), ({me}) );
	}
	if( me->move(obj) )
	{
		if(env->is_house()) obj->set("exits/exit",env);
		else if(env->is_room()) obj->set("exits/exit",base_name(env));
		me->remove_all_enemy();
		if(me->query_temp("invis")<1)
			message( "vision", who + min, environment(me), ({me}) );
		me->delete_temp("visible_ob");
		me->set_temp("pending", 0);
		return 1;
	}

	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : enter < 建築物 || 運輸工具 >
 
讓你進入某棟建築物或是運輸工具。
 
HELP
    );
    return 1;
}
