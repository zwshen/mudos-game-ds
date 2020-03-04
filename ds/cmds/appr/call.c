// call.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname, func, param, euid;
	object obj;
	mixed *args, result;
	int i;

	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("ぃ砞﹚ euid\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return notify_fail("Αcall <ン>-><ㄧ计>( <把计>, ... )\n");
	} else
		return notify_fail("Αcall <ン>-><ㄧ计>( <把计>, ... )\n");

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("тぃ﹚ン\n");

	if( userp(obj) )
	{
		if( obj != me )
		{
			if( wiz_level(me) < 4 && userp(obj))
			{
				log_file("static/CALL_PLAYER",
				sprintf("%s(%s)刚瓜э %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
				return notify_fail("ぃэㄤ產戈\n");
			}
			log_file("static/CALL_PLAYER",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
			if( !wizardp(obj) && wiz_level(me) < 4 )
			{
				log_file("static/CALL_PLAYER","[笻は畍砏﹚] "+me->name(1)+"("+geteuid(me)+") 刚瓜э "+obj->name(1)+"("+geteuid(obj)+")戈!!\n");
				return notify_fail("﹚ンぃ猭\n");
			}
		}
	}
	 else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("⊿Τ钡㊣硂ンㄧ计舦\n");

	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}

	args = ({ func }) + args;

	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}

int help(object me)
{
write(@HELP
Α : call <ン>-><ㄧ计>(<把计>, ...... )
 
㊣<ン>柑<ㄧ计>肚闽<把计>.

猔種: ぃ盢妮┦㎝м单籔璸衡Τ闽计秸び蔼(ぃ禬筁100夹非),
      硑Θ╰参岿粇讽诀!!
 
HELP
    );
    return 1;
}
