// uptime.c

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "¤Ñ";
	else time = "";

	if(h) time += chinese_number(h) + "¤p®É";
	if(m) time += chinese_number(m) + "¤À";
	time += chinese_number(s) + "¬í";

	write("[1;36m"+MUD_NAME+"[1;36m¤w¸g°õ¦æ¤F" + time + "[0m\n");
	return 1;
}

int help(object me)
{
	write(@HELP
«ü¥O®æ¦¡ : uptime
 
³o­Ó«ü¥O§i¶D§A¥»¹CÀ¸¤w¸g³sÄò°õ¦æ¤F¦h¤[.
 
HELP
    );
    return 1;
}
