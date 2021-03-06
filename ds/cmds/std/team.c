// team.c

#include <ansi.h>

inherit F_CLEAN_UP;
string show_team_member(object me);
int main(object me, string arg)
{
	object *t;
        seteuid(getuid());

	if( !arg ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你現在並沒有參加任何隊伍。\n");
		write(show_team_member(me));
		return 1;
	}
	
	// team dismiss
	if( arg=="dismiss" )
	{
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你現在並沒有參加任何隊伍。\n");
		if( me->is_team_leader() )
		{
			message("team", HIW "【隊伍】" +me->name(1) + "決定將隊伍解散。\n"+NOR, t, me);
			write("你將隊伍解散了。\n");
		}
		 else
		{
			message("team",HIW "【隊伍】" + me->name(1) + "決定脫離隊伍。\n"+NOR, t, me);
			write("你脫離了"+(me->query_team_leader())->name(1)+"的隊伍。\n");
		}
		me->dismiss_team();
		return 1;
	}
	
	// team with <某人>
	if( sscanf(arg, "with %s", arg)==1 )
	{
		object ob,ob_leader;

		if( !(ob = present(arg, environment(me)))
		||	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("你想和誰成為夥伴﹖\n");

		if( ob_leader=ob->query_team_leader() )
		{
			if(ob!=ob_leader)
			return notify_fail("對方已經是 "+ob_leader->name(1)+"小隊 的成員了。\n");
		}

		if( !pointerp(me->query_team()) || me->is_team_leader() ) //沒有隊伍或已經是隊長
		{
		  if( me==(object)ob->query_temp("pending/team") )  //對方邀請過
		  {
			if( !pointerp(me->query_team()) ) //本身沒有隊伍
			{
				ob->add_team_member(me);
				message_vision("$N決定加入$n的隊伍。\n", me, ob);
				
			}
			 else //有隊伍而且是隊長
			{
				me->add_team_member(ob);
				message_vision("$N決定讓$n加入隊伍。\n", me, ob);
			}
			ob->delete_temp("pending/team");
			return 1;
		   }
		   else  //沒有被邀請紀錄
		   {
		   	if(ob==ob_leader)
		   	{
		   	 message_vision("$N希望能加入$n的隊伍。\n", me, ob);
			 tell_object(ob, YEL "如果你願意﹐請用 team with " + me->query("id") + "。\n" NOR);
			 me->set_temp("pending/team", ob); //設定ob為要求對象
			 return 1; 
			}
			
			message_vision("$N邀請$n加入$P的隊伍。\n", me, ob);
			tell_object(ob, YEL "如果你願意加入﹐請用 team with " + me->query("id") + "。\n" NOR);
			me->set_temp("pending/team", ob); //設定ob為要求對象
			return 1;
		   }
		}
		else
		return notify_fail("只有隊伍領袖可以邀請別人加入。\n");
	}
	
	// team talk <訊息>
	if( sscanf(arg, "talk %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) )
			return notify_fail("你現在並沒有和別人組成隊伍。\n");
		message("team", HIW "【隊伍】" + me->name(1) + "﹕" + arg + "\n" NOR, t);

		return 1;
	}

	// team form <陣法>
	if( sscanf(arg, "form %s", arg)==1 )
	{
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("你必須是一個隊伍的領袖才能組織陣形。\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("這種陣形你沒學過。\n");
		return SKILL_D(arg)->form_array(me);
	}
	
	// team attack <陣法>
	if( sscanf(arg, "form %s", arg)==1 )
	{
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("你必須是一個隊伍的領袖才能組織陣形。\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("這種陣形你沒學過。\n");
		return SKILL_D(arg)->form_array(me);
	}
}

string show_team_member(object me)
{
 string str,mark;
 object *t;
 int i=0;
 t = me->query_team();
 str="\n你現在隊伍中的成員有﹕\n\n";
 while(i<sizeof(t))
 {
  if(i==0) mark="[領隊]"; else mark="      ";
  if(t[i]==me) mark+=HIG;
  str+=mark+t[i]->name(1);
  str+="("+t[i]->query("id")+")";
  str+=NOR+"\n";
  i++;
 }
 str+="\n";
 return str;

}

int help(object me)
{
	write(@HELP
隊伍指令使用方法:

team with <某人> - 跟某人組成隊伍. 必須要雙方都同意加入才會生效。
team dismiss     - 離開隊伍. 若下此指令的是領隊, 則整個隊伍會解散。
team talk <訊息> - 跟隊伍裡其他的人談話, 可以用 tt <訊息> 替代。
team form <陣法> - 如果隊伍的領隊學過陣法的話﹐可以將隊伍中的成員組織成
                   某種陣形﹐組成陣形的狀態只要領袖一移動就會解除。

直接下 team 指令時則會顯示你目前是否有加入隊伍及隊員名單。

註: team 跟 follow 是獨立的﹐你不一定要 follow 隊伍的領袖。
HELP
	);
	return 1;
}
