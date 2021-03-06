/*
  Name: /obj/board/summergame_b.c
  Copyright: DS
  Author: Alickyuen
  Date: 12/09/05 00:54
  Description: 2005暑期遊戲節目 
*/

#include <ansi2.h>
#define PATH "/open/world1/alickyuen/2005summer/"

inherit ITEM;
inherit F_UNIQUE;
inherit F_SAVE;

mapping game_record;
int popc, pearlc, dollc, moneyc, eqc, rubbishc;
static string *drawing = ({ });
int reset_record();
int clear_list();
int set_record(string arg);
varargs mixed query_gift(string type);
string do_list();
varargs string query_record(string arg);

void create()
{
	set_name(HIM"『2005夏日殺戮』遊戲排行榜"NOR, ({ "the list of game record", "record", "list" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
//	set("long", ""+this_object()->do_list()+"");
	set("long", " ");

	setup();
	if( !restore() )	game_record=([]);
	call_out("clear_list", 1800);
}

string query_save_file() 
{
	return DATA_DIR + "game/summer_game";
}

int clear_list()
{
	remove_call_out("clear_list");

	drawing = ({ });

	call_out("clear_list", 1800);

	return sizeof(drawing);
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return; // 若沒 me 又判斷userp的話會出bug -alickyuen@ds-
	
	add_action("do_look", "look");
	add_action("do_draw", "draw");
}
	 
varargs int do_record(object me, int score)
{
	string id;

	if( !me || !objectp(me) ) return 3;

	if( !score || !intp(score) ) return 4;

	id=getuid(me);

	if( !previous_object() || file_name(previous_object()) != COMBAT_D ) return 2;

	if( undefinedp(game_record) ) game_record=([]);

	if( undefinedp(game_record[id]) ) game_record[id]=score;
	else game_record[id] += score;
	
	this_object()->save();
	return 1;
}

int set_record(string arg)
{
	string id;
	int score;

	if( this_player() 
		&& wizardp(this_player())
		&& wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("for admin only.\n");

	if( !mapp(game_record) ) game_record=([]);

	if( sscanf(arg, "%s to %d", id, score) !=2 ) return notify_fail("syntax: player to score\n");
	game_record[id]=score;
	this_object()->save();
	return 1;
}

int test(string arg)
{
	if( !wizardp(this_player()) || wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("for wiz only.\n");

	moneyc= 0;
	this_object()->save();
	return 1;
}

int reset_record()
{
	if( !wizardp(this_player()) || wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("for wiz only.\n");

//	game_record=([]);
	popc = 0;
	pearlc = 0;
	dollc = 0;
	moneyc = 0;
	eqc = 0;
	rubbishc = 0;

	this_object()->save();

	write("清除完成！\n");

	return 1;
}

int do_look(string arg)
{
	if ( arg == "list" || arg == "record" )
	{
/*		return write(@HELP
2005 年度頂級暑假特別遊戲節目－『夏日殺戮』將於這個炎炎的假期隆重登場！

比賽日期：
　　 7 月 9 日 (星期六) 00:00 － 8 月 31 日 (星期三) 24:00 
(以 ds 的 指令 date 的時間為準喔~~~~!!)

遊戲玩法：
　　玩法簡單，打 mob 就能賺點∼ 賺點方法如下:
　　(1) 若玩家等級大於 mob 等級, 則會隨機加 0 ~ 1 點
　　(2) 若玩家等級小於 mob 等級, 則會以 mob 的 level 值計算 .. 4 level = 1 點 喔!!

遊戲獎品：
　　頭五名均有獲得 save eq 的機會，∼其他參加者當然也有安慰獎...就是你參與過程所
賺取的金錢和經驗值啦 XD  ~~~ 

各位加油努力~

Alickyuen @ The Dream of Seven 2005 

HELP
+do_list()
*/
		return write(@HELP
2005 年度頂級暑假特別遊戲節目－『夏日殺戮』已完滿結束，多謝各位參與。

各位沒得到大獎的參賽者亦有參加抽獎機會，抽獎時間為：
	2005 年 9 月 13 日 - 2005 年 9 月 30 日

抽獎獎品豐富，先抽先得[ 指令: draw ]，現時還未被抽到之獎品包括： 

HELP
+query_gift()
+query_record()
		);
	}
}

int do_draw(string arg)
{
	int chance = random(1000); // almost 1000 drawing chances
	string id = geteuid(this_player());
	return notify_fail("[2005 夏日殺戮] 抽獎活動已經完結，獎品將於稍後頒發。\n");
	restore();

	if( member_array(this_player()->query("id"), drawing) != -1 )
		return notify_fail(HIR"[2005 夏日殺戮]"NOR YEL"嘿，不要心急啦∼每半小時才能抽獎一次喔！\n"NOR);

	if( id == "ayumi"
	|| id == "watch" 
	|| id == "bamboo" 
	|| id == "lemonlin"
	|| id == "opek" )
		return notify_fail(HIR"[2005 夏日殺戮]"NOR" 恭喜你，你是 Save EQ 大獎得獎者！\n");

	if( to_int(query_record(this_player()->query("id"))) < 100 )
		return notify_fail(HIR"[2005 夏日殺戮]"NOR"你已經用完所有抽獎機會了~~! \n"NOR);

	set_record(this_player()->query("id")+" to "+
		(to_int(query_record(this_player()->query("id")))-100));

	drawing += ({ this_player()->query("id") });

//	popc, pearlc, dollc, moneyc, eqc, rubbishc;
	switch(chance)
	{
		case 333:
			if( query_gift("paper") )
			{
				if( eqc <= 0 ) eqc = 1;
				else eqc += 1;
				rm(PATH+"eq"+(eqc<10?"0"+eqc:""+eqc));
				log_file("area/2005summer", this_player()->short(1)+"抽中 paper. \n");
				write(HIR"[2005 夏日殺戮]"BLINK HIY"恭喜你! 你抽中了白紙~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 222..223:
			if( query_gift("pearl") )
			{
				if( pearlc <= 0 ) pearlc = 1;
				else pearlc += 1;
				rm(PATH+"pearl"+(pearlc<10?"0"+pearlc:""+pearlc));
				log_file("area/2005summer", this_player()->short(1)+"抽中 pearl. \n");
				write(HIR"[2005 夏日殺戮]"BLINK HIY"恭喜你! 你抽中了螢光棒~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 111..113:
			if( query_gift("doll") )
			{
				if( dollc <= 0 ) dollc = 1;
				else dollc += 1;
				rm(PATH+"doll"+(dollc<10?"0"+dollc:""+dollc));
				log_file("area/2005summer", this_player()->short(1)+"抽中 doll. \n");
				write(HIR"[2005 夏日殺戮]"BLINK HIY"恭喜你! 你抽中了替死娃娃~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 101..110:
			if( query_gift("rubbish") )
			{
				if( rubbishc <= 0 ) rubbishc = 1;
				else rubbishc += 1;
				rm(PATH+"rubbish"+(rubbishc<10?"0"+rubbishc:""+rubbishc));
				log_file("area/2005summer", this_player()->short(1)+"抽中 rubbish. \n");
				write(HIR"[2005 夏日殺戮]"BLINK HIY"恭喜你! 你抽中了洋娃娃~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 401..500:
			if( query_gift("pop") )
			{
				if( popc <= 0 ) popc = 1;
				else popc += 1;
				rm(PATH+"pop"+(popc<10?"0"+popc:""+popc));
				log_file("area/2005summer", this_player()->short(1)+"抽中 pop. \n");
				write(HIR"[2005 夏日殺戮]"BLINK HIY"恭喜你! 你抽中了聲望獎~~! \n"NOR); 
				this_object()->save();
				break;
			}
		case 501..700:
			if( query_gift("money") )
			{
				if( moneyc <= 0 ) moneyc = 1;
				else moneyc += 1;
				rm(PATH+"money"+(moneyc<10?"0"+moneyc:""+moneyc));
				log_file("area/2005summer", this_player()->short(1)+"抽中 money. \n");
				write(HIR"[2005 夏日殺戮]"BLINK HIY"恭喜你! 你抽中了金錢獎~~! \n"NOR); 
				this_object()->save();
				break;
			}
		default:
				write(HIR"[2005 夏日殺戮] 別灰心~!! 雖然你這次並沒有抽中任何東西~~.. \n"NOR); 
			break;
	}	
	
	return 1;
}

varargs mixed query_gift(string type)
{
	mixed *file;
	int i;
	int pop, pearl, doll, money, eq, rubbish;
	string *gifts;
        
	file = get_dir(PATH, -1); 
	gifts = ({ });

	for(i = 0; i < sizeof(file); i++)
	{
		gifts += ({ file[i][0] });
	}

	pop = 0;
	pearl = 0;
	doll = 0;
	money = 0;
	eq = 0;
	rubbish = 0;

	foreach(string id in gifts)
	{
		if( sscanf(id, "pop%d", i) == 1 )
			pop += 1;
		else if( sscanf(id, "pearl%d", i) == 1 )
			pearl += 1;
		else if( sscanf(id, "doll%d", i) == 1 )
			doll += 1;
		else if( sscanf(id, "money%d", i) == 1 )
			money += 1;
		else if( sscanf(id, "eq%d", i) == 1 )
			eq += 1;
		else if( sscanf(id, "rubbish%d", i) == 1 )
			rubbish += 1;	
	}

	if( type ) switch(type) {
		case "pop" : return pop;
		case "money" : return money;
		case "doll" : return doll;
		case "rubbish" : return rubbish;
		case "paper" : return eq;
		case "pearl" : return pearl;
		default: return "none";
	}

	return HIC"\t SAVE EQ - 白紙(white paper) "NOR": "+ eq +" 份 (共 1 份)\n"
		+ HIC"\t SAVE EQ - 螢光棒(fluorescent stick)"NOR" : "+ pearl +" 份 (共 2 份)\n"
		+ HIC"\t SAVE EQ - 替死娃娃(death doll)"NOR" : "+ doll +" 份 (共 3 份)\n"
		+ HIC"\t SAVE EQ - 洋娃娃(doll) "NOR": "+ rubbish +" 份 (共 10 份)\n"
		+ HIC"\t 聲望獎  - 聲望 250 點 "NOR": "+ pop +" 份 (共 100 份)\n"
		+ HIC"\t 金錢獎  - 古幣 10000 枚 "NOR": "+ money +" 份 (共 200 份)\n\n";
}

varargs string query_record(string arg)
{
	object me;
	string id;

	restore();

	if( !game_record )		return "目前還沒有任何紀錄！\n";
	if( !mapp(game_record) )	return "目前還沒有任何紀錄！\n";

	me = this_player();
	if( !arg ) id = geteuid(me);
	else id = arg;

	if( id == "ayumi"
	|| id == "watch" 
	|| id == "bamboo" 
	|| id == "lemonlin"
	|| id == "opek" )
		return HIR"[2005 夏日殺戮]"NOR" 恭喜你，你是 Save EQ 大獎得獎者！\n";
	
	if( arg ) return game_record[id];

	if( game_record[id] >= 100 )
		return HIR"[2005 夏日殺戮]"NOR" 你目前還有 "+game_record[id]/100+" 次抽獎機會。\n";

	return HIR"[2005 夏日殺戮]"NOR" 多謝你參與是次活動。\n";
}

string do_list()
{
	float *score, swap;
	int i, j, x;
	int flag;
	string *ppl, msg, user;

	restore();
	
	if( !game_record )		return "目前還沒有任何紀錄！\n";
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
	msg += HIY"\t\t\t☆活動"HIR"『2005夏日殺戮』"HIY"分數排行榜(1-25名)☆\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	if( !i ) msg += "\t\t\t\t\t暫無紀錄\n"; 
	
	while( i-- )
// && j < 25 ) 
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) 
		{ msg += HIC; flag = 1; }
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
			msg+=sprintf("第%4d名 ---- %13s 目前共 %5d 點得分",
				j,ppl[i],game_record[ppl[i]]);

			switch( j )
			{
				case 1: msg+= HIM""BLINK" (超級大獎：自訂 Save Eq 一件)"; break;
				case 2..5: msg+= HIY" (大獎：大會指定 Save Eq 一件)"; break;
				default:
					if( game_record[ppl[i]] >= 100 ) msg+= HIW" ("+game_record[ppl[i]]/100+" 次抽獎機會)";
					break;
			}
			msg += "\n"NOR;
		}
	}
	if( !flag && game_record[getuid(this_player())] > 0 ) 
	{
		msg+=sprintf(HIC"第%|4s名 ---- %13s 目前共 %5d 點得分",
		"n",geteuid(this_player()),game_record[geteuid(this_player())]);
		msg += "\n"NOR;
	}
         
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}
