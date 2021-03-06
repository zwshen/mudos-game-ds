#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "玩家競技場");
	set("long",@LONG
這是步靈城中的玩家競技場，在這裡有許多已戰三刻之上的人，看
起來體力還未耗損一半，精神仍然奕奕，在這的西邊是競技場的大廳，
有許多的人士在那歇息，不時也有許多結伴而來練武的武術家，這裡的
四周非常空曠，在十丈之外才有一條條的圍牆圍住這一塊專門比武的場
地。
LONG
	);
	set("exits", ([
  "west" : __DIR__"hippodrome.c",
]));

        set("no_die", 1);
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
}

void init()
{
	add_action("help","help");
	add_action("do_fight","fight");
	add_action("do_another","kill");
	add_action("do_another","quit");
}

int do_another()
{
	write("對不起, 這裡不能做此動作！\n");
	return 1;
}

int do_fight(string arg)
{
	object obj, old_target,me;
	me = this_player();

	if( me->is_ghost() )
		return notify_fail("你現在還是鬼魂吧\n");
	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("這裡禁止戰鬥。\n");
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻擊誰﹖\n");
	if( !obj->is_character() )
		return notify_fail("看清楚一點﹐那並不是生物。\n");
	if( obj->is_fighting(me) )
		return notify_fail("加油﹗加油﹗加油﹗\n");
	if( !living(obj) )
		return notify_fail(obj->name() + "已經無法戰鬥了。\n"); 
        if( obj->is_ghost() )
		return notify_fail("這個人是鬼魂並無法戰鬥。\n");
	if( obj==me )
		return notify_fail("你不能攻擊自己。\n");
	if( userp(me) && !userp(obj) && obj->query_temp("pending/fight")!=me )
		return notify_fail("你只能找玩家比試武藝。\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me )
	{
		message_vision("\n$N對著$n說道﹕" 
			+ RANK_D->query_self(me) 
			+ me->name() + "﹐領教"
			+ RANK_D->query_respect(obj) + "的高招﹗\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比試的念頭。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "如果你願意和對方進行比試﹐請你也對" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
		write(YEL "由於對方是由玩家控制的人物﹐你必須等對方同意才能進行比試。\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") )
	{
		message_vision("\n$N對著$n說道﹕" 
			+ RANK_D->query_self(me) 
			+ me->name() + "﹐領教"
			+ RANK_D->query_respect(obj) + "的高招﹗\n\n", me, obj);
                notify_fail("看起來" + obj->name() + "並不想跟你較量。\n");

		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	}
	else
	{
		message_vision("\n$N大喝一聲﹐開始對$n發動攻擊﹗\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}

	return 1;
}

int help(string arg)
{
	if( arg!="fight" )return 0;
	else write(@HELP
指令格式 : fight <人物名稱>
 
這個指令讓你向一個人物「討教」或者是「切磋武藝」﹐這種形式的戰鬥純粹是
點到為止﹐因此只會消耗體力﹐不會真的受傷﹐但是並不是所有的  NPC 都喜歡
打架﹐因此有許多狀況你的比武要求會被拒絕。

HELP
	);
	return 1;
}
