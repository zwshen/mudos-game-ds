// natured.c
// #pragma save_binary
#include <localtime.h>
#include <ansi.h>
#define TIME_TICK ((time()%(60*24*3600))*365)//mud中60年一輪=現實中60天
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

nosave int current_day_phase;
nosave int current_weather_phase;
nosave int current_world1_weather;
nosave int current_world2_weather;
nosave int current_world3_weather;
// land, forest, desert, heat, snow
nosave int *weather_msg_no = ({ 0,0,0,0,0,0,
                                0,0,0,0,0,0,
                                0,0,0,0,0,0 });

mapping *day_phase;
mapping *weather_phase;
int light=0;
string *weather_msg = ({
	"天空中萬里無雲",
	"幾朵淡淡的雲彩妝點著清朗的天空",
	"白雲在天空中飄來飄去",
	"厚厚的雲層堆積在天邊",
	"天空中烏雲密佈",
});

mapping *read_table(string file);
void init_day_phase();

// 病症 -Tmr 2006/11/16
void trigger_condition() {
        object *ob;
        int i, con1,con2, con3;
        string get_month,ill,msg;
        get_month = CHINESE_D->chinese_month(TIME_TICK);
        switch(get_month)
        {
                case "三":
                case "四":
                case "五":
                        ill = "ill_kesou";
                          msg = HIG"忽然喉頭一陣狠癢，你感覺似乎要咳嗽了。\n"NOR;
                        break;
                case "六":
                case "七":
                case "八":
                        ill = "ill_zhongshu";
                        msg = HIG"突然你胸臆之間一陣翻騰，你中暑了。\n"NOR;
                        break;
                case "九":
                case "十":
                case "十一":
                        ill = "ill_shanghan";
                         msg = HIG"你打了個冷顫，頭昏沉沉的，得到傷寒病了。\n"NOR;
                        break;
                case "十二":
                case "一":
                case "二":
                        ill = "ill_dongshang";
                        msg = HIG"你肢體末端一陣僵直，看來你被凍傷了。\n"NOR;
                        break;
        }
        if(random(2))
        {
                ill = "ill_fashao";
                 msg = HIG"你偶感風寒，竟然發起燒來。\n"NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                 if( !environment(ob[i])->query("outdoors") ) continue;
                  if( ob[i]->query_skill("strong-body") == 100 ) continue;
                con1 = ob[i]->query("ap");
                con2 = ob[i]->query("max_ap");
                con3 = ob[i]->query("con");
                     if( con1 < random(con2) || con3 < random(100) )
                {
                        ob[i]->apply_condition(ill, 10 + random(40));
                        tell_object(ob[i], msg);
                }
        }
}

int query_light()
{
  return light;
}

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	weather_phase = read_table("/adm/etc/nature/weather_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(GAME_TIME_TICK);
	t = local[LT_HOUR] * 60 + local[LT_MIN];	// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_weather_phase = 1;
	current_world1_weather = 1;
	current_world2_weather = 1;
	current_world3_weather = 1;

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.
	// 遊戲中的一分鐘等於現實世界的一秒鐘.

//	call_out("update_day_phase",
//		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
	call_out("update_weather_phase", 60);
}

