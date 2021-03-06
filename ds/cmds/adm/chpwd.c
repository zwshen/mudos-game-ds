/*	File : "/cmds/adm/chpwd.c"	*
 *	Author : "Alickyuen@DS"		*
 *	Last modify : 2002年8月15日	*/

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob, link;
	string id, passwd;

      if(!arg || sscanf(arg, "%s %s", id, passwd) != 2 )
		return notify_fail("指令格式：chpwd <player id> <new passwd>。\n");

	if( !ob = find_player(id) ) 
		return notify_fail("玩家："+id+"並不在線上。\n");

	if( sizeof(passwd) < 4 )
		return notify_fail("密碼最少四個位。\n");

	link = ob->query_temp("link_ob");

	link->set("password", crypt(passwd, 0));
//(find_player(arg)->query_temp("link_ob"))->set("password", crypt("1234", 0));
	return 1;
}
