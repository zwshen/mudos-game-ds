/*	File		: "/adm/daemons/matchd.c"	*
 *	Author		: "alickyuen@ds"		*
 *	Desc		: "每月一次比武大會主系統"	*
 *	Last Modify	: "2002年5月30日"		*/

#include <ansi2.h>

/*　４個區域的起始點　*/
#define AREA_A "/open/world1/alickyuen/match/area-a/map_7_14.c"	// map_1_1
#define AREA_B "/open/world1/alickyuen/match/area-b/map_8_1.c"	// map_8_11
#define AREA_C "/open/world1/alickyuen/match/area-c/map_8_14.c"	// map_1_1
#define AREA_D "/open/world1/alickyuen/match/area-d/map_5_3.c"	// map_1_1
/*　入口及出口　*/
#define ENTER_ROOM "/open/world1/alickyuen/match/entrance.c"
#define EXIT_ROOM "/open/world1/alickyuen/match/exit.c"

#define DOLL "/open/world1/alickyuen/match/obj/doll.c"

inherit F_SAVE;
inherit F_DBASE;

mapping game_record;	// 記錄勝利者
mapping game_list;	// 記錄報名名單
mapping play_list;	// 記錄比武中的名單
int num1 = 0;		// 監察有沒有TEAM A的人進場比武
int num2 = 0;		// 監察有沒有TEAM B的人進場比武
int num3 = 0;		// 監察有沒有TEAM C的人進場比武
int num4 = 0;		// 監察有沒有TEAM D的人進場比武
int count1 = 0;		// 記錄報名TEAM A的人數
int count2 = 0;		// 記錄報名TEAM B的人數
int count3 = 0;		// 記錄報名TEAM C的人數
int count4 = 0;		// 記錄報名TEAM D的人數
int fail = 0;		// 作廢記錄
int show = 0;		// 記錄公告次數
int okay = 1;		// 標記報名狀態
int reset_record();	// 重設報名名單
string do_list();	// 報名名單
void announce();	// 公告
int record(object me);	// 記錄勝利
int enter(object me);	// 進入比武區域
int check(object me);	// 查探比武進行的記錄
int start();		// 比武開始

void create()
{
	seteuid(getuid());
	set("name", "比賽精靈");
	set("id", "matchd");

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}
}

string query_save_file() 
{
	return DATA_DIR + "game/monthly_pk";
}

int sign_list(string team)
{
	object me;
	string id;
	int group, no = 0;

	me = this_player();

//	if( wiz_level(me) < wiz_level("(admin)") ) 
//		return notify_fail("巫師不能參加是次比賽。\n");

	if( okay != 1 )
                return notify_fail(HIR"現在已經停止接受報名，報名時間是每日之早上十二時正至晚上七時正。\n"NOR);

	if( team !="A" && team !="B" && team !="C" && team !="D" )
		return notify_fail("你要加入哪一組參賽？（A、B、C、D？）\n");

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	switch(team)
	{
		case "A":
			if( count1 >= 10 ) 
				return notify_fail(team+"組已經滿額了，請報共他組別吧。\n");
			else count1 += 1;
		break;
		case "B":
			if( count2 >= 10 ) 
				return notify_fail(team+"組已經滿額了，請報共他組別吧。\n");
			else count2 += 1;
		break;
		case "C":
			if( count3 >= 10 ) 
				return notify_fail(team+"組已經滿額了，請報共他組別吧。\n");
			else count3 += 1;
		break;
		case "D":
			if( count4 >= 10 ) 
				return notify_fail(team+"組已經滿額了，請報共他組別吧。\n");
			else count4 += 1;
		break;
		default:
			return notify_fail("發生錯誤！請與巫師Alickyuen聯絡或Report。\n");
		break;	
	}

	id = me->query("id");

	if( game_list[id] ) 
		return notify_fail("你已經報名了。\n");

	game_list[id] = team;

	this_object()->save();

	message_vision(HIW"$N寫了『"+id+"』在板上的報名欄上。\n"NOR, me);

	return 1;
}

int reset_record()
{
/*
	if( wiz_level(this_player()) < wiz_level("(admin)") )
		return notify_fail("你的巫師等級不夠。\n");
*/

	game_list = ([]);
	play_list = ([]);
	play_list["A"] = ({});
	play_list["B"] = ({});
	play_list["C"] = ({});
	play_list["D"] = ({});
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	count1 = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;	
	fail = 0;

	this_object()->save();

	write(HIW"參賽者名單清除完成！\n"NOR);

	return 1;
}

string do_list()
{
	float *team;
	string *ppl, msg;
	string team1, team2, team3, team4;
	int i;

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	msg = HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	msg += HIG"\t\t\t☆『夢幻比武大會』參賽者與及組別名單☆\n";
	msg +=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	if( !game_list )		
	{
		msg += HIY"∼目前還沒有任何玩家報名，請從速用『sign』指令參加∼\n"NOR;
	} else if( !mapp(game_list) ) {
		msg += "沒有任何紀錄，請向相關巫師回報。\n";
	} else {
		ppl = keys(game_list);
		team = values(game_list);
		team1 = HIC"Ａ組名單："NOR;
		team2 = HIC"Ｂ組名單："NOR;
		team3 = HIC"Ｃ組名單："NOR;
		team4 = HIC"Ｄ組名單："NOR;

		for(i=0;i<sizeof(ppl);i++)
		{
			switch(team[i])
			{
				case "A":
					team1 += CYN""+ppl[i]+"，";
				break;
				case "B":
					team2 += CYN""+ppl[i]+"，";
				break;
				case "C":
					team3 += CYN""+ppl[i]+"，";
				break;
				case "D":
					team4 += CYN""+ppl[i]+"，";
				break;
				default:
				break;
			}
		}
		msg += team1+"\n"NOR+team2+"\n"NOR+team3+"\n"NOR+team4+"\n"NOR;
	}       
	msg += HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}