void update_day_phase(int a)
{
//	mixed *local;
//	remove_call_out("update_day_phase");

//	current_day_phase = (++current_day_phase) % sizeof(day_phase);
//	local = localtime(GAME_TIME_TICK);

	current_day_phase = a;	//改由 CLOCK_D 指定並呼叫. Luky
     message("dayphase:vision", day_phase[current_day_phase]["time_msg"] + NOR"\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

//	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}

void update_weather_phase()
{
	int i,j;
	string word, weather, kinds;
	mixed current_weather;

	remove_call_out("update_weather_phase");

	if(current_weather_phase>=3)
	{
		current_weather_phase = 0;
		current_world1_weather = random(sizeof(weather_phase));
		current_world2_weather = random(sizeof(weather_phase));
		current_world3_weather = random(sizeof(weather_phase));
	}
	current_weather_phase++ ;

	word = "weather_msg" + (string)current_weather_phase ;

	current_weather =( { current_world1_weather,
			     current_world2_weather,
			     current_world3_weather  } );
// 除錯專用程式片斷...請勿刪掉
/*
	message("outdoor:vision", "天氣敘述如下: [word="+word+
		"] [world1="+current_world1_weather+
		"] [world2="+current_world2_weather+
		"] [world3="+current_world3_weather+"]\n", users());
*/
	for(i=1;i<=3;i++)
	{
		weather = weather_phase[current_weather[i-1]]["kinds"];
		while(1)
		{
			if( sscanf(weather,"%s|%s", kinds, weather)==2 )
			{
                 message("world:world"+(string)i+":outdoor:"+kinds, "\t\t"+weather_phase[current_weather[i-1]][word] + "\n"NOR, users());
				switch(kinds)
				{
					case "universe":j=5; break;
					case "heat":	j=4; break;
					case "desert":	j=3; break;
					case "snow":	j=2; break;
					case "forest":	j=1; break;
					case "land":	j=0; break;
					default:	j=0; break;
				}
				weather_msg_no[(i-1)*6+j]=current_weather[i-1]+1;
			}
			else break;
		}
	}
// 除錯專用程式片斷...請勿刪掉
/*
	for(j=0;j<3;j++)
	{
		for(k=0;k<6;k++)
			message("outdoor:vision", weather_msg_no[(j*6)+k]+", ",users() );
		message("outdoor:vision", "\n", users() );
	}
	message("outdoor:vision", "================\n", users() );
*/
	call_out("update_weather_phase", (int)weather_phase[current_weather_phase]["length"]);
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_dawn()
{
	light = 1;//天亮
	return;
}

void event_sunrise()
{
	light = 2;
	return;
}
void event_morning()
{
	light = 3;
	return;
}

void event_noon()
{
        light = 4;
        trigger_condition();

}

/*
void event_noon()
{
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mp") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "你覺得一陣暈眩﹐好像有一股能量從身上被黑洞吸走了。\n");
//			ob[i]->set("mp", 0);
//			ob[i]->receive_damage("mp", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "隨著黑洞升到天空的正中央﹐你覺得你的法力開始消失了。\n");
//			ob[i]->set("mp", (int)ob[i]->query("mp") * skill / 25 );
		}
	}
	return;
}
*/
void event_afternoon()
{
	light = 3;
	return;
}

void event_evening()
{
	light = 2;
	return;
}

void event_night()
{
	light = 1;
	return;
}

void event_midnight()
{
        string get_month, get_day;
	light = 0;
          trigger_condition(); // 病症

        get_day = CHINESE_D->chinese_monthday(TIME_TICK);
        get_month = CHINESE_D->chinese_month(TIME_TICK);
        switch(get_month)
        {
                //spring weather
                case "三":
                case "四":
                case "五":
                        switch(random(3))
                        {
                        case 0:
                                day_phase = read_table("/adm/etc/nature/spring_rain"); break;
                        case 1:
                                day_phase = read_table("/adm/etc/nature/spring_sun"); break;
                        case 2:
                                day_phase = read_table("/adm/etc/nature/spring_wind"); break;
                        }
                        break;
                //summer weather
                case "六":
                case "七":
                case "八":
                        switch(random(3))
                        {
                        case 0:
                                day_phase = read_table("/adm/etc/nature/summer_rain"); break;
                        case 1:
                                day_phase = read_table("/adm/etc/nature/summer_sun"); break;
                        case 2:
                                day_phase = read_table("/adm/etc/nature/summer_wind"); break;
                        }
                        break;
                //autumn weather
                case "九":
                case "十":
                case "十一":
                        switch(random(3))
                        {
                        case 0:
                                day_phase = read_table("/adm/etc/nature/autumn_rain"); break;
                        case 1:
                                day_phase = read_table("/adm/etc/nature/autumn_sun"); break;
                        case 2:
                                day_phase = read_table("/adm/etc/nature/autumn_wind"); break;
                        }
                        break;
                //winter weather
                case "十二":
                case "一":
                case "二":
                        switch(random(3))
                        {
                        case 0:
                                day_phase = read_table("/adm/etc/nature/winter_rain"); break;
                        case 1:
                                day_phase = read_table("/adm/etc/nature/winter_sun"); break;
                        case 2:
                                day_phase = read_table("/adm/etc/nature/winter_wind"); break;
                        }
                        break;
                default:
                        day_phase = read_table("/adm/etc/nature/day_phase");
        }
	return;	
}

string outdoor_room_description()
{
     return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n" NOR;
}

string outdoor_room_weather_status(object env)
{
	int i,j,k;

	string word, kinds, weather_status;

	if(!env) return "";
	if(env->query("no_weather")) return "";
	if( sscanf(base_name(env),"/open/world%d/%s",i,word) == 2 )
	{
		kinds = env->query("outdoors");
		switch(kinds)
		{
			case "universe":j=5; break;
			case "heat":	j=4; break;
			case "desert":	j=3; break;
			case "snow":	j=2; break;
			case "forest":	j=1; break;
			case "land":	j=0; break;
			default:	j=0; break;
		}
		word = "weather_msg" + (string)current_weather_phase;
		k = weather_msg_no[(i-1)*6+j];
		weather_status = (k>0) ? weather_phase[k-1][word]+"\n" : "";
	}
	else return "";
      return "    "+weather_status + ""NOR;
}

string game_time(int a)
{
	return CHINESE_D->ds_date(GAME_TIME_TICK,a);
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

//	if( file_size(file) <1 ) return ({ });
	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}


mapping *query_day_phase() { return day_phase; }

// 回傳 1 就是古代, 2 就是現代, 3 就是未來
int which_world(object env)
{
	string env_dir;
	string buf;
	int a;

	env_dir = base_name(env);
	if( sscanf(env_dir,"/open/%s/%s",env_dir,buf)!=2)
		return 0;
	if( sscanf(env_dir,"world%d",a)!=1)
		return 0;
	return a;

}
