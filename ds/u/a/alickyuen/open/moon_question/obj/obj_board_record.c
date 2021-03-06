/*	record.c			*
 *	write by -alickyuen@ds-		*
 *	部份程式部份來自acme:p		*/

#include <ansi2.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;

int do_record(object me);
int reset_record();
string do_list();

void create()
{
	set_name(HIM"『燈謎競逐』遊戲排行榜"NOR, ({ "the list of game record", "record", "list" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
//	set("long", ""+this_object()->do_list()+"");
	set("long", " ");

	setup();
	if( !restore() )	game_record=([]);
}

string query_save_file() 
{
	return DATA_DIR + "game/moon_question";
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return; // 若沒 me 又判斷userp的話會出bug -alickyuen@ds-
	
//	do_record(me);
	
	add_action("do_look", "look");
//        add_action("set_record", "set");
}
	 
int do_record(object me)
{
	string id;
	id=getuid(me);

	if( !mapp(game_record) ) game_record=([]);

	game_record[id]=me->query("game/moon_question");
	this_object()->save();
	return 1;
}

int set_record(string arg)
{
	string id;
//	int score;

	if( !wizardp(this_player()) ) return notify_fail("wrong\n");

	if( !mapp(game_record) ) game_record=([]);

//	if( sscanf(arg, "%s to %s", id, score) !=2 ) return notify_fail("wrong\n");
	id = arg;
	game_record[id]=this_player()->query("game/moon_question");
	this_object()->save();
	return 1;
}

int reset_record()
{
	game_record=([]);
	this_object()->save();

	write("清除完成！\n");

	return 1;
}

int do_look(string arg)
{
	if ( arg == "list" || arg == "record" )
	{
		return write(do_list());
	}
}

string do_list()
{
	float *score, swap;
	int i, j, x;
	string *ppl, msg, user;

	if( !game_record )		return "目前還有任何紀錄！\n";
	if( !mapp(game_record) )	return "目前還沒有任何紀錄！\n";

	ppl=keys(game_record);
	score=values(game_record);

	i=sizeof(score);

	for(j=i-1;j>0;j--)
	{
		for(x=1;x<=j;x++)
		{
			if( score[x-1] > score[x] )
			{
				swap=score[x-1];
				score[x-1]=score[x];
				score[x]=swap;
				user=ppl[x-1];
				ppl[x-1]=ppl[x];
				ppl[x]=user;
			}
		}
	}
	i=sizeof(ppl);
	j=0;
	msg= HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	msg += HIG"\t\t\t☆中秋節特別活動『燈謎競逐』分數排行榜☆\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	while( i-- )
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) msg+= HIC;
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
			msg+=sprintf("第%4s名 ---- %13s 目前共 %3d 點得分",
				chinese_number(j),ppl[i],game_record[ppl[i]]);

			switch( j )
			{
				case 1: msg+= HIM""BLINK" (超級大獎：上名人堂＆自訂 Save Eq 一件)\n"; break;
				case 2..5: msg+= HIY" (大獎：隨機 Save Eq 一件)\n"; break;
				default: msg+= HIR" (參加獎：錢、Exp)\n"; break;
                		}
		}

		msg+=NOR;
	}       
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}
