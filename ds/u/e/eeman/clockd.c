// clockd.c
// �o�Ӻ��F��U�ò��w�Ҧ�����ɶ����ʧ@
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
//	int     LT_SEC          ��� (0..59)
//	int     LT_MIN          ���� (0..59)
//	int     LT_HOUR         �p�� (0..23)
//	int     LT_MDAY         ��� (1..31)
//	int     LT_MON          ��� (0..11)
//	int     LT_YEAR         �~�� (�����j�� 1900)
//	int     LT_WDAY         �P���X (0..6)
//	int     LT_YDAY         �@�~�����ĴX�� (0..365)
//	int     LT_GMTOFF       ��L�ªv�ɶ��ۮt����� (UTC)
//	string  LT_ZONE         ���a�ɰϪ��W��
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

//�C�p�ɪ����I����
void every_hour()
{
	string week;
		switch(local[LT_WDAY])
        	{	
        		case 0: week="��"; break;
        		case 1: week="�@"; break;
        		case 2: week="�G"; break;
        		case 3: week="�T"; break;
        		case 4: week="�|"; break;
        		case 5: week="��"; break;
        		case 6: week="��"; break;
        		default: week="??"; break;
        	}
		message("system",sprintf(HIC+"�i�w�ɺ��F�j���I���ɴ��աR�褸%d�~ %d�� %d�� �P��%s "+HIW+"%d[1;5m:[0m"+HIW+"00"+HIC+"�C\n"+NOR,
		local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],week,
		local[LT_HOUR], ),users());

		//�w�ɧ�s����
		RECORD_D->resort_record();
}

//�C�p�ɪ�30������
void per_min_30()
{
	object *user;
	int i;
	
	LOTTERY_D->generate_num();
	message("system",sprintf(HIC+"\n�i�m�����ߡj�� %d ���������X�w���Q�}�X�T���U�쳣�੯�B�����C\n"NOR,LOTTERY_D->query_times()),users());
	
	//�w�ɦ۰ʬ���
	user=users();
	for(i=0;i<sizeof(user);i++)
	{
		tell_object(user[i],"�۰ʦs�ɤ�...�еy��C\n");
		user[i]->force_me("save");
	}

}

// �C 15 ��������	by Shengsan
void per_15_min()
{
	// �έp�Τ��R�W���H��
	RECORD_D->usage_statistics();
}

void clock_23h59m()	// �C�� 23 �I 59 ������
{
	// �C�ѱN USAGE ��W�ƥ�, �H�קK USAGE �ɮ׹L�j
	// �Ӥ��Q���έp���R                       by Shengsan
	RECORD_D->usage_rename_backup();
}

void clock_0() // �b�]12�I05������, �׶}���I�B�z�H�K�L������
{
	int t;
	
	RECORD_D->remove_temp_record();
	
	// Check to auto_reboot . (2 days = 60sec*60min*48hr=171400)
	// �אּ�W�L25�p��. ( �]�N�O����W�L25�p�ɫ᪺���00:00 )
	t = uptime();
	if(t<170000) return;
	else
	{
		call_out("auto_reboot",60);
		message("system",HIC+
		"\n\n"+
		"\t��M���g���j�@�A�ѪŤ����M�X�{�@�D�����ӥ��j�����v�A�åB���_�ֳt���ȵۡI�I\n "+
		HIW+
		"\n\t  �L�ư{�q�q�Ѧӭ��A�䤤�@�D�{�q�ǽT���A���F�o��H�[���֪Z��a�q�����ߡI\n\n"+
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

	//����
	if(pre_min==59 && current_min==0)
	{
		every_hour();
	}
	else
	if(pre_min==29 && current_min==30) //�C��30����
	{
		per_min_30();
	}
	else
	if((pre_min==14 && current_min==15) ||
	   (pre_min==29 && current_min==30) ||
   	   (pre_min==44 && current_min==45) ||
	   (pre_min==59 && current_min==0)  )
	{
		per_15_min();		// �C 15 ���� by Shengsan
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
