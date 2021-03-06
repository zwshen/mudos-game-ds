/*	tree.c			*
 *	write by -alickyeun@ds-	*
 *	2002中秋節遊戲記錄檔	*/

#include <ansi2.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;

void create()
{
	set_name(HIY"月亮桂樹"NOR, ({ "moon tree", "tree" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
	set("long", "");
	setup();
	if( !restore() )	game_record=([]);
}

string query_save_file()
{
	return DATA_DIR + "game/moon_sun";
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return;

	add_action("do_look", "look");
	add_action("do_climb", "climb");
	add_action("do_search", "search");
	if( getuid(me) == "alickyuen" ) add_action("reset_record", "reset");
        if( getuid(me) == "alickyuen" ) add_action("set_record", "set");
}

int do_record(object me)
{
	string id;

	if( !me || !userp(me) ) return 0;

	id = getuid(me);

	if( !restore() ) game_record=([]);
	if( !mapp(game_record) ) game_record=([]);

	if( !game_record[id] ) game_record[id] = 1;
		else game_record[id] += 1;
	this_object()->save();

	message("world:world1:vision", HIR"\n\t\t\t天上突然有一個太陽被射下來了......\n\n"NOR, users());

	return 1;
}

int reset_record()
{
	if( this_player()->query("id") != "alickyuen" )
		return notify_fail("你並不是遊戲的創作者，沒有資格去改變遊戲記錄。\n");

	game_record=([]);
	this_object()->save();
	write("清除記錄完成。\n");

	return 1;
}

int set_record(string arg)
{
	string who;
	int score;

	if( sscanf(arg, "%s to %d", who, score) != 2 )
		return notify_fail("指令格式: set who to score。\n");
	if( !restore() ) game_record=([]);
	game_record[who] = score;
	this_object()->save();
	write("ok。\n");
	return 1;
}

int do_look(string arg)
{
	if( arg == "tree" || arg == "moon tree" )
	{
		write("2004 中秋活動[射日] 玩法: \n"+
		"[search tree] -> 取得木弓\n"+ 
		"[climb] 爬樹  \n[shoot] 射日\n");
                return this_player()->start_more(this_object()->do_list());
	}
}

string do_list()
{
	float *score, swap;
	int i, j, x;
	string *ppl, msg, user;

	if( !restore() ) game_record=([]);
	if( !game_record )		return "暫時沒有人上榜。\n";
	if( !mapp(game_record) )	return "暫時沒有人上榜。\n";
	if( !sizeof(game_record) )	return "暫時沒有人上榜。\n";

	ppl=keys(game_record);
	score=values(game_record);
	i=sizeof(score);

	for(j=i-1;j>0;j--)
	{
		for(x=1;x<=j;x++)
		{
			if( score[x-1] > score[x] )
			{
				swap=score[x-1];
				score[x-1]=score[x];
				score[x]=swap;
				user=ppl[x-1];
				ppl[x-1]=ppl[x];
				ppl[x]=user;
			}
		}
	}

	i=sizeof(ppl);
	j=0;
	msg= HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
        msg += HIG"\t\t☆200"HIY"4"HIG"年中秋節特別活動『射太陽』之神射手榜☆\n";
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	while( i-- )
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) msg+= BLINK+HIC;
			else msg += CYN;

		if( game_record[ppl[i]] > 0 ) {
                        msg+=sprintf("第%4s名 ---- %13s 目前共射下了 %3d 個太陽",
				chinese_number(j),ppl[i],game_record[ppl[i]]);

		switch( j )
		{
/*
			case 1: msg+= HIR""BLINK" (超級大獎：神射手專用裝備一件[save eq])\n"; break;
			case 2..5: msg+= HIM" (大獎：神秘面紗(secret mask)一件[save eq])\n"; break;
                        default: msg+= HIW" (參加獎：可以於活動結束後參與抽獎[每5分一次]，有機會獲取save eq一件)\n"; break;
*/
                        case 1: msg+= HIR""BLINK" (超級大獎：Save EQ[白紙(white paper)]一件)\n"; break;
                        default: msg+="\n"NOR; break;
		}
		}
                msg+=NOR;
	}
        msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}

int do_climb(string arg)
{
	object me = this_player();

	if( arg != "tree" && arg != "moon tree" ) return 0;

	if( me->is_busy() || me->is_block() )
		return notify_fail("你正在忙中！\n");

	message_vision("$N慢慢地往$n上爬了上去。\n",me ,this_object());
	me->move(__DIR__"tree1");
	me->start_busy(2);
        me->receive_wound("left_leg", 2+random(2));
        me->receive_wound("left_arm", 2+random(2));
        me->receive_wound("right_arm", 2+random(2));
        me->receive_wound("right_leg", 2+random(2));

	return 1;
}

int do_search(string arg)
{
	__DIR__"tree1"->do_search(arg);
}
