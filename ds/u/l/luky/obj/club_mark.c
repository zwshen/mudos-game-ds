// 幫會信物
// "club/name": 幫會名稱
// "club/level": 玩家在幫會中的等級(1~?)
// 1: 一般幫眾 (隊員)
// 2: 堂主 (分隊長)
// 3: 護法 (大隊長)
// 4: 長老 (參謀長)
// 5: 幫主 (指揮官) 限1名
// "club/title": 幫會頭銜
// "club/info1": 備用區1 (分隊名稱)
// "club/info2": 備用區2
// "club/info3": 備用區3
// "club/info4": 備用區4
// "club/info5": 備用區5
#include <ansi.h>
#define CLUB_NAME "夢幻戰隊"
#define CLUB_CHANNEL "dream"
inherit ITEM;
void create()
{
	set_name(HIC"夢幻戰隊徽章"NOR,({"dream team badge","badge","club_mark"}));
	set_weight(750);
	set("value",0);
	set("no_drop",1);
	set("unit","個");
	set("long",@LONG
這是一個夢幻戰隊隊員的專屬信物, 你可以用(help badge)來查看有什麼幫會指令。

LONG
);
	set("club",CLUB_NAME);
	set("sub_club",({"異型分隊","神族分隊","人類分隊",}));
	setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 if(environment(this_object())!=this_player()) return;
 if(this_player()->query("club/name")!=query("club")) return;
 switch(this_player()->query("club/level"))
 {
  case 5:
		add_action("do_handover","handover");
		add_action("no_suicide","suicide"); //防止幫主自殺
  case 4:
		add_action("do_givepower","givepower");
  case 3:
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 2:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
}

int do_help(string arg)
{
 if(arg=="badge")
 {
  write(@HELP

       �翦�����������������������������������������������������������������
       │                      幫會信物的輔助說明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │說明              │權限        │
       ├───────────────┼─────────┼──────┤
       │  help badge                  │本輔助訊息        │隊員        │
       │  dream <你的訊息>            │夢幻中隊專用頻道  │隊員        │
       │  members                     │列出線上中隊成員  │隊員        │
       │  leaveclub                   │主動退出夢幻戰隊  │隊員        │
       │  include <人名>              │將某人收入分隊    │分隊長專用  │
       │  dismiss <人名>              │取消某人分隊職務  │分隊長專用  │
       │  accept <人名>               │讓某人加入夢幻中隊│大隊長以上  │
       │  kickout <人名>              │將某人逐出夢幻中隊│大隊長以上  │
       │  subleader <人名> to <分隊名>│升級某人為分隊長  │大隊長以上  │
       │  retire <人名>               │撤除某人分隊長職位│大隊長以上  │
       │  givepower <人名> to <等級>  │改變某人的職位    │參謀長以上  │
       │  handover <人名>             │指揮權交接        │指揮官      │
       └───────────────┴─────────┴──────┘

         ◎ 夢幻戰隊目前有三個分隊: 【異型分隊】、【神族分隊】、【人類分隊】
         ◎ 等級分為: <1:隊員> <2:分隊長> <3:大隊長> <4:參謀長> <5:指揮官>

HELP
  );
  return 1;
 }
 return 0;
}

int filter_members(object ppl)
{
        if( !environment(ppl) ) return 0;
        if( ppl->query("club/name")==CLUB_NAME ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 string str;
 level=user->query("level");
 if(level>100) 	str = "【????????】";
 else if(level<11)	str = "【第 "+chinese_number(level)+" 級】";
 else if(level<21) 	str = "【第"+chinese_number(level)+"級】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
 else str = "【"+chinese_number(level)+"級】";
 rank=user->query("club/level");
 switch(rank)
 {
 	case 5: str+=" 夢幻戰隊指揮官 "; break;
 	case 4: str+=" 夢幻戰隊參謀長 "; break;
 	case 3: str+=" 夢幻戰隊大隊長 "; break;
 	case 2: str+=" "+user->query("club/info1")+"分隊長 "; break;
 	default: 
 		if(user->query("club/info1"))
 		{
 			str+=" "+user->query("club/info1")+"隊員   "; break;
 		} else str+=" 夢幻戰隊戰鬥員 ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	if(ob1->query("club/level") == ob2->query("club/level"))
		return  (int)ob1->query("level") - (int)ob2->query("level");
	else return (int)ob1->query("club/level") - (int)ob2->query("club/level");
}

int do_members(string arg)
{
	object *users;
	string str;
	int i,ppl_cnt,idle;
	
	users = filter_array( users(), "filter_members", this_object() );
	str = "◎ 夢幻戰隊: \n";
	str += "─────────────────────────────────────\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			str = sprintf("%s%12s%-16s %s(%s)",
				str,
				show_level(users[i]),
				RANK_D->query_level(users[i]),
				users[i]->name(1),
				users[i]->query("id"),
			);
			if(users[i]->query_temp("killer")) str+=HIR" [殺人犯]"NOR;
			idle=query_idle(users[i]);
			if(users[i]->query_temp("invis")) str+=HIB"(隱形)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<斷線中>"NOR;
			if(idle>60) str +=sprintf(HIY" (發呆%d分鐘)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s目前共有 %d 位隊員在線上.\n", str, ppl_cnt);
	this_player()->start_more(str);
	return 1;
}

int do_include(string arg)
{
	string sub,club;
	object ob,me;
	me=this_player();
	
        if(!arg) return notify_fail("include <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
			if(!sub=me->query("club/info1") || me->query("club/level")!=2) return notify_fail("只有分隊長能將隊員收入分隊\n");
			if(ob->query("club/level") != 1 || ob->query("club/info1"))
				return notify_fail("只有基本隊員可以收入你的分隊。\n");
			ob->set("club/info1",sub);
		 	message_vision("$N將$n收入"+sub+", 並拍拍$n的肩膀說: 今後就看你的表現了。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	string sub,club;
	object ob,me;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
			if(!sub=me->query("club/info1") || me->query("club/level")!=2) return notify_fail("只有分隊長能免除分隊隊員職務\n");
			if(ob->query("club/level") != 1 ) return notify_fail("你不夠資格解除對方的職務。\n");
			if(ob->query("club/info1") != sub) return notify_fail("對方並不屬於你的分隊。\n");
			ob->delete("club/info1");
		 	message_vision("$N解除了$n"+sub+"的職務, 搖搖頭說: 又少了一個人才...真是可惜啊。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_accept(string arg)
{
	string club;
	object ob,mark,me;
	me=this_player();
        if(!arg) return notify_fail("你要讓誰加入戰隊﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
	        if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club==CLUB_NAME) return notify_fail("對方已經是"+CLUB_NAME+"的一份子了。\n");
			else return notify_fail("對方已經加入了別的幫派。\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("幫會信物取得失敗。\n");
		 if( (mark->query_weight()+ob->query_encumbrance())>ob->query_max_encumbrance() )
 		 return notify_fail(ob->name(1)+"拿不動"+mark->query("name")+"。\n");
		 message_vision("$N給了$n一個"+mark->query("name")+", 並隆重的迎接$n成為"+CLUB_NAME+"的一份子。\n",me,ob);
		 ob->set("club/name",CLUB_NAME);
		 ob->set("club/level",1);
		 mark->move(ob);
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string club,*tuned_ch;
	object ob,mark,me;
	me=this_player();
	
        if(!arg) return notify_fail("你要將誰踢出戰隊﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
	        if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
			else 
			{
				if(ob->query("club/level") >= me->query("club/level"))
					return notify_fail("你不夠資格將對方踢出戰隊。\n");
				else
				{
		 			tuned_ch = ob->query("channels");
		 			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
		 			{
		 					tuned_ch -= ({ CLUB_CHANNEL });
							ob->set("channels", tuned_ch);
		 			}
					ob->delete("club");
					if(!mark=present("badge",ob)) return notify_fail("幫會信物取得失敗。\n");
		 			message_vision("$N沒收了$n的"+mark->query("name")+", 並強制$n退出"+CLUB_NAME+"。\n",me,ob);
		 			destruct(mark);
		 			ob->save();
		 			return 1;
				}
			}
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub,club;
	object ob,me,mark;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <人名> to <分隊名>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <分隊名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
			else 
			{
				if(ob->query("club/level") != 1)
					return notify_fail("只有基本隊員可以成為分隊長。\n");
				if( (int) member_array(sub, query("sub_club"))<0 )
					return notify_fail("目前可用的分隊為 <異型分隊> <神族分隊> <人類分隊> \n");
				ob->set("club/level",2);
				ob->set("club/info1",sub);
				if(!mark=present("badge",ob)) return notify_fail("幫會信物取得失敗。\n");
		 		message_vision("$N將$n提昇為"+sub+"分隊長, 並和$n握手勉勵一番。\n",me,ob);
		 		mark->move(ob);
		 		ob->save();
		 		return 1;
			
			}
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub,club;
	object ob,me,mark;
	me=this_player();
	
        if(!arg) return notify_fail("retire <人名> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
			else 
			{
				if(ob->query("club/level") != 2)
					return notify_fail("對象並不是分隊長。\n");
				sub=ob->query("club/info1");
				ob->set("club/level",1);
				ob->delete("club/info1");
				if(!mark=present("badge",ob)) return notify_fail("幫會信物取得失敗。\n");
		 		message_vision("$N免除了$n的"+sub+"分隊長職務。\n",me,ob);
		 		mark->move(ob);
		 		ob->save();
		 		return 1;
			
			}
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,club;
	int level;
	object ob,me,mark;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <人名> to <等級>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <人名> to <等級>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");

			if(ob->query("club/level") >= me->query("club/level"))
				return notify_fail("你沒有資格改變對方的戰隊等級。\n");
			if(level > 4 || level < 1 )
				return notify_fail("目前等級分為 <1:隊員> <2:分隊長> <3:大隊長> <4:參謀長> <5:指揮官> \n");
			switch(level)
			{
				case 1:
					ob->delete("club");
					ob->set("club/name",CLUB_NAME);
					ob->set("club/level",1);
					break;
				case 2:
					return notify_fail("請用subleader指令來指定一個分隊。\n");
					break;
				case 3:
					ob->delete("club");
					ob->set("club/name",CLUB_NAME);
					ob->set("club/level",3);
					break;
				case 4:
					ob->delete("club");
					ob->set("club/name",CLUB_NAME);
					ob->set("club/level",4);
					break;
				case 5:
					return notify_fail("請用handover指令做指揮權移交。\n");
					break;
				default: return notify_fail("參數錯誤。\n");
				
			}

			if(!mark=present("badge",ob)) return notify_fail("幫會信物取得失敗。\n");
			message_vision("$N將$n的戰隊職位等級提昇為"+(string)level+", 並和$n握手勉勵一番。\n",me,ob);
			mark->move(ob);
			ob->save();
			return 1;
			

		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_handover(string arg)
{
	string club;
	object ob,mark,me;
	me=this_player();
        if(!arg) return notify_fail("你要將指揮權移交給誰﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
	        if(!userp(ob)) return notify_fail("這裡有這個人嗎﹖\n");
		if(club=ob->query("club/name"))
		{
			if(club!=CLUB_NAME) return notify_fail("對方並不是"+CLUB_NAME+"的一份子。\n");
		 	
		 	ob->set("club/level",5);
		 	me->set("club/level",4);
		 	ob->delete("club/info1");
		 	me->delete("club/info1");
		 
		 	mark=present("badge", environment(me));
		 	if(!mark) return notify_fail("幫會信物取得失敗。\n");
			mark->move(me);
			mark=present("badge", environment(ob));
		 	if(!mark) return notify_fail("幫會信物取得失敗。\n");
			mark->move(ob);
			message_vision("$N將"+CLUB_NAME+"的總指揮權移交給$n。\n",me,ob);
			message( "channel:dream",CYN"【夢幻戰隊】"+me->name(1)+"("+capitalize(me->query("id"))+")將"+CLUB_NAME+"指揮權移交給"+ob->name(1)+"("+capitalize(ob->query("id"))+")。"NOR, users() );
			ob->save();
			me->save();
			return 1;
		}
		 else return notify_fail("對方並不是"+CLUB_NAME+"的一份子。\n");
	}
	return 1;
}

int do_leaveclub(string arg)
{
	string club,*tuned_ch;
	object mark,me;
	me=this_player();
	
	if(me->query("club/level") == 5)
		return notify_fail("你必須先將指揮權轉移才能離開戰隊。\n");

	if(!mark=present("badge",me)) return notify_fail("幫會信物取得失敗。\n");
	message_vision("$N主動退出了"+CLUB_NAME+"。\n",me);
	message( "channel:dream",CYN"【夢幻戰隊】"+me->name(1)+"("+capitalize(me->query("id"))+")主動退出了夢幻戰隊。"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	destruct(mark);
	me->save();
	return 1;
}

int no_suicide(string arg)
{
	write("身為戰隊最高指揮官, 交出指揮權之前不可輕生, 以免後繼無人。\n");
	return 1;
}