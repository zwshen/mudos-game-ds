// wizlist.c
//EDIT BY SAMMY 11/20/1997
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string *list;
        int my_level, i, j;
          string ch,str;
        object ob;
        list = sort_array(SECURITY_D->query_wizlist(), 1);
str = sprintf("[1;35m目前的巫師一共有 %d  位[0m﹕(黃色高亮度者表正在線上)\n",sizeof(list));
        my_level=wiz_level(me);
str += sprintf("[32m████████████████[1;36m    (admin)    [0;32m████████████████[0m\n\n ");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(admin)")
        {     
                ch = " ";
                if(ob=find_player(list[i]))
if(me->visible(ob) || wiz_level(ob) <= my_level )
   ch = "[1;33m " ;
                str += sprintf("%s%-10s[0m%s", ch, list[i], ((j++)%7==6) ? "\n " : "");
        }
str += sprintf("\n\n[32m████████████████  [1;33m  (arch)     [0;32m████████████████[0m\n\n ");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(arch)")
        {
                ch = " ";
                if(ob=find_player(list[i]))
                        if(me->visible(ob) || wiz_level(ob) <= my_level)
                                ch = "[1;33m ";
                str += sprintf("%s%-10s[0m%s", ch, list[i], ((j++)%7==6) ? "\n " : "");
        }
str += sprintf("\n\n[32m████████████████ [1m   (wizard)   [0;32m████████████████[0m\n\n ");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(wizard)")
        {
                ch = " ";
                if(ob=find_player(list[i]))
                        if(me->visible(ob) || wiz_level(ob) <= my_level)
                                ch = "[1;33m ";
                str += sprintf("%s%-10s[0m%s", ch, list[i], ((j++)%7==6) ? "\n " : "");
        }
str += sprintf("\n\n[32m████████████████  [1;35m(apprentice) [0;32m████████████████[0m\n\n ");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(apprentice)")
        {
                ch = " ";
                if(ob=find_player(list[i]))
                        if(me->visible(ob) || wiz_level(ob) <= my_level)
                                ch = "[1;33m ";
                str += sprintf("%s%-10s[0m%s", ch, list[i], ((j++)%7==6) ? "\n " : "");
        }
str += sprintf("\n\n[32m████████████████  [1;37m(immortal)   [0;32m████████████████[0m\n\n ");

        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(immortal)")
	{
                ch = " ";
                if(ob=find_player(list[i]))
                        if(me->visible(ob) || wiz_level(ob) <= my_level)
                                ch = "[1;33m ";
                str += sprintf("%s%-10s[0m%s", ch, list[i], ((j++)%7==6) ? "\n " : "");
	}
        str += sprintf("\n");
	me->start_more(str);
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : wizlist
指令說明 :
           本指令用來查看目前總共有多少個巫師。
HELP
    );
    return 1;
}

