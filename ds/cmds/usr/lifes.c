// lifes.c
// 三轉之後，可以學習生活技能

#include <ansi2.h>

inherit F_CLEAN_UP;
int sort_skill(string sk1,string sk2);

int main(object me, string arg)
{
        object ob;
       string basic;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看誰的生活技能﹖\n");
        }

        if( ob!=me      && !wizardp(me)         && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("只有巫師或有師徒關係的人能察看他人的技能。\n");


        basic   = "│"+BBLU HIW "  生 活 技 能                              等級    熟練度 / 升級需要    "+NOR"│\n"NOR;
        basic += "�澺������������������������������������������������������������������������螏n";
        
        basic = "┌────────────────────────────────────┐\n"
                + basic
                + "└────────────────────────────────────┘\n";

        write(basic);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : lifes [<某人>]

這個指令可以讓你(妳)查詢所學過的生活技能。

巫師可以查詢任何人或 NPC 的技能狀況。

HELP
    );
    return 1;
}

