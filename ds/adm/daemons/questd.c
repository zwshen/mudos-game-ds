// natured.c
// #pragma save_binary
#include <ansi.h>
#define BASIC_PAGES 3
#define QUEST_LIST 3
inherit F_DBASE;

mapping quests = ([
	"SadSworder":([ //questID
		"page" : "page4",
		"title": "傷心劍客",
		"steps": 8, //目前沒用
	]),
	"LostRing":([ //questID
		"page" : "page5",
		"title": "遺失的回憶",
		"steps": 2, 
	]),
]);
void create()
{
	seteuid(getuid());
}

string show_page(int index,object notebook)
{
	string out="",*questname;
	mapping quest=([]);
          int i,j;
	if( index == QUEST_LIST )
	{
		questname = keys(quests);
		quest = notebook->query_quests();
		out = "任務名稱                  完成度\n"+
		      "================================\n";
		for(i=0;i<sizeof(questname);i++)
		{
			out+=quests[questname[i]]["title"];
			for(j=0;j<(25-strlen(quests[questname[i]]["title"]));j++) out+=".";
			if(!undefinedp(quest[questname[i]]) && quest[questname[i]]==1) out+="   完成";
			else out+=" 未完成";
			out+="\n";
		}
		out+="================================\n";
		return out;
	}
        if( file_size("/doc/note/page"+index)>0 )
	{
	    out = read_file("/doc/note/page"+index );
	} else out="這一頁是空白的\n";
	return out;
}

int query_maxpage(object notebook)
{
	return BASIC_PAGES+sizeof(quests);
}

int check_quest(string playerid,string questid)
{
	return 0;	
}
string find_quest_page(string questid)
{
	if(undefinedp(quests[questid])) return "";
	else if(undefinedp(quests[questid]["page"])) return "";
	return quests[questid]["page"];
}
int do_save(object notebook)
{
	return notebook->save();
}

void delay_add_mytemp(object me,string arg,int dur,int time)
{
	if(!me) return;
	call_out("add_mytemp",time,me,arg,dur);
	return;
}

void add_mytemp(object me,string arg,int dur)
{
	if(!me) return;
	me->add_temp(arg,dur);
	return;
}

void delay_del_mytemp(object me,string arg,int time)
{
	if(!me) return;
	call_out("del_mytemp",time,me,arg);
	return;
}

void del_mytemp(object me,string arg)
{
	if(!me) return;
	me->delete_temp(arg);
	return;
}
