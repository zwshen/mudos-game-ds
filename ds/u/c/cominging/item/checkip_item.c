// cominging@DS 2000.6.30
// 刪除相似的功能, 先解決重覆出現的問題
// checkip.c (草稿) 檢查 Multi-login 的 ip.
// bug 1. 會重覆出現
// cominging@DS 2000.5.26

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"Checkip ITEM 版 "NOR, ({ "checkip item", "item", "checkip" }));
	set("long", "\n");
	set("unit", "台");
	set("value", 1);
	setup();
}

void init()
{
	add_action("do_checkip", "checkip");
	add_action("do_help", "help");
}

int do_checkip(string arg)
{
	object me = this_player(), *ob = users(), tar;
	int x, y, i1, i2, i3, i4, ip1, ip2, ip3, ip4, a, ppl;
	string ip, str = "", got = "..", *g;

	for(x=0;x<sizeof(ob);x++)
	{
		string t = "";
		if( !ob[x]->query("name") ) continue;
		if( !ip = query_ip_number(ob[x]) ) continue;
		if( sscanf( ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4 ) != 4 ) continue;
		g = explode(got, "..");
		if( member_array(ob[x]->query("id"), g) != -1 ) continue;

		for(y=0;y<sizeof(ob);y++)
		{
			if( !ob[y]->query("name") ) continue;
			if( ob[x] == ob[y] ) continue;
			if( query_ip_number(ob[y]) == ip )
			{
//				str += sprintf(WHT" %-12s 與 %12s 的 ip "HIR"相同"NOR WHT"(%-16s)。\n", getuid(ob[x]), getuid(ob[y]), ip);
				got += ob[y]->query("id") + "..";
				t += ob[y]->query("id") + ",";
			}	
/*			else if( sscanf(query_ip_number(ob[y]), "%d.%d.%d.%d", i1, i2, i3, i4 ) == 4 )
				if( i1 == ip1 && i2 == ip2 && i3 == ip3 )
					str += sprintf(WHT" %-12s 與 %12s 的前三位 ip "HIG"相似"NOR WHT"(%-16s)。\n", getuid(ob[x]), getuid(ob[y]), ip);*/
		}
		if( t && t != "" )
		{
			t += ob[x]->query("id");
			if( sizeof(g=explode(t, ",")) != 0 )
			{
				ppl = sizeof(g);
				tell_object(find_player("cominging"), t + "(" + ppl + ")\n");
				if( ppl > 1 )
					for(a=0;a<(sizeof(g)-2);a++)
						str += " " + WHT + g[a] + "、";
				str += sprintf(WHT" %s 和 %s 的 ip "HIR"相同"NOR WHT"(%-16s)。\n", g[ppl-2], g[ppl-1], ip);
			}
		}
	}
//	if( str == "" ) str = " 沒有找到任何 "HIR"相同"NOR" 或 "HIG"相似"NOR" 的連線使用者！ \n";
	if( !str || str == "" ) str = " 沒有找到任何 "HIR"相同"NOR" ip 的連線使用者！ \n";
	write(BLU"\n<------------------> 檢查 ip Multi-Login <------------------>\n\n"NOR + str +
		CYN"\n-======================- Check okay. -======================-\n\n"NOR);
	return 1;
}

int help(string arg)
{
	object me = this_player();
	if( arg == "checkip" )
	{
		write(@HELP
指令格式﹕checkip

查詢在線上使用者有那些是重覆連線的 ip 。

HELP );
		return 1;
	}
	else return 0;
}

/*
	if( mapp(exits = env->query("exits")) )
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
		{
			if( (int)env->query_door(dirs[i], "status") == DOOR_LOCKED )
			{
				str +="    " + to_chinese(dirs[i])+"邊的"+env->query_door(dirs[i], "name")+"是鎖著的。\n";
				dirs[i] = 0;
			}
			else if( (int)env->query_door(dirs[i], "status") == DOOR_CLOSED )
			{
				str += "    " + to_chinese(dirs[i])+"邊的"+env->query_door(dirs[i], "name")+"是關著的。\n";
				dirs[i] = 0;
			}
		}
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    這裡沒有任何明顯的出路。\n";
		else if( sizeof(dirs)==1 )
			str += "    這裡唯一的出口是 " +HIW+  dirs[0] + NOR + "。\n";
		else
		{
			str += sprintf("    這裡明顯的出口是 ");
			k=sizeof(dirs);
			if(k>2) and="、";
				else and="";
			for(i=0;i<k-2;i++)
			{
				str +=HIW+dirs[i]+NOR+"、";
			}
			str +=HIW+dirs[k-2]+" 和 "+dirs[k-1]+NOR+"。\n";
		}
	} else str += "    這裡沒有任何明顯的出路。\n";
*/