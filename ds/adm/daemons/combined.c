// combined.c <luky>
// #pragma save_binary
#include <ansi.h>
inherit F_DBASE;

nosave mapping bagi_combine = ([
	"bagi_fist.bagi_fist" : "/daemon/combine/bagi-god-sword",
]);

nosave mapping god_combine = ([
	"bagi_fist" : "/daemon/combine/bagi-god-sword",
]);

string skill_array(object *members);
string search_file(string base_skill,object *members,object me);

void create()
{
	seteuid(getuid());
	set("name", "��O���F");
	set("id", "combined");
}

int exert_combine(object me,object target,object *eff_member,string type)
{
	object weapon;
	string base_skill,base_skill_map,file;
	int i;

	weapon=me->query_temp("weapon");
	
	if(!weapon) base_skill="unarmed";
		else base_skill=weapon->query("skill_type");
	
	base_skill_map=me->query_skill_mapped(base_skill); //��X�D�n�ޯ�
	
	if(stringp(base_skill_map)) base_skill=base_skill_map;

	eff_member -= ({me});
 	if(sizeof(eff_member)>0)
	{
		file=search_file(base_skill,eff_member,me);
		if(!file || file=="") return 0;
		if( file_size(file + ".c") <= 0 )
		{
			CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): error in load file = %s",
			me->name(1), me->query("id"), file));
			log_file( "combine_skill", sprintf("%s(%s): error in load %s on %s\n",
			me->name(1), me->query("id"), file, ctime(time())));
			return 0;
		}
		return (int)call_other( file, "combine", me, target, eff_member);
	}
	return 0;
}

//�Nskill_array�Ǧ^���r��B�z���X�ŦX���ޯ��ɮ�
//Luky
string search_file(string base_skill,object *members,object me)
{
	string skills,*type,*file;
	int i;
	
	skills=skill_array(members);
	if(me->query("env/debug")) tell_object(me,HIW"\n skill_array ���G: "+skills+"\n\n"NOR);
	
	
	switch(base_skill)
	{
		case "godsword" : 
			type=keys(god_combine);
			file=values(god_combine);
			for(i=0;i<sizeof(god_combine);i++)
			{
			if( strsrch(skills,type[i],1) !=-1 ) return file[i];
			}
			break;
		case "bagi_fist" : 
			if( strsrch(skills,"bagi_fist.bagi_fist",1) !=-1 ) return "/daemon/combine/three-bagi";
			break;
		default :
				return "";	
	
	}
}

//����ƱNmembers���Ѥ��ޯ���r�����ǱƧǫ��ର�r��Ǧ^
//Luky
string skill_array(object *members)
{
	object weapon;
	string base_skill,base_skill_map,output="";
	string *skills=({ });
	int i;
 	
 	//�N�ޯ��ন�r��}�C
 	for(i=0;i<sizeof(members);i++)
 	{
 		if(!members[i]) continue;
 		weapon=members[i]->query_temp("weapon");
	
		if(!weapon) base_skill="unarmed";
			else base_skill=weapon->query("skill_type");
	
		base_skill_map=members[i]->query_skill_mapped(base_skill);
		if(stringp(base_skill_map)) base_skill=base_skill_map;
		skills+=({ base_skill });
 	}
 	//�r��}�C�Ƨ�
 	skills = sort_array(skills, "sort_skill", this_object());
 	
 	//�N�}�C�ର��@�r��
 	for(i=0;i<sizeof(skills);i++) output+=skills[i]+".";
	return output;
}

int sort_skill(string skill1, string skill2)
{
	return strcmp(skill1,skill2);
}
