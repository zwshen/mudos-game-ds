// 幫會信物
// "level": 玩家在幫會中的等級(1~?)
// 1: 一般幫眾 
// 2: 堂主 
// 3: 護法 
// 4: 長老 
// 5: 副幫主 (限1名)
// 6: 幫主 (限1名)
// "title": 幫會頭銜
// "info1": 備用區1 (分堂名稱)
// "info2": 備用區2
// "info3": 備用區3
// 大草原 - /open/world1/acme/area/lea3
//燕赤霞說﹕ 可以在這個房間的long 加上你發現這裡的天空有一比平常大的月亮?? :P
// 【閒聊】燕赤霞(Jawei)﹕族長 副族長 長老 旗主 族人
// 【閒聊】龍蝦(Luky)﹕長老以上或是旗主以上
// 【閒聊】燕赤霞(Jawei)﹕幹部我希望是都只有族長能升降...
// 新月 滿月 闇月 半月

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "天地會"
#define CLUB_ID "sky"
#define CLUB_CHANNEL "sky"
#define CLUB_MARK "ring of heaven and earth"

inherit FINGER;
private string *members_level = ({
	"族客", //0
	"幫眾", //1
	"堂員", //2
	"護法", //3
	"舵主", //4
	"總舵主", //5
});
void create()
{
	set_name(HIG"天地指環"NOR,({"ring of heaven and earth","ring","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("material","steel");
		set("club_id",CLUB_ID);
		set("club",CLUB_NAME);
		set("sub_club",({"天罡\堂","地剎堂"}));
		set("value",0);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","只");
		set("long",@LONG
	
此指環乃是天下名匠為天下會創幫，以天下會鎮幫之寶
(天地指環)的外形組做成的，指環透射出碧綠色的光澤
，令你贊嘆該名匠所花的心血。

[關於天地會的其他說明請用<help sky>指令查詢。]
LONG
		);
	}
	set("club_max_level",sizeof(members_level)-1);
	set("armor_prop/shield", 1);
	setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
 	if(wizardp(this_player()))
 	{
 		 info = ([
		 "level": wiz_level(this_player()),
		 "title": "天地會特級顧問  ",
		 "info1": "無",
		 "info2": ctime(time()),
		 "info3": this_player()->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
	}
	else 
	{
 		tell_object(this_player(),this_object()->name()+"突然從你身上飛出，漸漸消失在遠方。\n");
 		this_player()->delete("club");
 		destruct(this_object());
 		return;
 	}
 }
 switch(level)
 {
  case 5:
		add_action("do_handover","handover");
		add_action("do_givepower","givepower");
		add_action("no_suicide","suicide"); //防止自殺
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 4:
  		add_action("do_listmember","listmember");
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
  case 3:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  case 2:
  default:
   		add_action("do_help","help");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
}

int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "【榮譽會員】天地會特級顧問  ";
 level=user->query("level");
 if(level>100) 	str = "【????????】";
 else if(level<11)	str = "【第 "+chinese_number(level)+" 級】";
 else if(level<21) 	str = "【第"+chinese_number(level)+"級】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
 else str = "【"+chinese_number(level)+"級】";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
 	case 5: str+="天地會總舵主    "; break;
 	case 4: str+="天地會舵主      "; break;
 	case 3: str+=info["info1"]+"護法      "; break;
  	case 2: str+=info["info1"]+"堂員      "; break;
 	default: str+="天地會一般幫眾  "; break;
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
	lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
	if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
	else return (lv1 - lv2);
}

int do_members(string arg)
{
	object *users,me;
	string str,*list;
	int i,ppl_cnt,idle;
	me=this_player();
//	list=CLUB_D->club_members(CLUB_ID);
//	users = filter_array( users(), "filter_members", this_object() ,list);
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "◎ "+CLUB_NAME+": \n";
	str += "─────────────────────────────────────\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(!me->visible(users[i]) && wizardp(users[i])) continue;
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
			if(users[i]->query_temp("hide")) str+=HBK"(躲藏)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<斷線中>"NOR;
			if(idle>60) str +=sprintf(HIY" (發呆%d分鐘)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s目前共有 %d 位成員在線上.\n", str, ppl_cnt);
	this_player()->start_more(str);
	return 1;
}

int do_include(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("include <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
			if(me_info["level"] != 3 ) return notify_fail("只有護法能將幫眾收入分堂。\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("只有護法能將幫眾收入分堂。\n");
			if(ob_info["level"] != 1) return notify_fail("只有一般族人可以收入你的分堂。\n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
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
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));		
		if(sizeof(ob_info))
		{
			if(!sub=me_info["info1"] || me_info["level"]!=3 ) return notify_fail("只有護法能免除分堂成員職務。\n");
			if(ob_info["level"] != 2 ) return notify_fail("對方並不屬於你的分堂。\n");
			if(ob_info["info1"] != sub) return notify_fail("對方並不屬於你的分堂。\n");
			ob_info["level"]=1;
			ob_info["info1"]="無";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N解除了$n在"+sub+"的職務, 搖搖頭說: 又少了一個人才...真是可惜啊。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}
//收人
int do_accept(string arg)
{
	string *clubs;
	object ob,mark,me;
	mapping info;
	me=this_player();
        if(!arg) return notify_fail("你要讓誰加入"+CLUB_NAME+"﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
	        if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		if(ob->query_temp("joinclub") != me->query("id") )
		{
			return notify_fail("對方並沒有向你申請入幫(joinclub).\n");
		}
		clubs=CLUB_D->find_player_club(getuid(ob));
		if(sizeof(clubs)>0)
		{
			if(clubs[0]==CLUB_ID) return notify_fail("對方已經是"+CLUB_NAME+"的一份子了。\n");
			else return notify_fail("對方已經加入了別的幫派。\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("幫會信物取得失敗。\n");
		 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"拿不動"+mark->query("name")+"。\n");
		 message_vision("$N給了$n一"+mark->query("unit")+mark->query("name")+", 並隆重的迎接$n成為"+CLUB_NAME+"的一份子。\n",me,ob);
		 info = ([
		 "level": 1,
		 "title": "天地會一般幫眾",
		 "info1": "無",
		 "info2": ctime(time()),
		 "info3": me->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"sky"}));
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string *tuned_ch;
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("你要將誰踢出"+CLUB_NAME+"﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
	        if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"])
				return notify_fail("你不夠資格將對方踢出"+CLUB_NAME+"。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
				return notify_fail("你不夠資格將對方踢出"+CLUB_NAME+"。\n");
 			tuned_ch = ob->query("channels");
 			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
 			{
 				tuned_ch -= ({ CLUB_CHANNEL });
				ob->set("channels", tuned_ch);
 			}
			//ob->delete("club");
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
 				message_vision("$N沒收了$n的"+mark->query("name")+", 並強制$n退出"+CLUB_NAME+"。\n",me,ob);
 				destruct(mark);
 			}
 			CLUB_D->remove_member(CLUB_ID,getuid(ob));
 			ob->save();
 			return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <人名> to <分堂名>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <分堂名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] > 2) return notify_fail("只有一般幫眾或是堂員可以成為護法。\n");
			if( (int) member_array(sub, query("sub_club"))<0 ) return notify_fail("目前可用的分堂為【天罡\堂】、【地剎堂】。\n");
			ob_info["level"]=3;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
	 			message_vision("$N將$n提昇為"+sub+"護法, 並和$n握手勉勵一番。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("retire <人名> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me) return notify_fail("這裡有這個人嗎﹖\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));

		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 3) return notify_fail("對象並不是護法。\n");
			
			sub=ob_info["info1"];
			ob_info["level"]=1;
			ob_info["info1"]="無";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
	 			message_vision("$N免除了$n的"+sub+"護法職務。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,type,res;
	int level;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <人名> to <等級>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <人名> to <等級>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me) return notify_fail("這裡有這個人嗎﹖\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"]) return notify_fail("你沒有資格改變對方的職務等級。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
					return notify_fail("你沒有資格改變對方的職務等級。\n");
			if(level >= me_info["level"])
				return notify_fail("你沒有資格提昇對方的職務等級到這個等級。\n");
			if(level == ob_info["level"])
				return notify_fail("對方已經是"+(string)members_level[level]+"了。\n");
			if(level > 5 || level < 1 )
				return notify_fail("目前等級分為 <1:幫眾> <2:堂員> <3:護法> <4:舵主> <5:總舵主> \n");
			if( level > ob_info["level"] )
			{
				type="提昇";
				res ="並和$n握手勉勵一番";
			}
			else
			{
				type = "降";
				res ="並拍拍$n的肩膀期勉$n能將功\折罪";
			}
			switch(level)
			{
				case 1:
					ob_info["level"]=1;
					ob_info["info1"]="無";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 2:
					return notify_fail("此動作保留給護法專用指令include使用才能指定分堂。\n");
					break;
				case 3:
					return notify_fail("請用subleader指令來指定一個分堂。\n");
					break;
				case 4:
					ob_info["level"]=4;
					ob_info["info1"]="無";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 5:
					return notify_fail("請用handover指令做指揮權移交。\n");
					break;
				default: return notify_fail("參數錯誤。\n");
				
			}
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
				message_vision("$N將$n的職位等級"+type+"為"+(string)members_level[level]+"(等級"+(string)level+"), "+res+"。\n",me,ob);
				mark->move(ob);
			}
			ob->save();
			return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_handover(string arg)
{
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
        if(!arg) return notify_fail("你要將大權移交給誰﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me) return notify_fail("這裡有這個人嗎﹖\n");
		
		if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("你不是真正的幫會領導人。\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
		 	CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
		 	
		 	ob_info["level"]=5;
		 	ob_info["info1"]="無";
		 	ob_info["info2"]=ctime(time());
		 	ob_info["info3"]=me->name_id(1);
		 	CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			
			me_info["level"]=4;
		 	me_info["info1"]="無";
		 	me_info["info2"]=ctime(time());
		 	me_info["info3"]=me->name_id(1);
			CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
		 	
		 	mark=present(CLUB_MARK, me);
		 	if(!mark)
		 	{
		 		write("幫會信物取得失敗。\n");
			}
			else
			{
				mark->move(me);
			}
			mark=present(CLUB_MARK, ob);
		 	if(!mark)
		 	{
		 		write("幫會信物取得失敗。\n");
			}
			else
			{
				mark->move(ob);
			}
			message_vision("$N將"+CLUB_NAME+"的總指揮權移交給$n。\n",me,ob);
			message( "channel:sky",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")將"+CLUB_NAME+"指揮權移交給"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
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
	string *tuned_ch;
	object mark,me;
	me=this_player();
	
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
		return notify_fail("你必須先將大權轉移才能離開"+CLUB_NAME+"。\n");
	CLUB_D->remove_member(CLUB_ID,getuid(me));
	message_vision("$N主動退出了"+CLUB_NAME+"。\n",me);
	message( "channel:sky",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主動退出了"+CLUB_NAME+"。\n"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	if(!mark=present(CLUB_MARK,me))
	{
		write("幫會信物取得失敗。\n");
	} else destruct(mark);
	me->save();
	return 1;
}

int no_suicide(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
	{
		write("身為"+CLUB_NAME+"高級長官, 交出指揮權之前不可輕生, 以免後繼無人。\n");
		return 1;
	}
	return 0;
}

int do_listmember(string arg)
{
	string *list,*members,temp,output;
	int i,j;
	mapping club;
	list=CLUB_D->club_members(CLUB_ID);
	club=CLUB_D->query_club_record(CLUB_ID);
	members=keys(club);
	output="\n目前"+CLUB_NAME+"登記有案的成員有:\n";
	if(arg=="long")
	{
		for(i=this_object()->query("club_max_level");i>0;i--)
		{
			for(j=0;j<sizeof(members);j++)
			{
				if(club[members[j]]["level"]==i) output=sprintf("%s %12s 幫會等級: %d\n",output,members[j],i);
			}
		}
		output=sprintf("%s \n目前%s共計有: %d 名成員。\n",output,CLUB_NAME,sizeof(members));
		write(output);
		return 1;
	}
	temp=CLUB_D->query_club_leader(CLUB_ID);
	output=sprintf("%s 領導人: %12s\n",output,temp);
	list-=({temp});
	output=sprintf("%s 其他:\n",output,temp);
	output+=CLUB_D->show_club_members(CLUB_ID);
	output=sprintf("%s目前%s共計有: %d 名成員。\n",output,CLUB_NAME,sizeof(members));
	output+="\n [用listmember long 可以看到更完整的資料。]\n";
	write(output);
	return 1;
}

int do_help(string arg)
{
 if(arg=="sky")
 {
  write(@HELP

       �翦�����������������������������������������������������������������
       │                      幫會信物的輔助說明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │說明              │權限        │
       ├───────────────┼─────────┼──────┤
       │  help sky                    │本輔助訊息        │族人        │
       │  sky <你的訊息>              │幫會專用頻道      │族人        │
       │  members                     │列出線上幫會成員  │族人        │
       │  leaveclub                   │主動退出幫會      │族人        │
       │  include <人名>              │將某人收入分堂    │護法專用    │
       │  dismiss <人名>              │取消某人分堂職務  │護法專用    │
       │  accept <人名>               │讓某人加入幫會    │舵主以上    │
       │  kickout <人名>              │將某人逐出幫會    │舵主以上    │
       │  subleader <人名> to <分堂名>│升級某人為護法    │總舵主      │
       │  retire <人名>               │撤除某人護法職位  │總舵主      │
       │  givepower <人名> to <等級>  │改變某人的職位    │總舵主      │
       │  handover <人名>             │掌門職務交接      │總舵主      │
       │  listmember                  │幫會名冊          │舵主以上    │
       └───────────────┴─────────┴──────┘
	 ◎ 使用 accept 指令必須對方先用 joinclub 指令申請才能生效。
         ◎ 天地會目前有二個分堂:【天罡堂】、【地剎堂】。
         ◎ 等級分為: <1:幫眾> <2:堂員> <3:護法> <4:舵主> <5:總舵主> 。
         ◎ 其他天地會的事務: <help sky_rule> , <help sky_story> 。
     	
HELP
  );
  return 1;
  }
  if(arg=="sky_rule")
  {
   this_player()->start_more(@RULE

	                           【天地會幫規】
	一、  嚴格禁止跨幫
	
	      本幫幫員所擁有之所有角色(就是分身囉)，不可以加入其他幫派
	      這樣是避免各幫派之間的無謂鬥爭。
	      同時也各位不要將自己的角色借給他人使用。而要把角色送給他
	      人時，必須POST在幫會的 Terra Board公佈，由長老以上同意並
	      將之Kickout後才可送給他人。
	      如送給同幫幫員,可以POST在Terra Board，由長老同意。
	      另外禁止任意脫離本會，如自己脫離幫會，不要希望本會重新收
	      你，而有必要脫離時，必須POST在 Terra Board經長老會議通過
	      准許，始可離開幫會。
	      違反上述規定者，將逐出族，並會由幫主決定是否加以通緝之。
	
	二、  嚴禁主動PK其他玩家
	
	      本幫幫員禁止PK其他玩家，但由本幫發出格殺令的例外。
	      而所有PK我幫幫員之玩家，應立即通知在線之長老人員，並將情
	      況POST在Terra Board，內容必須必須包括PKER ID和被PK者ID，
	      而在線的幫員,應給与最大協助。
	      而本幫將列出通緝黑名單，我幫幫眾皆可除之。若被PK時，線上
	      無長老以上可為之作證，則請被PK之幫眾自行POST過程，事後經
	      長老或以上人員查證，亦將之列入通緝黑名單。
	
	      除遭受PK以外，本幫幫眾與他人的其他糾紛，必須POST在
	      Terra Board由長老以上決定行動，不可自行PK對方。
	      違反上述規定者，將逐出本族，並由幫主視情況決定是否加以通
	      緝。
	
	三、  禁止盜賣本會裝備
	                    【盜賣本會裝備是嚴重罪行】
	      放置於幫會內之裝備為全幫共有，不得私自變賣。而幫眾可任意
	      加以拿取，唯不可全部拿去，而在離線時，必須放回原位。
	      如在Wiz宣告Reboot time時，可自行拿去變賣。
	      私自變賣裝備者，將逐出本族並且【殺．無．赦】。
	      若有緊急事情需馬上離線，則必須託同一幫之人代為整理。    
	     而會內之EQ不可借給非本幫之人，請緊記。
   
RULE
);
return 1;
  }
  if(arg=="sky_story")
  {
  this_player()->start_more(@SKY_PART

	【天地會傳記和起源 】
	  
	    話說天下會創幫總陀主周伯通在拜訪古劍亭武林大會時，驚
	聞【烏日國】的狂沙十鷲率兵襲擊向天關，武林大會上眾高手趕
	往向天關救援。在離開古劍亭時，在場有一老前輩向周伯通走來
	，而他就是古劍亭的主人 四靈劍王 冉紅塵，冉紅塵向周伯通說
	到因覺得周伯通與其有緣，吩咐他在遲些日子，到天霖聖澤一遊
	。而周伯通的好友李玟(Coco)因耳力驚人，雖然他在遠處，但依
	然聽到一些斷斷續續的話。據李玟在武林大會後向同行之人所說
	，當時冉紅塵向周伯通透露，在古劍亭東南二百里，有一名為天
	霖聖澤的地方，數年前冉紅塵經過那處，發覺那處透射出奇異的
	綠光，而因為當時冉紅塵要趕回古劍亭而無暇理會，所以就此不
	放在心上。而在武林大會上，冉紅塵發覺周伯通身上隱約見到一
	些碧綠色光澤，而且和冉紅塵當年在天霖聖澤見到的一樣，所以
	指導周伯通前天霖聖澤，說不定會有意外收獲。
	
	李玟說到這處，就說因當時手上儲存著三把神武真火，因而精神
	力大減，往後的對談就聽不清了．．．
	    而在打敗烏日國眾兵後，周伯通和其伙伴覺得閑來無事，就
	往天霖聖澤看看吧。同行的是周伯通年少時結識的好兄弟姐妹，
	在各人呼應下，周伯通率令眾人前往天霖聖澤查個究竟....
	在天霖聖澤十里外，各人也隱約見到天霖聖澤中心所發出的綠光
	而眾人就向此綠光進發，途經之處環境清幽，各人走著走著，突
	然間天地變色，像是天怒一樣....天空打下了數個旱雷，似在警
	告各人不要繼續前進。
	眾人是長年在江湖上行走的高手，當然不會被這雷聲嚇退。就在
	此時，地下冒起了數十隻異獸，各人隨即運起自身絕學，周伯通
	當先運起本門索極劍法，配合內功將內力凝聚於右臂之上，運起
	五段連發技，而身旁好友李玟(Coco)和濱崎布(Ayumi)分別向東面
	天霖聖澤中心殺去。李玟運起手上早以儲存的神武真火向異獸擲
	去，而濱崎布也不輸前者，運起八極拳中的纏絲勁向異獸殺去。
	
	雖然眾人也是高手，但在苦戰中內力消耗得特別多，而異獸的威
	力當真厲害，就在此時，眾人發覺同行之伙伴燕楠(Sevil)不見了
	，就在各人疑惑時，聽到一異獸大叫一聲..鮮血濺了一地。原來
	是燕楠用其神偷的絕技背刺正中異獸背心，令該異獸才發出殺豬
	般的怪叫...
	
	眾人邊打邊進，到達了綠色光源之處，而異獸們也不敢靠近，眾
	人才鬆了口氣。就在此時綠光大盛，眾人向那綠光中心一望，驚
	見其中有一物，而此物就是發出綠光的原因。
	周伯通向那物走去，各人立即叫嚷道不要走向不明的物質，但周
	伯通就說到，那可能是冉紅塵前輩所說之物，當天冉紅塵前輩說
	此物應該是由九天之外來到，實是一件異寶。
	而在此後三年，眾人就在天城開門立戶，在天池附近開創了天下
	顯赫有名的【天地會】，而在天霖聖澤獲得之物，就是天下會的
	鎮幫之寶－ 天地指環 。

SKY_PART
);
  return 1;	
 }
 return 0;
}
