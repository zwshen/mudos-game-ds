/*
message_vision()加入以下語句
	object snobj;//監視人
	string *snpkey;
	mapping snp;
	int i;

	snp=environment(me)->query_temp("snp");
	  if (mapp(snp) && sizeof(snp))
	   {  snpkey=keys(snp);
		for (i=0;i<sizeof(snp);i++)
		{snobj=environment(me)->query_temp("snp/"+snpkey[i]);
		tell_object(snobj, ">>>"+str3);
		}
	   }
*/
//修改go.c snoop時不能而動
//if (me->query_temp("snoop"))
//		return notify_fail("你正灰監視中不能而動\n");

/* 為了顯示某某走過來而修改
/adm/simul_efun/message樓�遻婘繙缺�
varargs void view_message(string str, object env, object me )
{
	object snobj;//潼弝��
	string *snpkey;
	mapping snp;
	int i;
	 snp=env->query_temp("snp");
	  if (mapp(snp) && sizeof(snp))
	   {  snpkey=keys(snp);
		for (i=0;i<sizeof(snp);i++)
		{snobj=env->query_temp("snp/"+snpkey[i]);
		tell_object(snobj, ">>>"+str);
		}
	   }
	message("vision",str,env,me);
}
/cmds/std/go.c酕眕狟党蜊
message( "vision", mout, environment(me), ({me}) );
蜊ㄩ	view_message(mout,environment(me),me);
message( "vision", min, environment(me), ({me}) );
蜊ㄩ	view_message(min,environment(me),me);
*/



#include <ansi.h>

inherit ITEM;
void init()
{
	add_action("do_see","see");
	
}
void create()
{
        set_name(HIY "望遠鏡" NOR, ({ "telscope" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {  set("long", "這是一個普通的望遠鏡,你可以用來監視附近的動靜\n"+
				    "�蓧ee south﹝ see none取消監視﹝\n");	
                set("unit", "副");
		   // set("no_drop","這麼好用的東西,不能drop﹝\n");
                set("value", 50000);
                set("material", "gold");
                
        }
        setup();
}

int do_see(string arg)
{	
	mapping exits;
	object env,me;
	me=this_player();
	env = environment(me);
	if (!arg || arg=="") return 0;
	if (arg=="none" )
	if (env=me->query_temp("snoop")) 
	{
	 env->delete_temp("snp/"+me->query("id"));
	 me->delete_temp("snoop");
	 message_vision("$N取消了監視\n",me);
	 remove_call_out("clear_temp");
	 return 1;
	}else return notify_fail("你並沒有監視\n");
	if (me->query_temp("snoop")) return notify_fail("你正在監視呢!\n");
	if (me->query("ap") < 50) return notify_fail("你太累沒有精神監視\n");
			if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			env->set_temp("snp/"+me->query("id"),me);
		else {
			call_other(exits[arg], "???");
			find_object(exits[arg])->set_temp("snp/"+me->query("id"),me);
			}
	message_vision("$N拿起望遠鏡開始監視"+arg+"的動靜\n",me);
	//me->command("look "+arg);
	me->force_me("look "+arg);
	me->set_temp("snoop",env);
	call_out("clear_temp",60,env,me);
	return 1;
	}
	return notify_fail("你要看那裡\n");
}

void clear_temp(object env, object me)
{
	env->delete_temp("snp/"+me->query("id"));
	tell_object(me,"你累啦,休息一會兒吧\n");
	me->delete_temp("snoop");
	me->add("jing",-30);
	

}