void announce()
{
        string msg, time, date, hour;

	time = ctime(time());
	date = time[8..9];
	hour = time[11..12];
      return; // 暫時關閉 add by tmr 2006/11/07

//        if( to_int(date) == 5 )
/*
        if( to_int(hour) == 20 )
	{
		msg = HIW"\n【夢幻七域比武大會】請各參賽者準時在今天下午１２時正在比武場入口集合。\n\n"NOR;
		okay = 0;
	} else
*/
	if( to_int(hour) < 24 && to_int(hour) >= 20 )
	{
		okay = 2;
		return;
	}
//        if( to_int(date) < 5 && to_int(date) > 2 ) 
        if( to_int(hour) > 18 )
	{
                msg = BEEP+HIW"\n【夢幻七域比武大會】將於下午八時舉行，請各參賽者於八時前到達比武場入口，大會將會根據date時間準時於八時開始。\n\n"NOR;
//                msg = HIW"\n【夢幻七域比武大會】現已停止接受報名，比賽將於每月之第五日舉行。\n\n"NOR;
		okay = 2;
	} else 	{
		msg = HIW"\n【夢幻七域比武大會】現已接受報名，請從速到比武場登記。\n\n"NOR;
		okay = 1;
	}

	message("system", msg, users());

	this_object()->save();

	return;
}

int enter(object me)
{
	string id, *area, *list;
	object room;

	id = me->query("id");

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	if( !game_list[id] )
		return notify_fail("你並不是這次比武大會的參賽者。\n");

	if( sizeof(play_list[(game_list[id])]) < 1 )
	{
		play_list[(game_list[id])] = ({ id });
	} else {
		play_list[(game_list[id])] += ({ id });
	}

	area = game_list[id];

	switch(area)
	{
		case "A":
			room = load_object(AREA_A);
			num1 = 1;
		break;
		case "B":
			room = load_object(AREA_B);
			num2 = 1;
		break;
		case "C":
			room = load_object(AREA_C);
			num3 = 1;
		break;
		case "D":
			room = load_object(AREA_D);
			num4 = 1;
		break;
		default:
		break;
	}
/*
	tell_object(me, HIC"工作人員發配了一隻替死娃娃給你。\n"NOR);

	new(DOLL)->move(me);
*/
	me->move(room);

	me->set_temp("match_player", 1);

	this_object()->save();

	return 1;
}

int check(object me)
{
	string id, win;
	int noa, nob, noc, nod;

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	id = me->query("id");

//	map_delete(play_list, id);

	play_list["A"] -= ({ id });
	play_list["B"] -= ({ id });
	play_list["C"] -= ({ id });
	play_list["D"] -= ({ id });

	me->delete_temp("match_player");

	if( sizeof(play_list["A"]) ) 
	{	
		noa = 1;
		win = "A";
	}
	else noa = 0;

	if( sizeof(play_list["B"]) ) 
	{
		nob = 1;
		win = "B";
	}
	else nob = 0;

	if( sizeof(play_list["C"]) )
	{
		noc = 1;
		win = "C";
	}
	else noc = 0;

	if( sizeof(play_list["D"]) )
	{
		nod = 1;
		win = "D";
	}
	else nod = 0;

	if( (noa+nob+noc+nod) == 1 )
	{
		foreach(string ppl in play_list[win])
		{
			if( !fail )	find_player(ppl)->set_temp("match_winner", 1);
			if( file_name(environment(find_player(ppl))) != EXIT_ROOM )
			{
				find_player(ppl)->move(EXIT_ROOM);
			}
		}
		if( !fail && !show )
		{
			message("system", HIW"\n【夢幻七域比武大會】比武現已結束，多謝各位參賽者踴躍支持。\n\n"NOR, users());
			show = 1;
		}
		this_object()->reset_record();
	}

	this_object()->save();

	return 1;
}

int record(object me)
{
	string time, date;

	if( !restore() )
	{
		if( !game_record )
			game_record = ([]);
		if( !game_list )
			game_list = ([]);
		if( !play_list )
		{
			play_list = ([]);
			play_list["A"] = ({});
			play_list["B"] = ({});
			play_list["C"] = ({});
			play_list["D"] = ({});
		}
	}

	time = ctime(time());

	date = time[4..6]+"-"+time[8..9]+"-"+time[20..23];
	
	if( !game_record[date] ) game_record[date] = ({ });
	game_record[date] += ({ me->query("id") });	

	me->delete_temp("match_winner");

	message("system", HIW"【"HIG"比武通告"HIW"】"HIG""+me->query("name")+NOR HIG"("+me->query("id")+HIG")在這次比武中勝出了！\n\n"NOR, users());


	this_object()->save();

	return 1;
}

int start()
{
	load_object(ENTER_ROOM)->start_game();

	message("system", HIW"\n【夢幻七域比武大會】現在開始！！！\n\n"NOR, users());

	show = 0;
	fail = 0;

	if( (num1+num2+num3+num4) == 1 )
	{
		string *list;

		list = play_list["A"]+play_list["B"]+play_list["C"]+play_list["D"];

		fail = 1;

		foreach(string ppl in list)
		{
			if( file_name(environment(find_player(ppl))) != EXIT_ROOM )
			{
				find_player(ppl)->move(EXIT_ROOM);
			}
		}
                this_object()->reset_record();
		message("system", HIW"\n【夢幻七域比武大會】由於人數不足，本次比武大會作廢。\n\n"NOR, users());
	}
	this_object()->save();
}
