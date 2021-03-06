// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string id,file,club_name;
	object mark,ob,old_mark;
	mapping ob_info;
	int level;
	seteuid(getuid());
        if(!arg) return notify_fail("指令格式 : setclub <某人> with (幫會信物檔案路徑)\n");
        else
        {
        	if( sscanf(arg, "%s with %s", id, file)!=2 ) return notify_fail("指令格式 : setclub <某人> with (幫會信物檔案路徑)\n");
                ob = present(id, environment(me));
                if (!ob) ob = find_player(id);
                if (!ob) ob = find_living(id);
	        if (!ob) return notify_fail("沒有這個人喔.\n");
		
		if(!mark=new(file)) return notify_fail("沒有這個信物或是檔案不正確.\n");
		if(!stringp(club_name=mark->query("club"))) return notify_fail("這個信物的<club>資料不正確.\n");
		 if( (mark->query_weight()+ob->query_encumbrance())>ob->query_max_encumbrance() )
 		 return notify_fail(ob->name(1)+"拿不動"+mark->query("name")+"。\n");
		ob->delete("club");

		CLUB_D->add_club(mark->query("club_id"));
		
		if(mark->query("club_max_level") > 1) level=mark->query("club_max_level");
			else level=5;
		
		ob_info=([
				"level": level,
				"title": "幫會創始人",
				"info1": "無",
				"info2": ctime(time()),
				"info3": me->name_id(1),
		]);
		
		CLUB_D->set_member(mark->query("club_id"),getuid(ob),ob_info);
		CLUB_D->set_club_leader(mark->query("club_id"),getuid(ob));
		while(old_mark=present("club_mark", ob)) destruct(old_mark);
		mark->move(ob);
		message_vision("$N將$n提升為"+club_name+"的創始人。\n",me,ob);
		ob->save();
	}
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : setclub <某人> with (幫會信物檔案路徑)

將一名玩家提昇為幫派老大。
HELP
    );
    return 1;
}
