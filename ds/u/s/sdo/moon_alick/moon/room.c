/*	room.c					*
 *	write by alickyuen@ds 20-9-2001		*
 *	管理關於 中秋節 謎題游戲程式		*/

#include <ansi.h>
#define DATA_D __DIR__"data"
#define EXIT_D __DIR__"exit"
#define LOADED_DIR __DIR__"loaded/"

inherit ROOM;

string *id = ({ });

void renew();

void create()
{
	set("short", "花燈大會");
	set("long", 
"這裡正是一年一度的中秋節的花燈大會場地，這裡人山人海，擠\n"+
"迫得很。你的頭上滿是一堆堆五彩漂艷的花燈，有紅有綠有黃，款式\n"+
"多而創新，應有盡有，為這裡營造了一個很好的氣氛。這裡還有一個\n"+
"特別大的花燈，上方還有一張紙，原來是這個花燈大會的特別游戲－\n"+
"『燈謎競逐』。\n"+
"\n紙上寫著：\n"+this_object()->show_question()
);

	set("no_recall", "這裡太多人了，天神聽不到你的呼召。\n");
	set("light", 1);

	setup();

	set("channel_id", "花大會燈工作人員(Officer)");
}

void init()
{
	object room = this_object();

	if( !room->query("question") ) 
	{
		DATA_D->show_question(room);
		renew();
	}

	if( !room->query("exits") ) EXIT_D->show_exit(room);

	add_action("do_answer", "answer");
	add_action("no_ask", ({ "say", "tell" }) );
}

int do_answer(string ans)
{
	object me, file;
	
	me = this_player();
	file = load_object(LOADED_DIR+this_object()->query("question"));

	if( wizardp(me) && me->query("id") != "release" )
		return notify_fail("巫師不能參與是次活動。\n");
	if( !this_object()->query("question") )
		return notify_fail("這裡都沒有謎題，你怎樣去答呀！\n");

	if( member_array(me->query("id") , id) != -1 ) return notify_fail("工作人員說道：你在這段答題時間已經答過問題了，請等後下一次答題時間。\n");

	id += ({ me->query("id") });

	message_vision(HIY"$N把答案『"+ans+"』寫在答題紙上，然後交給工作人員。\n"NOR, me);
	message_vision("\n工作人員馬上幫$N核對答案......\n\n", me);

	if( ans != file->query_answer() )
	{
		message_vision(HIR"工作人員說道：$N的答案是錯的！\n"NOR, me);
		return 1;
	} else {
		if( DATA_D->delete_question(this_object()->query("question")) == 1)
		{
			message_vision(HIY"工作人員說道：恭喜，答對了！$N得到了一分。\n"NOR, me);
			me->add("game/moon_question", 1);
			CHANNEL_D->do_channel(this_object(), "rumor", "恭喜 "+me->name()+" 答中燈謎題目。");
		} else {
			message_vision(HIR"工作人員說道：這題已有人答中了，這個答案不能計算。\n"NOR, me);
		}

		this_object()->delete("question");
		DATA_D->show_question(this_object());
//		write("\n新的題目為：\n\n"+this_object()->show_question()+"\n");
		create();
		renew();
		return 1;
	}

	return 1;
}

string show_question()
{
	object file;
	object room = this_object();

	if( !room->query("question") )
	{
		DATA_D->show_question(room);
		if( !room->query("question") )
                        return HIW"題庫已沒題目，多謝大家參加是次遊戲。\n"NOR;
	}

	file = load_object(LOADED_DIR+room->query("question"));

	return HIW""+file->query_question()+"\n"NOR;
}

void reset()
{
	return;
}

int no_ask(string arg)
{
	return notify_fail("為禁止作弊情形出現，這裡禁止 Tell 與 say 。\n");
}

void renew()
{
	remove_call_out("renew");

	if( !this_object()->query("question") ) return;

	id = ({ });
	CHANNEL_D->do_channel(this_object(), "rumor", "新的燈謎題目為："+this_object()->show_question()+"");
	CHANNEL_D->do_channel(this_object(), "rumor", "這節答題時間現在開始，有五分鍾，請大家快來踴躍參與。");

	call_out("renew", 300);
	return;
}
