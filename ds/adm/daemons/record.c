//�������F. by Luky 1999/8/10
// #pragma save_binary
#include <localtime.h>
#include <ansi2.h>
#include <command.h>
#define GVHEIGHT 12
inherit F_DBASE;
inherit F_SAVE;

mapping record;
string past_money_rec;
string now_money_rec;
string future_money_rec;
string pk_rec;
string mk_rec;
string popularity_rec;
string mud_age_rec;
string temp_rec;
string scroll_rec;   // ���b�X�g�O�� - Tmr 2007/04/29
nosave string usage_graph_rec;
int *usage;
mapping mj_record;
string *do_sort_record(string type,string *keys);
void resort_record();
int remove_temp_record();
void www_usrlist();

void create()
{
        seteuid(getuid());
        if( !restore() )
        {
        	record = ([]);
        }
        else
        {
        	if( !mapp(record) ) record = ([]);
        	if( !mapp(mj_record) ) mj_record = ([]);
        }
        remove_temp_record();
	resort_record();
}
string query_save_file() { return DATA_DIR + "record"; }

int clear_mj_data()
{
	mj_record = ([]);
	save();
	return 1;
}

mapping query_mj_data()
{
	mapping temp_data=([]);
	if(!mapp(mj_record) || sizeof(mj_record)<1) return temp_data;
	temp_data = mj_record;
	return temp_data;
}

int set_mj_data(mapping temp_data)
{
	if(mapp(temp_data))
	{
		mj_record = temp_data;
//		save();
		return 1;
	}
	return 0;
}

int set_record(string id, mapping info)
{
	record[id]=info;
        save();
        return 1;
}

mapping query_record(string id)
{
	if(!undefinedp(record[id]) ) return record[id];
        else return ([]);

}

int remove_record(string id)
{
	if(undefinedp(record[id]) ) return 0;
	map_delete(record,id);
        save();
        return 1;
}
int add_scroll_record(string arg)
{
          if( !scroll_rec ) scroll_rec = "";
        scroll_rec = arg + scroll_rec;
        return 1;
}


string query_scroll_record() {
        if( !scroll_rec || scroll_rec=="" ) return "�|�L���󱲶b����\n";
        return scroll_rec;
}
int scroll_times = 0;

int getTotalScroll() { return scroll_times; }
int add_temp_record(string arg)
{
	if(temp_rec=="����L�j�ơC\n" || temp_rec=="�����w�M��!\n") temp_rec="\n";
         temp_rec = arg + temp_rec;
    scroll_times++;
        return 1;
}
int remove_temp_record()
{
	temp_rec="����L�j�ơC\n";
        save();
        return 1;
}
int remove_all_record()
{
	record=([]);
	past_money_rec="�����w�M��!\n";
	now_money_rec="�����w�M��!\n";
	future_money_rec="�����w�M��!\n";
	pk_rec="�����w�M��!\n";
	mk_rec="�����w�M��!\n";
	popularity_rec="�����w�M��!\n";
	mud_age_rec="�����w�M��!\n";
	temp_rec="�����w�M��!\n";
     scroll_rec = "�����w�M��!\n";
     scroll_times = 0;
        save();
        return 1;
}

int do_record(object me)
{
	object money;
	int value;
	mapping player_info = ([
				"name": "�L�W��",
				"past_money": 0,
				"now_money": 0,
				"future_money": 0,
				"MKS": 0,
				"PKS": 0,
				"popularity": 0,
				"mud_age": 0,
				]);
	player_info["name"]=me->query("name");
	money=present("past_money",me);
	if(money) value=money->value();
	else value=0;
	player_info["past_money"]=(int)value+(int)me->query("bank/past");
	money=present("dollar",me);
	if(money) value=money->value();
	else value=0;
	player_info["now_money"]=(int)value+(int)me->query("bank/now");
	player_info["future_money"]=(int)me->query("bank/future");
	player_info["MKS"]=(int)me->query("MKS");
	player_info["PKS"]=(int)me->query("PKS");
	player_info["popularity"]=(int)me->query("popularity");
	player_info["mud_age"]=(int)me->query("mud_age");
	return set_record(me->query("id"),player_info);
}

