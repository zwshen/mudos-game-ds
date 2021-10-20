// natured.c
// #pragma save_binary
#define TIME_TICK (time()*60)

static int current_day_phase;
static int current_weather_phase;
static int current_world1_weather;
static int current_world2_weather;
static int current_world3_weather;
// land, forest, desert, heat, snow
static int *weather_msg_no = ({ 0,0,0,0,0,0,
                                0,0,0,0,0,0,
                                0,0,0,0,0,0 });

mapping *day_phase;
mapping *weather_phase;
int light=0;
string *weather_msg = ({
	"�ѪŤ��U���L��",
	"�X���H�H�����m���I�۲M�Ԫ��Ѫ�",
	"�ն��b�ѪŤ��ƨ��ƥh",
	"�p�p�����h��n�b����",
	"�ѪŤ��Q���K�G",
});

mapping *read_table(string file);
void init_day_phase();

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
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

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

	call_out("update_day_phase",
		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
	call_out("update_weather_phase", 10);
}

void update_day_phase()
{
	mixed *local;
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	local = localtime(TIME_TICK);

	message("dayphase:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}

void update_weather_phase()
{
	int i,j,k;
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
// �����M�ε{�����_...�ФŧR��
/*
	message("outdoor:vision", "�Ѯ�ԭz�p�U: [word="+word+
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
				message("world:world"+(string)i+":outdoor:"+kinds, "\t\t"+weather_phase[current_weather[i-1]][word] + "\n", users());
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
// �����M�ε{�����_...�ФŧR��
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
	light = 1;//�ѫG
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
	return;
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
			tell_object(ob[i], "�Aı�o�@�}�w�t�M�n�����@�ѯ�q�q���W�Q�¬}�l���F�C\n");
//			ob[i]->set("mp", 0);
//			ob[i]->receive_damage("mp", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "�H�۶¬}�ɨ�ѪŪ��������M�Aı�o�A���k�O�}�l�����F�C\n");
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
	light = 0;
	return;	
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "�C\n";
}

string outdoor_room_weather_status(object env)
{
	int i,j,k;

	string word, kinds, weather_status;

	if(!env) return "";

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
	return "\t\t"+weather_status;
}

string game_time(int a)
{
	return CHINESE_D->ds_date(TIME_TICK,a);
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

// �^�� 1 �N�O�j�N, 2 �N�O�{�N, 3 �N�O����
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