// news.c by alick 2006 jan

int help(object);

int main(object me, string arg)
{
        int num, no;

        if(!arg) {
                me->start_more(MOTD_D->list());
                return 1;
        }
        
    if( sscanf(arg,"%d",num) != 1 && sscanf(arg,"-d %d", no) != 1 )
        {
                if( wizardp(me) )  {
                        MOTD_D->announce(me->query("id"), arg );
                        write("新增公告：" + arg + " ok\n");
                        return 1;
                }
                
                return help(me);
        }

        if( no && wizardp(me) )
        {
                if( MOTD_D->discard(no) )
                {
                        write("公告刪除成功\！\n");
                        return 1;
                }
                return notify_fail("沒有這篇公告！\n");
        }

        if( num ) 
                me->start_more(MOTD_D->list(num));
        else
                me->start_more(MOTD_D->list());
        return 1;
}

int help(object me)
{
        write(@HELP
        指令格式:
        news                    顯示所有公告
        news [n]                顯示最新 n 項公告
        news -d [n]             刪除編號 n 之公告       [wiz only] 
                                (巫師可從 news 指令中查看公告編號)
        
        shout [msg] -beep       公告指令格式            [wiz only]

HELP);
        return 1;
}