void resort_record()
{
	string *key,*old_key;
	int key_size,i;
	mapping record_temp;

	record_temp = record;
	old_key=keys(record_temp);
	key_size=sizeof(old_key);
	
	if(key_size<1)
	{
		past_money_rec="\n    �ثe�S���Ʀ���� \n\n";
		now_money_rec="\n    �ثe�S���Ʀ���� \n\n";
		future_money_rec="\n    �ثe�S���Ʀ���� \n\n";
		pk_rec="\n    �ثe�S���Ʀ���� \n\n";
		mk_rec="\n    �ثe�S���Ʀ���� \n\n";
		popularity_rec="\n    �ثe�S���Ʀ���� \n\n";
		mud_age_rec="\n    �ثe�S���Ʀ���� \n\n";
		return;
	}
	//
	// �O���Ǫ��Ʀ�
	//
	key=do_sort_record("MKS",old_key);
	key_size=sizeof(key);
	mk_rec="\n";
	mk_rec+=HIM"  �ڤۤC�������ͪ��Ʀ�]\n"NOR"==============================================\n";
	for(i=0;i<key_size && i<9;i++)
	{
		mk_rec+=sprintf(" %6s %-18s  �����Ǫ�: %-12d\n",
		"��"+chinese_number(i+1)+"�W:",record_temp[key[i]]["name"]+"("+key[i]+")",record_temp[key[i]]["MKS"],);
	}
	mk_rec+="==============================================\n";
	//
	// �O�����a�Ʀ�
	//
	old_key=keys(record_temp);
	key=do_sort_record("PKS",old_key);
	key_size=sizeof(key);
	pk_rec="\n";
	pk_rec+=HIR"  �ڤۤC����H�g�q�r�W��\n"NOR"==============================================\n";
	for(i=0;i<key_size && i<9;i++)
	{
		if(record_temp[key[i]]["PKS"]<1) continue;
		pk_rec+=sprintf(" %10s %-18s ���`�H�� %d �H\n",
		"��"+chinese_number(i+1)+"������:",record_temp[key[i]]["name"]+"("+key[i]+")",record_temp[key[i]]["PKS"],);
	}
	pk_rec+="==============================================\n";
	//
	// �j�N�]�I�Ʀ�
	//
	old_key=keys(record_temp);
	key=do_sort_record("past_money",old_key);
	key_size=sizeof(key);
	past_money_rec="\n";
	past_money_rec+=HIY"  �ڤۤC��j�N�I�αƦ�]\n"NOR"==============================================\n";
	for(i=0;i<key_size && i<9;i++)
	{
		past_money_rec+=sprintf(" %6s %-18s  �`�겣: %-12d\n",
		"��"+chinese_number(i+1)+"�W:",record_temp[key[i]]["name"]+"("+key[i]+")",record_temp[key[i]]["past_money"],);
	}
	past_money_rec+="==============================================\n";
	//
	// �{�N�]�I�Ʀ�
	//
	old_key=keys(record_temp);
	key=do_sort_record("now_money",old_key);
	key_size=sizeof(key);
	now_money_rec="\n";
	now_money_rec+=HIY"  �ڤۤC��{�N�I�αƦ�]\n"NOR"==============================================\n";
	for(i=0;i<key_size && i<9;i++)
	{
		now_money_rec+=sprintf(" %6s %-18s  �`�겣: %-12d\n",
		"��"+chinese_number(i+1)+"�W:",record_temp[key[i]]["name"]+"("+key[i]+")",record_temp[key[i]]["now_money"],);
	}
	now_money_rec+="==============================================\n";
	//
	// ���W�ױƦ�
	//
	old_key=keys(record_temp);
	key=do_sort_record("popularity",old_key);
	key_size=sizeof(key);
	popularity_rec="\n";
	popularity_rec+=HIW"  �ڤۤC��^���Ʀ�]\n"NOR"==============================================\n";
	for(i=0;i<key_size && i<9;i++)
	{
		if(record_temp[key[i]]["popularity"]<1) continue;
		popularity_rec+=sprintf(" %6s %-18s  ���W��: %-12d\n",
		"��"+chinese_number(i+1)+"�i�h:",record_temp[key[i]]["name"]+"("+key[i]+")",record_temp[key[i]]["popularity"],);
	}
	popularity_rec+="==============================================\n";
	//
	// �C���~�ֱƦ�
	//
	old_key=keys(record_temp);
	key=do_sort_record("mud_age",old_key);
	key_size=sizeof(key);
	mud_age_rec="\n";
	mud_age_rec+=HIC"  �ڤۤC��ѳ��Ʀ�]\n"NOR"==============================================\n";
	for(i=0;i<key_size && i<9;i++)
	{
		mud_age_rec+=sprintf(" %6s %-18s  �Z���ɶ�: %-8d �p��\n",
		"��"+chinese_number(i+1)+"�W:",record_temp[key[i]]["name"]+"("+key[i]+")",record_temp[key[i]]["mud_age"]/3600,);
	}
	mud_age_rec+="==============================================\n";
}

