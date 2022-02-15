// aliasd.c
// #pragma save_binary
#include <ansi.h>
inherit F_DBASE;
void create() 
{
	seteuid(getuid());
	set("channel_id", "���~���F");
}
// list �ɪ����~��T���
string weapon_info(object ob,object ppl,string type)
{
	object old_eq;
	string race,output="";
	int now_dam,new_dam,fee;
	if(!ppl) return "";
	race = ppl->query("race");
	if(race == "human") race ="";
	else race += "_";
      race = ""; // add by tmr 2006/11/13
	if(old_eq=ppl->query_temp("weapon"))
	{
		{
			now_dam = old_eq->query(race+"weapon_prop/damage");
			new_dam = ob->query(race+"weapon_prop/damage");
		}
	}
	 else
	{
		now_dam = 0;
		new_dam = ob->query(race+"weapon_prop/damage");
	}
	fee = new_dam - now_dam;
	if(fee<0)
	{
		output = GRN;
	}
	else if(fee>0) output = HIG;
	else output = "";
	output += sprintf("��%3d%s ",new_dam,NOR);
	return output;
}

string armor_info(object ob,object ppl,string type)
{
	object old_eq;
	string race,output="";
	int now_def,new_def,fee;
	if(!ppl) return "";
	race = ppl->query("race");
	if(race == "human") race ="";
	else race += "_";
      race = ""; // add by tmr 2006/11/13
	if(old_eq=ppl->query_temp("armor/"+type))
	{
		{
			now_def = old_eq->query(race+"armor_prop/armor");
			new_def = ob->query(race+"armor_prop/armor");
		}
	}
	 else
	{
		now_def = 0;
		new_def = ob->query(race+"armor_prop/armor");
	}
	fee = new_def - now_def;
	if(fee<0)
	{
		output = YEL;
	}
	else if(fee>0) output = HIY;
	else output = "";
	output += sprintf("��%3d%s ",new_def,NOR);
	return output;
}

varargs string item_desc(object ob,object ppl)
{
	string output="",type;
	if(type=ob->query("skill_type"))
	{
		output = sprintf("%s�Z��%s %s%-s%-s",HIG,NOR,ob->query_autoload()? HIR"S"NOR:" ",weapon_info(ob,ppl,type),ob->short());
	}
	else if(type=ob->query("armor_type"))
	{
		output = sprintf("%s����%s %s%-s%-s",HIY,NOR,ob->query_autoload()? HIR"S"NOR:" ",armor_info(ob,ppl,type),ob->short());
	}
	else if(ob->is_water() || ob->is_food() || ob->is_pill()) output = sprintf("%s�^�_%s %s%-s",HIC,NOR,ob->query_autoload()? HIR"S"NOR:" ",ob->short());
	else output = sprintf("�D�� %s%-s",ob->query_autoload()? HIR"S"NOR:" ",ob->short());
	return output;
}
string item_list(object ob,object ppl)
{
	   return sprintf("%8d .............. %s", ob->query("value"),item_desc(ob,ppl));
}
