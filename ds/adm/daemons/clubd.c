//���|���F. by Luky 1999/4/11
// �ΨӰO���B�~�����Ϊ�..
// �ثe�䴩�����|:
// dragon �g�s
// moon ���
// sky �Ѧa�|
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
						"name" :	"�g�s��",
						"mark" :	"dragon necklace",
						"file" :	"/open/always/dragon_mark",
					]),
			"sky" :	        ([
						"name" :	"�Ѧa�|",
						"mark" :	"ring of heaven and earth",
						"file" :	"/open/always/sky_mark",
					]),
			"moon" : 	([
						"name" :	"���",
						"mark" :	"ring of moon-soul",
						"file" :	"/open/always/moon_mark",
					]),
			"ming" : 	([
						"name" :	"����",
						"mark" :	"god fire mask",
						"file" :	"/open/always/ming_mark",
					]),
                        "god"  :        ([
                                                "name" :        "����",
                                                "mark" :        "god crown",
                                                "file" :        "/open/always/god_mark",
                                        ]),
                        "ming" :        ([
                                                "name" :        "����",
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
			return "�S�������|�����C\n";
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
		write("�A�S���������v���M�����|�����I\n");
		return;
	}
	write("�o�˷|�M���Ҧ������|�����I  �T�w�n�M���ܡH(y/n)");
	input_to("comfirm_clear_all", ob);
}

protected void comfirm_clear_all(string yn, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("�����I\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) �M���Ҧ������|�����C\n�ƥ���T:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), show_club_members("all")) );
	
	club_record=([]);
	save();
	write("���|��T�w�����R���C\n");
	return;
}

void clear_record(string club)
{
	string *clubs;
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("�A�S���������v���M�����|�����I\n");
		return;
	}
	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("�ثe�S�����|�����C\n");
		return;	
	}
	clubs=keys(club_record);
	if(sizeof(clubs)<1 || member_array(club,clubs)==-1)
	{
		write("�S���o�����|�����C\n");
		return;
	}
	
	write("�o�˷|�M��"+club+"�����|�����I  �T�w�n�M���ܡH(y/n)");
	input_to("comfirm_clear",club, ob);
}

protected void comfirm_clear(string yn,string club, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("�����I\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) �M�� %s �����|�����C\n�ƥ���T:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , show_club_members(club)) );
	
	club_record[club]=([]);
	save();
	write("["+club+"]���|��T�w�R���C\n");
	return;
}

void remove_club(string club)
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("�A�S���������v���M�����|�����I\n");
		return;
	}
	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("�ثe�S�����|�����C\n");
		return;	
	}

	if(undefinedp(club_record[club]))
	{
		write("�S���o�����|�����C\n");
		return;
	}
	
	write("�o�˷|�M��"+club+"���|�I  �T�w�n�M���ܡH(y/n)");
	input_to("comfirm_remove",club, ob);
}

protected void comfirm_remove(string yn,string club, object ob)
{
	if( yn!="y" && yn!="Y" )
	{
		write("�����I\n");
		return;
	}
	
	log_file( "CLUB", sprintf("[%s] %s(%s) �R�� %s ���|�C\n�ƥ���T:\n%s\n",  ctime(time()),
		ob->query("name"),getuid(ob), club , show_club_members(club)) );
	
	map_delete(club_record, club);
	save();
	write("["+club+"]���|�w�R���C\n");
	return;
}

int add_club(string club)
{
	object ob;
	ob=this_player();
	if( wiz_level(ob)<wiz_level("(arch)") || !userp(ob) )
	{
		write("�A�S���������v���W�[���|�I\n");
		return 0;
	}

	if(!undefinedp(club_record[club]))
	{
		write("�w�g���o�����|�F�C\n");
		return 0;
	}
	club_record[club]=([]);
	write("�s�W���|OK�I["+club+"]\n");
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
	else return "�L�����|�άO�����|���]�w���D\n";
}

void set_club_leader(string club,string id)
{
	object ob;
	ob=this_player();

	if(!mapp(club_record) || sizeof(club_record)<1)
	{
		write("�ثe�S�����|�����C\n");
		return;	
	}

	if(undefinedp(club_record[club]))
	{
		write("�S���o�����|�����C\n");
		return;
	}
	
	if( wiz_level(ob)<wiz_level("(arch)") && query_club_leader(club)!=getuid(ob) )
	{
		write("�A�S���������v���]�w���|��S�I\n");
		return;
	}
	club_leader[club]=id;
	save();
	log_file( "CLUB", sprintf("[%s] %s(%s) �]�w %s ���|�s��S %s�C\n",  ctime(time()),
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
		notify_fail("�S��"+club+"�o�����|!!\n");
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
		notify_fail("�S���o�����|!!\n");
		return 0;
	}
	if(!undefinedp(club_record[club_id][member_id]))
	{
		notify_fail("�o�ӤH�w�g�[�J�����|�F!!\n");
		return 0;	//�w�g��������
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
		notify_fail("�S���o�����|!!\n");
		return 0;
	}
	if(undefinedp(club_record[club_id][member_id]))
	{
		notify_fail("���H�èS���[�J�o�����|!!\n");
		return 0;	//�L������
	}
	map_delete(club_record[club_id], member_id);
        save();
	return 1;
}

int check_member(string club,string id)
{
	if(undefinedp(club_record[club]))
	{
		notify_fail("�S���o�����|!!\n");
		return 0;
	}
	if(undefinedp(club_record[club][id]))
	{
		notify_fail("���H�èS���[�J�o�����|!!\n");
		return 0;
	}
	if(!undefinedp(club_record[club][id]["level"])) return (int)club_record[club][id]["level"]; //�Ǧ^���|����
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
		notify_fail("�S���o�����|!!\n");
		return ({"�S�������|\n"});
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

