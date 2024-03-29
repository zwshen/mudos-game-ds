//幫會精靈. by Luky 1999/4/11
// 用來記錄額外身分用的..
// 目前支援的幫會:
// dragon 狂龍
// moon 月族
// sky 天地會
// info:
// ([
//    level:
//    title:
//    info1:
//    info2:
//    info3:
// ])

// #pragma save_binary
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;

mapping club_record;
mapping club_leader;

protected mapping club_detail = ([]);

string *do_sort_record(string type,string *keys);
void resort_record();

void create()
{
        seteuid(getuid());
        if( !restore() )
        {
        	club_record=([]);
        	club_leader=([]);
        	club_detail=([
			"dragon" : 	([
						"name" :	"狂龍幫",
						"mark" :	"dragon necklace",
						"file" :	"/open/always/dragon_mark",
					]),
			"sky" :	        ([
						"name" :	"天地會",
						"mark" :	"ring of heaven and earth",
						"file" :	"/open/always/sky_mark",
					]),
			"moon" : 	([
						"name" :	"月族",
						"mark" :	"ring of moon-soul",
						"file" :	"/open/always/moon_mark",
					]),
			"ming" : 	([
						"name" :	"明教",
						"mark" :	"god fire mask",
						"file" :	"/open/always/ming_mark",
					]),
                        "god"  :        ([
                                                "name" :        "神族",
                                                "mark" :        "god crown",
                                                "file" :        "/open/always/god_mark",
                                        ]),
                        "ming" :        ([
                                                "name" :        "明教",
                                                "mark" :        "Plate of Holy Fire",
                                                "file" :        "/open/always/ming_mark",
                                        ]),

		]);
        }
        else
        {
        	if( !mapp(club_record) ) club_record = ([]);
        	if( !mapp(club_leader) ) club_leader = ([]);
        }
}

string query_save_file() { return DATA_DIR + "club"; }

varargs string show_club_members(string type)
{
	string list="",*club_name,*member_id;
	int i,j,k;
	club_name=keys(club_record);
	if(type=="all")
	{
		for(i=0;i<sizeof(club_name);i++)
		{
			list=sprintf("%s%s:\n",list,club_name[i]);
			member_id=keys(club_record[club_name[i]]);
			k=0;
			for(j=0;j<sizeof(member_id);j++)
			{
				list=sprintf("%s  %12s",list,member_id[j]);
				k++;
				if(k%5==0) list+="\n";
			}
		}
	}
	else
		if(member_array(type,club_name)!=-1)
		{
			member_id=keys(club_record[type]);
			k=0;
			for(j=0;j<sizeof(member_id);j++)
			{
				list=sprintf("%s  %12s",list,member_id[j]);
				k++;
				if(k%5==0) list+="\n";
			}
		}
		else
		{
			return "沒有此幫會紀錄。\n";
		}
		
	list+="\n";
	return list;
}

void clear_all()
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<=wiz_level("(arch)") || !userp(ob) )
	{
		write("你沒有足夠的權限清除幫會紀錄！\n");
		return;
	}
	write("這樣會清除所有的幫會紀錄！  確定要清除嗎？(y/n)");
	input_to("comfirm_clear_all", ob);
}

protected void comfirm_clear_all(string yn, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("取消！\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) 清除所有的幫會紀錄。\n備份資訊:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), show_club_members("all")) );
	
	club_record=([]);
	save();
	write("幫會資訊已全部刪除。\n");
	return;
}

void clear_record(string club)
{
	string *clubs;
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("你沒有足夠的權限清除幫會紀錄！\n");
		return;
	}
	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("目前沒有幫會紀錄。\n");
		return;	
	}
	clubs=keys(club_record);
	if(sizeof(clubs)<1 || member_array(club,clubs)==-1)
	{
		write("沒有這個幫會紀錄。\n");
		return;
	}
	
	write("這樣會清除"+club+"的幫會紀錄！  確定要清除嗎？(y/n)");
	input_to("comfirm_clear",club, ob);
}

protected void comfirm_clear(string yn,string club, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("取消！\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) 清除 %s 的幫會紀錄。\n備份資訊:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , show_club_members(club)) );
	
	club_record[club]=([]);
	save();
	write("["+club+"]幫會資訊已刪除。\n");
	return;
}

void remove_club(string club)
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("你沒有足夠的權限清除幫會紀錄！\n");
		return;
	}
	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("目前沒有幫會紀錄。\n");
		return;	
	}

	if(undefinedp(club_record[club]))
	{
		write("沒有這個幫會紀錄。\n");
		return;
	}
	
	write("這樣會清除"+club+"幫會！  確定要清除嗎？(y/n)");
	input_to("comfirm_remove",club, ob);
}

protected void comfirm_remove(string yn,string club, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("取消！\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) 刪除 %s 幫會。\n備份資訊:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , show_club_members(club)) );
	
	map_delete(club_record, club);
	save();
	write("["+club+"]幫會已刪除。\n");
	return;
}

int add_club(string club)
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("你沒有足夠的權限增加幫會！\n");
		return 0;
	}

	if(!undefinedp(club_record[club]))
	{
		write("已經有這個幫會了。\n");
		return 0;
	}
	club_record[club]=([]);
	write("新增幫會OK！["+club+"]\n");
	save();
	return 1;
}

