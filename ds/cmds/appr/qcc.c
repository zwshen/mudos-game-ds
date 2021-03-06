// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg, output, *type,*exits,*files, material;
	mapping apply;
	int i,*value,flag,times;
	object obj,*ob;

	if (!arg) return notify_fail("指令格式 : qc <物件之名稱或檔名>\n" );
	flag=0;
	if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
			seteuid(ROOT_UID);
		else
			seteuid(geteuid(me));

	if(arg=="here") obj=environment(me);
	else obj = present(target, me);
	if (!obj) obj = find_object(target);
	if (!obj) obj = present(target, environment(me));
	if (!obj && file_size( resolve_path(me->query("cwd"), target))>0 )
	 obj = load_object( resolve_path(me->query("cwd"), target) );
	if (!obj && file_size( resolve_path(me->query("cwd"), target)+".c")>0 )
	 obj = load_object( resolve_path(me->query("cwd"), target)+".c" );
	if (!obj) return notify_fail("沒有這樣物件....。\n");

	if( environment(me)==environment(obj) )
	if( !stringp(msg = me->query("env/msg_qc")) )
		msg = "$N拿起一個放大鏡, 仔細的檢查$n。\n";
	else
		message_vision(msg + "\n", me, obj);

	if(obj->is_character())
	{
		output = "NPC名稱: "+obj->short()+"\n";
		output += "等級: "+obj->query("level")+"\n";
		if(obj->query("race")!="人類")
		{
			output += "開始檢查攻擊方式設定: ";
			if(obj->query("verbs")) output+= "通過!!\n";
				else output+= "沒有設定 verbs! \n";
			output += "開始檢查受攻部位設定: ";
			if(obj->query("limbs")) output+= "通過!!\n";
				else output+= "沒有設定 limbs! \n";
		}
		if(mapp(apply=obj->query("apply")))
		{
		 type=keys(apply);
		 value=values(apply);
		 for(i=0;i<sizeof(apply);i++)
		 {
		  output+=sprintf("附加 %s : %d \n",type[i],value[i]);
		 }
		}
		output+=sprintf("\n基本屬性:\n  力量: %-4d 體質: %-4d 速度: %-4d 智慧: %-4d\n  最大HP: %-5d\n  最大MP: %-5d\n\n",
			obj->query("str"),obj->query("con"),obj->query("dex"),obj->query("int"),
			obj->query("max_hp"),obj->query("max_mp"));
		if(ob=all_inventory(obj))
		{
		 	output += "攜帶物品: \n";
		        for(i=0; i<sizeof(ob); i++)
        		{
				output+=sprintf("  %s (%s) \n",ob[i]->short(),base_name(ob[i]));
        		}
		}
		
		output+="\n其餘請用score查看.\n";
	} else
	{
	 material = obj->query("material");
	 output = "物件名稱: "+(obj->short()? obj->short() : obj->query("short"))+"\n";
	 output += "物件種類: ";
	 if(obj->query("armor_type"))
	 {
	  output+= "防具("+obj->query("armor_type")+")   質料: "+material+"("+obj->M_chinese(material)+")\n";
	  output += "=============================== 材質資訊 ================================\n";
	  output += "密度: "+obj->M_density(material)+"\t";
	  output += "硬度: "+obj->M_hardness(material)+"\t";
	  output += "耐用: "+obj->M_durable(material)+"\t";
	  output += "銳利: "+obj->M_sharp(material)+"\t";
	  output += "價格: "+obj->M_prize(material)+"\n";
	  output += "=========================================================================\n";
	  output+= sprintf("重量: %-5d\t價格: %-5d\t單位: %s\t體積: %-5d\t耐用: %-5d\n",
	  		obj->query_weight(),obj->query("value"),obj->query("unit"),obj->query("volume"),obj->query_temp("durable"));
	  if(obj->query("female_only") ) output += "女性專用\n";
	  if(obj->query("limit_lv")) output+=sprintf("限制等級: %d \n",obj->query("limit_lv"));
	  if(obj->query("limit_str")) output+=sprintf("限制力量: %d \n",obj->query("limit_str"));
	  if(obj->query("limit_con")) output+=sprintf("限制體型: %d \n",obj->query("limit_con"));
	  if(obj->query("limit_dex")) output+=sprintf("限制敏捷: %d \n",obj->query("limit_dex"));
	  if(obj->query("limit_int")) output+=sprintf("限制智慧: %d \n",obj->query("limit_int"));
		if(mapp(apply=obj->query("armor_prop")))
		{
		 type=keys(apply);
		 value=values(apply);
		 for(i=0;i<sizeof(apply);i++)
		 {
		  output+=sprintf("附加 %s : %d \n",type[i],value[i]);
		 }
		}
	 }
	 else if(obj->query("skill_type"))
	 {
	  output+= "武器("+obj->query("skill_type")+")   材質: "+material+"("+obj->M_chinese(material)+")\n";
	  output += "=============================== 材質資訊 ================================\n";
	  output += "密度: "+obj->M_density(material)+"\t";
	  output += "硬度: "+obj->M_hardness(material)+"\t";
	  output += "耐用: "+obj->M_durable(material)+"\t";
	  output += "銳利: "+obj->M_sharp(material)+"\t";
	  output += "價格: "+obj->M_prize(material)+"\n";
	  output += "=========================================================================\n";
	  output+= sprintf("重量: %-5d\t價格: %-5d\t單位: %s\t體積: %-5d\t耐用: %-5d\n",
	  		obj->query_weight(),obj->query("value"),obj->query("unit"),obj->query("volume"),obj->query_temp("durable"));
	  if(obj->query("female_only") ) output += "女性專用\n";
	  if(obj->query("limit_lv")) output+=sprintf("限制等級: %d \n",obj->query("limit_lv"));
	  if(obj->query("limit_str")) output+=sprintf("限制力量: %d \n",obj->query("limit_str"));
	  if(obj->query("limit_con")) output+=sprintf("限制體型: %d \n",obj->query("limit_con"));
	  if(obj->query("limit_dex")) output+=sprintf("限制敏捷: %d \n",obj->query("limit_dex"));
	  if(obj->query("limit_int")) output+=sprintf("限制智慧: %d \n",obj->query("limit_int"));
		if(mapp(apply=obj->query("weapon_prop")))
		{
		 type=keys(apply);
		 value=values(apply);
		 for(i=0;i<sizeof(apply);i++)
		 {
		  output+=sprintf("附加 %s : %d \n",type[i],value[i]);
		 }
		}
	 }
	 else if(obj->is_room()) 
	 {
	  output+= "房間("+base_name(obj)+")\n\n";
	  if(obj->query("light")) output+="照明: 有\n";
	  	else output+="照明: 無\n";
	  if(obj->query("outdoors")) output+="室外: "+obj->query("outdoors")+"\n";
	  	else output+="室內\n";
	  if(mapp(apply=obj->query("exits")))
	  {
	  	output+="\n這裡的出口有:\n";
	   	exits=keys(apply);
		files=values(apply);
		for(i=0;i<sizeof(apply);i++)
		{
		  output+=sprintf("  %s : %s \n",exits[i],files[i]);
		}
	  }
	  if(mapp(apply=obj->query("item_desc")))
	  {
	  	output+="\n房間中可看的額外敘述有:\n";
	   	exits=keys(apply);
		for(i=0;i<sizeof(apply);i++)
		{
		  output+=sprintf("  %s \n",exits[i]);
		}
	  }
	  if(mapp(apply=obj->query("objects")))
	  {
	  	output+="\n這裡的物件有:\n";
	   	exits=keys(apply);
		value=values(apply);
		for(i=0;i<sizeof(apply);i++)
		{
		  output+=sprintf("  %s : %d \n",exits[i],value[i]);
		}
	  }
	 }
	 else
	 {
	  if(obj->value())
	  {
	   output+= "貨幣\n";
	   output=sprintf("%s重量: %d 公克\n",output,obj->weight());
	   output=sprintf("%s價值: %d \n",output,obj->value());
	   write(output);
	   return 1;
	  }
	  if(obj->is_food())
	  {
	   output+= "食物\n";
	   flag=1;
	   times=obj->query("food_remaining");
	  }
	  else if(obj->is_water())
	  {
	   output+= "飲料\n";
	   times=obj->query("water_remaining");
	   flag=1;
	  }
	  else if(obj->is_pill())
	  {
	   output+= "丹藥\n";
	   flag=1;
	   times=1;
	  }
	  else output+= "道具\n";
	  output=sprintf("%s重量: %d 公克\n",output,obj->weight());
	  output=sprintf("%s價格: %d \n",output,obj->query("value"));
	  if(flag)
	  {
	    if(times) output=sprintf("%s可用次數: %d \n",output,times);
	    if(obj->query("heal_hp")) output=sprintf("%s補充HP: %d \n",output,obj->query("heal_hp"));
	    if(obj->query("heal_mp")) output=sprintf("%s補充MP: %d \n",output,obj->query("heal_mp"));
   	    if(obj->query("heal_ap")) output=sprintf("%s補充AP: %d \n",output,obj->query("heal_ap"));
	  }
	 }
	}
	write(output);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : qc <物件之名稱||檔名||here>

利用此指令可以讓巫師快速檢查一個物件或檔案的設定是否正確.

HELP
    );
    return 1;
}
