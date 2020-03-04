// dnsquery.c 硂琌代刚呼隔ㄣ.
// By Luky @ds.muds.net 1999.11.29
#include <net/dns.h>
inherit F_CLEAN_UP;

int help(object me);

string map_to_string(mapping info)
{
	int loop;
	string *key,text="";
	if(sizeof(info))
	{
		key=keys(info);
		for(loop=0; loop<sizeof(key); loop++)
		{
       			if(strlen(key[loop]) > 7)  text += key[loop] + "\t: ";
       			else text += key[loop] + "\t\t: ";
	      			text +=sprintf("%O \n",info[ key[loop] ]);
     		}
    		text+="============================\n";
	}

	return text;

}

int main(object me,string arg)
{
	string opt,mud,*key,text="";
	mapping info;

	seteuid(geteuid(me));
	if(!arg) return help(me);
	if(arg=="-a")
	{
		if( wiz_level(me) < wiz_level("(arch)") ) return notify_fail("舦ぃì磅︽\\n");
		info = DNS_MASTER->query_muds();
		if(sizeof(info)) text = map_to_string(info);
		else text = "Sorry.. No such can't find mud_info.\n";
		me->start_more(text);	
		return 1;
	}

	if(sscanf(arg,"-%s %s",opt,mud)!=2) return help(me);
	switch(opt)
	{
		case "i":	
				info = DNS_MASTER->query_mud_info(mud);
				if(sizeof(info)) text = map_to_string(info);
				else text = "Sorry.. No such mud_info .. <"+mud+">\n";
				break;

		default :
				return help(me);
	}
	
	me->start_more(text);	
	return 1;
}

int help(object me)
{
	write(@HELP
Α : dnsquery [把计] MUD_NAME
 
把计:
	-i : DNS_MASTER 琩高 MUD_NAME  info. (mapping)
	-a : 琩高┮Τ硈絬MUD戈癟.

HELP
    );
    return 1;
}
 