mapping query_club_record(string club)
{
	if(!undefinedp(club_record[club]))
	{
		if(mapp(club_record[club])) return club_record[club];
		else return ([]);
	}
	else return ([]);
}

string query_club_mark(string club)
{
	if(!undefinedp(club_detail[club]))
	{
		if(!undefinedp(club_detail[club]["file"]) && stringp(club_detail[club]["file"]))
			return club_detail[club]["file"];
		else return "";
	}
	else return "";
}

mapping query_club_detail(string club)
{
	if(!undefinedp(club_detail[club]))
	{
		return club_detail[club];
	}
	else return ([]);
}

string query_club_leader(string club)
{
	if(!undefinedp(club_leader[club])) return club_leader[club];
	else return "無此幫會或是此幫會未設定幫主\n";
}

void set_club_leader(string club,string id)
{
	object ob;
	ob=this_player();

	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("目前沒有幫會紀錄。\n");
		return;	
	}

	if(undefinedp(club_record[club]))
	{
		write("沒有這個幫會紀錄。\n");
		return;
	}
	
	if( wiz_level(ob)<wiz_level("(arch)") && query_club_leader(club)!=getuid(ob) )
	{
		write("你沒有足夠的權限設定幫會領袖！\n");
		return;
	}
	club_leader[club]=id;
	save();
	log_file( "CLUB", sprintf("[%s] %s(%s) 設定 %s 幫會新領袖 %s。\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , id) );
	return;
}

int is_club_leader(object user)
{
	string *clubs;
	int i;
	clubs=keys(club_leader);
	for(i=0;i<sizeof(clubs);i++)
	{
		if(club_leader[clubs[i]]==getuid(user)) return 1;
	}
	return 0;
}

int set_member(string club,string id,mapping info)
{
	string *clubs;
	clubs=keys(club_record);
	if(member_array(club,clubs)==-1)
	{
		notify_fail("沒有"+club+"這個幫會!!\n");
		return 0;
	}
	club_record[club][id]=info;
	save();
	return 1;
}

int add_member(string club_id,string member_id,mapping info)
{
	string *clubs;
	clubs=keys(club_record);
	if(member_array(club_id,clubs)==-1)
	{
		notify_fail("沒有這個幫會!!\n");
		return 0;
	}
	if(!undefinedp(club_record[club_id][member_id]))
	{
		notify_fail("這個人已經加入此幫會了!!\n");
		return 0;	//已經有此成員
	}
	club_record[club_id][member_id]=info;
	save();
	return 1;
}

int remove_member(string club_id,string member_id)
{
	string *clubs;
	clubs=keys(club_record);
	if(member_array(club_id,clubs)==-1)
	{
		notify_fail("沒有這個幫會!!\n");
		return 0;
	}
	if(undefinedp(club_record[club_id][member_id]))
	{
		notify_fail("此人並沒有加入這個幫會!!\n");
		return 0;	//無此成員
	}
	map_delete(club_record[club_id], member_id);
        save();
	return 1;
}

int check_member(string club,string id)
{
	if(undefinedp(club_record[club]))
	{
		notify_fail("沒有這個幫會!!\n");
		return 0;
	}
	if(undefinedp(club_record[club][id]))
	{
		notify_fail("此人並沒有加入這個幫會!!\n");
		return 0;
	}
	if(!undefinedp(club_record[club][id]["level"])) return (int)club_record[club][id]["level"]; //傳回幫會等級
	else return 1;
}

mapping query_member_info(string club,string id)
{
	mapping info;
	if(!undefinedp(club_record[club][id]))
	{
		if(mapp(club_record[club][id])) return club_record[club][id];
		else return ([]);
	}
	return ([]);
}

string *club_members(string club)
{
	string *members;
	
	if(undefinedp(club_record[club]))
	{
		notify_fail("沒有這個幫會!!\n");
		return ({"沒有此幫會\n"});
	}
	
	members=keys(club_record[club]);
	return members;
}

string *find_player_club(string id)
{
	string *result=({}),*clubs;
	int i;
	clubs=keys(club_record);
	for(i=0;i<sizeof(clubs);i++)
	{
		if(!undefinedp(club_record[clubs[i]][id])) result+=({clubs[i]});
	}
	return result;
}

object *find_online_members(string club)
{
	object *user,*result=({});
	string *club_member=({""});
	int i;
	club_member=club_members(club);
	user=users();
	for(i=0;i<sizeof(user);i++)
	{
		if(member_array(getuid(user[i]),club_member)!=-1) result+=({user[i]});
	}
	return result;
}

int set_lockleave(string clubid,int flag)
{
	if(undefinedp(club_detail[clubid])) return 0;
	club_detail[clubid]["lock_leave"]=flag;
	save();
	return flag;
}

int query_lockleave(string clubid)
{
	if(undefinedp(club_detail[clubid])) return 0;
	if(undefinedp(club_detail[clubid]["lock_leave"]))
	{
		club_detail[clubid]["lock_leave"]=0;
		save();
		return 0;
	}
	return club_detail[clubid]["lock_leave"];
}

void clean_player(string id)
{
	string *joinclub=({});
	int i;
	joinclub = find_player_club(id);
	if(sizeof(joinclub))
	{
		for(i=0;i<sizeof(joinclub);i++)
		{
			remove_member(joinclub[i],id);
		}
	}
	return;
}

