// alias.c
// #pragma save_binary
#define MAX_REPEAT 60
#define MAX_ALIASES 100
#define HISTORY_BUFFER_SIZE 10

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;

varargs string process_input(string str,int test)
{
	string *args, cmd, argstr;
	int i, j;
	if(this_object()->query_temp("gb_player")) str=LANGUAGE_D->GB2Big5(str);
	if( str==last_input ) {
		repeat_cnt++;
		if( repeat_cnt > MAX_REPEAT ) {
			tell_object( this_object(),
				"\n\n賽菲羅斯突然從一團火球中走了出來。\n\n"
				"\n\n賽菲羅斯露出詭異的笑容﹕你這個機器人是個失敗品!!! 消失吧!!!\n\n");
			command("quit");
		}
	} else {
		repeat_cnt = 0;
		last_input = str;
	}

	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) && (HISTORY_BUFFER_SIZE + last_cmd - i) >= 0 )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		if(!test)
		{
			last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
			history[last_cmd] = str;
		}
	}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}

	return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
	if( !verb ) return 0;
	if( !replace )
	{
		if( mapp(alias) ) map_delete(alias, verb);
		write("[alias]: "+verb+" 已刪除!!\n");
		return 1;
	}
	 else
	{
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("您設定的 alias 太多了﹐請先刪掉一些不常用的。\n");
		/* 以下由alickyuen 加上fix掉add_action的bug-治標不治本 */
		else alias[verb] = replace;
		write("你將 "+verb+" 設定為: "+replace+"\n");
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}

string *query_history()
{
	return history;
}

