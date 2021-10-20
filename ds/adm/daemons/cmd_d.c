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
	i = sizeof(cmds);
	for(i=0;i<sizeof(cmds);i++)
		if( sscanf(cmds[i], "%s.c", cmds[i])==1 ) {
			cmd+=({cmds[i]});
		}
	if( sizeof(cmd) )
		search[dir] = cmd;

}

varargs string auto_string_complete(string head,string *bodys, int length)
{
	int i=0,j;

	if(strlen(head) < length) return 0;
	if( !pointerp(bodys) )	return 0;
	j=sizeof(bodys);
	if(!stringp(bodys[0])) return 0;
	while(i<j) {
		if(strsrch(bodys[i],head)==0)
		{
			return bodys[i];
			break;
		}
		i++;
	}
	return 0;
}

string find_command(string verb, string *path)
{
	int i,j;
	if( !pointerp(path) ) return 0;
	if(i = sizeof(path))
		for(j=0;j<i;j++) {
			if( undefinedp(search[path[j]]) ) rehash(path[j]);
			if( undefinedp(search[path[j]]) ) continue;
			if( member_array(verb, search[path[j]])!=-1 ) return path[j] + verb;
		}
		return 0;
}
