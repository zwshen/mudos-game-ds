// clockd.c
// 這個精靈協助並統籌所有關於時間的動作
// Luky@DS 1999
//
//	#define LT_SEC          0
//	#define LT_MIN          1
//	#define LT_HOUR         2
//	#define LT_MDAY         3
//	#define LT_MON          4
//	#define LT_YEAR         5
//	#define LT_WDAY         6
//	#define LT_YDAY         7
//	#define LT_GMTOFF       8
//	#define LT_ZONE         9
//	
//	int     LT_SEC          秒數 (0..59)
//	int     LT_MIN          分鐘 (0..59)
//	int     LT_HOUR         小時 (0..23)
//	int     LT_MDAY         日數 (1..31)
//	int     LT_MON          月數 (0..11)
//	int     LT_YEAR         年份 (必須大於 1900)
//	int     LT_WDAY         星期幾 (0..6)
//	int     LT_YDAY         一年中的第幾天 (0..365)
//	int     LT_GMTOFF       格林威治時間相差的秒數 (UTC)
//	string  LT_ZONE         本地時區的名稱
// #pragma save_binary
#include <localtime.h>
#include <ansi.h>
#include <login.h>
#include <obj.h>

inherit F_DBASE;

static int current_week;
static int current_hour;
static int current_min;
static int current_week;

static int current_game_month;
static int current_game_day;
static int current_game_week;
static int current_game_hour;

mixed *local,*game_time;

void init_time();
void auto_reboot()
{
	object npc;
	remove_call_out("auto_reboot");
	npc = new(NPC_REBOOT);
	npc->set("no_kill",1);
	npc->move(START_ROOM);
	npc->start_shutdown();
	return;
}

void create()
{
	seteuid(getuid());
	init_time();
}

//每小時的整點執行
void every_hour()
{
	string week;
		switch(local[LT_WDAY])
        	{	
        		case 0: week="日"; break;
        		case 1: week="一"; break;
        		case 2: week="二"; break;
        		case 3: week="三"; break;
        		case 4: week="四"; break;
        		case 5: week="五"; break;
        		case 6: week="六"; break;
        		default: week="??"; break;
        	}
		message("system",sprintf(HIC+"【定時精靈】整點報時測試﹕西元%d年 %d月 %d日 星期%s "+HIW+"%d[1;5m:[0m"+HIW+"00"+HIC+"。\n"+NOR,
		local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],week,
		local[LT_HOUR], ),users());

		//定時更新紀錄
		RECORD_D->resort_record();
}

//每小時的30分執行
void per_min_30()
{
	object *user;
	int i;
	
	LOTTERY_D->generate_num();
	message("system",sprintf(HIC+"\n【彩卷中心】第 %d 期中獎號碼已順利開出﹗祝各位都能幸運中獎。\n"NOR,LOTTERY_D->query_times()),users());
	
	//定時自動紀錄
	user=users();
	for(i=0;i<sizeof(user);i++)
	{
		tell_object(user[i],"自動存檔中...請稍後。\n");
		user[i]->force_me("save");
	}

}

// 每 15 分鐘執行	by Shengsan
void per_15_min()
{
	// 統計及分析上站人次
	RECORD_D->usage_statistics();
}

void clock_23h59m()	// 每天 23 點 59 分執行
{
	// 每天將 USAGE 更名備份, 以避免 USAGE 檔案過大
	// 而不利做統計分析                       by Shengsan
	RECORD_D->usage_rename_backup();
}

void clock_0() // 半夜12點05分執行, 避開整點處理以免過長執行
{
	int t;
	
	RECORD_D->remove_temp_record();
	
	// Check to auto_reboot . (2 days = 60sec*60min*48hr=171400)
	// 改為超過25小時. ( 也就是執行超過25小時後的凌晨00:00 )
	t = uptime();
	if(t<170000) return;
	else
	{
		call_out("auto_reboot",60);
		message("system",HIC+
		"\n\n"+
		"\t突然間狂風大作，天空中赫然出現一道神秘而巨大的陰影，並且不斷快速膨脹著！！\n "+
		HIW+
		"\n\t  無數閃電從天而降，其中一道閃電準確的劈中了廢棄以久的核武基地電腦中心！\n\n"+
		NOR
		,users());
		return;
	}
}

void clock_1()
{

}
void clock_2() { }
void clock_3() { }
void clock_4() { }
void clock_5() { }
void clock_6() { }
void clock_7() { }
void clock_8() { }
void clock_9() { }
void clock_10() { }
void clock_11() { }
void clock_12()
{
//	RECORD_D->remove_temp_record(); 
}
void clock_13() { }
void clock_14() { }
void clock_15() { }
void clock_16() { }
void clock_17() { }
void clock_18() { }
void clock_19() { }
void clock_20() { }
void clock_21() { }
void clock_22() { }
void clock_23() { }

