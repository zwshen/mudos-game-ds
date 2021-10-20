//
// cmd_d.c
//
// By Annihilator (11/07/94)
// Re-write By Luky (03/01/2000) : auto_complete
// #pragma save_binary
mapping search = ([]);

void rehash(string dir)
{
	int i;
	string *cmds,*cmd=({});

	if( dir[sizeof(dir)-1]!='/' ) dir += "/";
	cmds = get_dir(dir);
	i = 0;
	while(i<sizeof(cmds))
	{
		if( sscanf(cmds[i], "%s.c", cmds[i])==1 ) cmd+=({cmds[i]});
		i++;
	}
	if( sizeof(cmd) )
		search[dir] = cmd;

}

varargs string auto_string_complete(string head,string *bodys, int length)
{
	int i;

	if(strlen(head) < length) return 0;
	if( !pointerp(bodys) )	return 0;

	i = sizeof(bodys);
	if(!stringp(bodys[0])) return 0;
	while(i--) {
		if(strsrch(bodys[i],head)==0)
		{
			return bodys[i];
			break;
		}
	}
	return 0;
}

varargs string find_command(string verb, string *path,int losely)
{
	int i;
	string file;
	if( !pointerp(path) ) return 0;
	i = sizeof(path);

	if(!losely)
	{
		while(i--) {
			if( undefinedp(search[path[i]]) ) rehash(path[i]);
			if( undefinedp(search[path[i]]) ) continue;
			if( member_array(verb, search[path[i]])!=-1 ) return path[i] + verb;
		}
		return 0;
	} else {
		while(i--) {
			if( path[i]=="/cmds/std/" || path[i]!="/cmds/usr/")
			{
				if( undefinedp(search[path[i]]) ) rehash(path[i]);
				if( undefinedp(search[path[i]]) ) continue;
				if(file=auto_string_complete(verb,search[path[i]],2)) return path[i]+file;
			}
		}
		return 0;
	}
}
