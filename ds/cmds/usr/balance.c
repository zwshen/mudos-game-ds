inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object who;
        
    if( arg && !wizardp(me) )
        return notify_fail("只有巫師才能查詢別人的存款。\n");

    if( !arg ) who = me;
    if( arg=="ALL") {
        object* ob;
        string msg ;
        int i;

        ob = sort_array( users(), "sort_user" );

        msg  = "╭────────────────────────────────────╮\n";
        for(i=0;i<sizeof(ob);i++) {
        msg += sprintf("│%12s%-12s %40s 枚銅板│\n",
                       ob[i]->query("name"),
                       "("+ ob[i]->query("id") + ")",
                        chinese_number(ob[i]->query("bank/past"))
                      );

        }
        msg += "╰────────────────────────────────────╯\n";
        //tell_object(me, msg);
        me->start_more(msg);
        return 1;
    }
    else {
        if( !who ) who = present(arg, environment(me));
        if( !who ) who = find_living(arg);
        if( !who ) return notify_fail("沒有 " + arg + " 這個人物。\n");
        write( sprintf("[%s(%s)] ",who->name(), who->query("id")));
    }

    tell_object(me, "你目前有" + chinese_number(who->query("bank/past")) + "枚銅板的存款。\n");

    return 1;
}

int sort_user(object ob1, object ob2)
{
    return ob2->query("bank/past")- ob1->query("bank/past");
}

int help()
{
    write(@TEXT
指令格式﹕balance [某人|ALL]

這個指令可以查詢你銀行目前的存款。
TEXT);
    return 1;
}

