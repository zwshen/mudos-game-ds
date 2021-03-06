// write by -Acme- 2001/9/16
#include <ansi.h>
#include <room.h>
//#define START_ROOM "/open/dragon_wine/inn_hall.c"	//At 用
#define START_ROOM "/open/world1/tmr/area/hotel.c"	  //Ds 用

inherit F_SAVE;
inherit ROOM;

mapping game_record;

int do_leave();
int do_list();
int do_sign();
int sort_list(string ob1, string ob2);

void create()
{
        seteuid(getuid()); 
        set("short", "月宮[月球]");
        set("long", @LONG
一望無際的月球，四週坑坑洞洞的，十分荒涼，遠方傳來「喀∼
喀∼」之聲，應該是吳剛在砍桂樹吧，後方又傳來陣陣「咚咚∼」聲
，也許是玉兔在搗藥，眼前一顆黑色大石，上頭刻著許多密密麻麻的
字。當然你也可以離開(leave)這裡。
LONG
        );
//        set("detail", ([	// At 用
	set("item_desc", ([	// Ds 用
		"黑色大石" : "你可以在上面刻下(sign)自已的紀錄，也可以觀看紀錄(list)。\n",
	]));
        set("no_fight",1);
        set("no_recall",1);
        setup();
        if( !restore() )
	        game_record=([]);
}

void init()
{
	add_action("do_list","list");
	add_action("do_sign","sign");
	add_action("do_leave","leave");
}

int do_leave()
{
	message_vision(HIW"$N說了一句「罷了∼神仙難為∼還是回去當凡夫俗子吧∼」隨即往下墜落！\n"NOR,this_player());
	this_player()->delete_temp("fly_speed");
	this_player()->delete_temp("fly_long");
	this_player()->delete_temp("fly_time");
	this_player()->move(START_ROOM);
	message_vision(HIW"$N從天上掉了下來！！\n"NOR,this_player());
	return 1;
}

int do_list()
{
	int i,j;
	string *ppl,msg;
        if( !mapp(game_record) ) return notify_fail("目前還沒有任何紀錄！\n");
	ppl=keys(game_record);
	i=sizeof(ppl);
        ppl = sort_array(ppl, "sort_list", this_object());
	msg ="\t\t\t  ◎中秋奔月活動◎\n";
	msg+="======================================================================\n";
	while( i-- )
	{
		j++;
		if( ppl[i]==getuid(this_player()) ) msg+= HIC;
                msg+=sprintf("第%3d名 ---- %13s 共花%6.2f秒",
			j,ppl[i],game_record[ppl[i]]);

		switch( j )
		{
			case 1: msg+= "\t(上名人堂,自訂save eq一件)\n"; break;
			case 2..5: msg+= "\t(自訂save eq一件)\n"; break;
			default: msg+="\t(參加獎)\n"; break;
		}

		msg+=NOR;
	}	
	msg+="======================================================================\n";
	msg+="註：活動結束後，前五名者請洽 流影(Acme) 領取獎品…\n";
	this_player()->start_more(msg);
	return 1;
}

int sort_list(string ob1, string ob2)
{
        int i;
	i = game_record[ob2] - game_record[ob1];
        return i;
}

int do_sign()
{
	string id;
	object me=this_player();
	id=getuid(me);
        if( !mapp(game_record) ) game_record=([]);
	if( !me->query_temp("fly_time") )
		return notify_fail("你並沒有奔月速度！\n");
        if( !undefinedp(game_record[id]) )
        {
		write("你的舊紀錄為["+game_record[id]+"]秒，這次的速度為["+me->query_temp("fly_time")+"]你確定要更新紀錄嗎？(y/n)");
		input_to("check_sign");
		return 1;
	}
	write("你在黑色大石上刻下了自已的大名和奔月速度！\n");
        (float)game_record[id]=(float)me->query_temp("fly_time");
	me->delete_temp("fly_time");
	this_object()->save();
        return 1;
}

private void check_sign(string check)
{
	object me=this_player();
        if( check!="y" && check!="Y" )
        {
                write("取消更新紀錄。\n");
                return;
        }
	game_record[getuid(me)]=me->query_temp("fly_time");
	me->delete_temp("fly_time");
	write("你在黑色大石上刻下了自已的大名和奔月速度！\n");
	this_object()->save();
}
string query_save_file() { return DATA_DIR + "game/ma_game"; }