void init_time()
{
	// Get time of today.
	local = localtime(REAL_TIME_TICK);
	current_week = local[LT_WDAY]; //0~6
	current_hour = local[LT_HOUR]; //0~23
	current_min = local[LT_MIN];   //0~59


	// Get time of today.
	game_time = localtime(GAME_TIME_TICK);
	current_game_month= game_time[LT_MON]; //0~11
	current_game_day = game_time[LT_MDAY]; //1~31
	current_game_week = game_time[LT_WDAY]; //0~6
	current_game_hour = game_time[LT_HOUR];   //0~23

	call_out("update_time",60-game_time[LT_MIN]);
}

mixed query_game_time(int a)
{
	mixed *game_time;
	game_time = localtime(GAME_TIME_TICK);
	return game_time;
}

void update_time()
{
	int pre_week,pre_hour,pre_min,pre_game_month,pre_game_day,pre_game_week,pre_game_hour;
	string week;

	remove_call_out("update_time");
	pre_week=current_week;
	pre_hour=current_hour;
	pre_min=current_min;
	
	pre_game_month=current_game_month;
	pre_game_day=current_game_day;
	pre_game_week=current_game_week;
	pre_game_hour=current_game_hour;
	
	// Get REAL time of today.
	local = localtime(REAL_TIME_TICK);
	current_week = local[LT_WDAY]; //0~6
	current_hour = local[LT_HOUR]; //0~23
	current_min = local[LT_MIN];   //0~59

	// Get time of GAME.
	game_time = localtime(GAME_TIME_TICK);
	current_game_month= game_time[LT_MON]; //0~11
	current_game_day = game_time[LT_MDAY]; //1~31
	current_game_week = game_time[LT_WDAY]; //0~6
	current_game_hour = game_time[LT_HOUR];   //0~23
	
	if( current_hour == 23 && pre_min==58 && current_min==59)
		clock_23h59m();
		
	if(pre_game_hour!=current_game_hour)
	{
		switch(current_game_hour)
		{
			case 4:
				NATURE_D->update_day_phase(DAWN_PHASE);
				break;
			case 5:
				NATURE_D->update_day_phase(SUNRISE_PHASE);
				break;
			case 7:
				NATURE_D->update_day_phase(MORNING_PHASE);
				break;
			case 12:
				NATURE_D->update_day_phase(NOON_PHASE);
				break;
			case 16:
				NATURE_D->update_day_phase(AFTERNOON_PHASE);
				break;
			case 19:
				NATURE_D->update_day_phase(EVENING_PHASE);
				break;
			case 21:
				NATURE_D->update_day_phase(NIGHT_PHASE);
				break;
			case 0:
				NATURE_D->update_day_phase(MIDNIGHT_PHASE);
				break;
			default:
				break;
		}
	}

	//測試
	if(pre_min==59 && current_min==0)
	{
		every_hour();
	}
	else
	if(pre_min==29 && current_min==30) //每個30分時
	{
		per_min_30();
	}
	else
	if((pre_min==14 && current_min==15) ||
	   (pre_min==29 && current_min==30) ||
   	   (pre_min==44 && current_min==45) ||
	   (pre_min==59 && current_min==0)  )
	{
		per_15_min();		// 每 15 分鐘 by Shengsan
	}
	
	if(pre_min==4 && current_min==5)
	{
		switch(current_hour)
		{
			case 0: clock_0();
				break;
			case 1:	clock_1();
				break;
			case 2: clock_2();
				break;
			case 3: clock_3();
				break;
			case 4: clock_4();
				break;
			case 5: clock_5();
				break;
			case 6: clock_6();
				break;
			case 7: clock_7();
				break;
			case 8: clock_8();
				break;
			case 9: clock_9();
				break;
			case 10: clock_10();
				break;
			case 11: clock_11();
				break;
			case 12: clock_12();
				break;
			case 13: clock_13();
				break;
			case 14: clock_14();
				break;
			case 15: clock_15();
				break;
			case 16: clock_16();
				break;
			case 17: clock_17();
				break;
			case 18: clock_18();
				break;
			case 19: clock_19();
				break;
			case 20: clock_20();
				break;
			case 21: clock_21();
				break;
			case 22: clock_22();
				break;
			case 23: clock_23();
				break;

			default:
				break;
		}
	} 
	call_out("update_time",60-game_time[LT_MIN]);
	return;
}
