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
				"\n\n�ɵ�ù����M�q�@�Τ��y�����F�X�ӡC\n\n"
				"\n\n�ɵ�ù���S�X�޲������e�R�A�o�Ӿ����H�O�ӥ��ѫ~!!! �����a!!!\n\n");
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
		write("[alias]: "+verb+" �w�R��!!\n");
		return 1;
	}
	 else
	{
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("�z�]�w�� alias �Ӧh�F�M�Х��R���@�Ǥ��`�Ϊ��C\n");
		/* �H�U��alickyuen �[�Wfix��add_action��bug-�v�Ф��v�� */
		else alias[verb] = replace;
		write("�A�N "+verb+" �]�w��: "+replace+"\n");
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