string query_past_money_rec()
{
	return past_money_rec;
}
string query_now_money_rec()
{
	return now_money_rec;
}
string query_future_money_rec()
{
	return future_money_rec;
}
string query_pk_rec()
{
	return pk_rec;
}
string query_mk_rec()
{
	return mk_rec;
}
string query_popularity_rec()
{
	return popularity_rec;
}
string query_mud_age_rec()
{
	return mud_age_rec;
}
string query_temp_rec()
{
	return temp_rec;
}
string *do_sort_record(string type,string *keys)
{
	string *temp_keys,*result=({});
	int i=0,j,max_value,mark;
	temp_keys=keys;
	while(i<sizeof(keys) && i<10)
	{
		max_value=0;
		mark=0;
		for(j=0;j<sizeof(temp_keys);j++) //��̤j��
		{
			if(record[temp_keys[j]][type]>max_value)
			{
			 max_value=record[temp_keys[j]][type];
			 mark=j;
			}
			
		}
		if(sizeof(temp_keys)>0)
		{
			result+=({temp_keys[mark]});
			temp_keys-=({temp_keys[mark]});
		}
		i++;
	}
	return result;
}

void clean_up_usage()
{
	usage=({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
	return;
}

string graph_vertical(int *counter)
{
	string pic="";
	int total = 0,max_count=0,i,k,*graph_count;
	graph_count = counter;
	for(i=0; i<sizeof(counter); i++)
	{
		if(counter[i] > max_count) max_count=counter[i];
	}
	for(i=0;i<sizeof(counter);i++)
	{
		total += counter[i];
	}
	// �p��۹�q
	if( max_count > GVHEIGHT )
	{
		for(i=0;i<sizeof(counter);i++)
			graph_count[i] = (counter[i]*GVHEIGHT)/max_count;
	}
	for(k=GVHEIGHT;k>=0;k--)
	{
		pic += "    ";
		for(i=0;i<sizeof(graph_count);i++)
		{
			if(graph_count[i]==k)
				pic += sprintf(HIM"%2d "NOR,counter[i]);
			else if(graph_count[i]>k)
				pic += "�i ";
			else
				pic += "   ";
		}
		pic += "\n";
	}
	pic += "    ";
	for(i=0;i<sizeof(graph_count);i++)
	{
		pic += sprintf("%02d ",i);
	}
	pic += "\n\n\t\t�� �� �b �� �� �C �� �_ �I �� �H ��: "+HIR+total+NOR+"\n";
	return pic;
}

int do_graph()
{
	string pic;

	pic = HIY"\t\t��  ��  �C  ��  �W  ��  �H  ��  ��  �p  ��\n\n"NOR;
	pic += graph_vertical(usage);	
	usage_graph_rec = pic;
	return 1;
}

// �έp�Τ��R�W���H��
void usage_statistics()
{
	if(!sizeof(usage)) clean_up_usage();
	do_graph();
	save();
}

mixed query_usage() { return usage; }

void add_usage()
{
	mixed *local;
	int current_hour;
	if(!sizeof(usage)) clean_up_usage();
	local = localtime(REAL_TIME_TICK);
	current_hour = local[LT_HOUR]; //0~23
	usage[current_hour] += 1;
	return;
}

string query_usage_rec()
{
	if(!sizeof(usage)) clean_up_usage();
	return usage_graph_rec;
}


void www_usrlist()
{
	string usrlist;
	
	usrlist = WHO_CMD->main(this_object(),"-l",1);
	rm("/data/usrlist");
	write_file("/data/usrlist",usrlist);
	
	return;
}
