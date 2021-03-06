#include <ansi2.h>

inherit NPC;

string do_book(); // void -> string by -alick@ds-

void create()
{	
	set_name("海頓", ({ "haydn"}) );
	set("long", @LONG
現在站在你眼前的人就是村長海頓。他是在這裡住最久的人，如果說
想要知道什麼情報，問他就對了。而且有小道消息說他有一位特殊的
好友，偶爾會住在他家二樓。
LONG);
	set("level",30);
	set("age",70);
	set("race","人類");
	set("gender","男性");
	set("combat_exp", 5000);
	set("title","村長");

	set("talk_reply","真是煩惱阿...\n");
	set("inquiry", ([
		"迷霧森林" : "迷霧森林就是指這一大片的森林。\n",
		"煩惱" : "就是最近有一群怪物聚在本村的西邊，偶爾會在本村附近肆虐\n"
    			"，真令人煩惱。不知道誰能夠解決...\n",
		"海頓" : "就是本人，想要來一杯嗎？\n",
		"通過方法" : this_object()->do_book(),
	]));

	setup();
}

string do_book()
{
	object book,me;
	me=this_player();

	if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdoquest/step1")==1) 
	{
		book->add_quests_note("fogforest",
			"不知道伏克村的最大問題是什麼....，也許\我該四處打聽一下。\n");
		me->set_temp("sdoquest/step1",2);
		return "通過的方法阿....可是我不能平白的告訴你。這樣吧，\n如果你能解決本村最大的問題，我就會告訴你的。\n";
	}
}

int accept_object(object me,object ob)
{
        object obj,book;
        obj=this_object();
	if(!objectp(book=present("adventure notebook",me))) return 0;
        if(ob->name()!="感謝信")
        	return notify_fail("謝謝你，但是我不需要這個。\n");
        if(obj->is_busy() )
        	return notify_fail("我現在沒空！！\n");
        message_vision("$N給了$n一封"+ob->query("name")+"。\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        message_vision(
        "$n低頭看著感謝信，看完後思考了一會，對著$N說道：『你幫本村出了不少心力，我也不好意思隱瞞你；想要\n"
        "知道如何通過迷霧森林，到二樓去問(inquiry)瑟琳娜吧！她會告訴你的。\n",me,obj);
        if(book)
        {
        	book->add_quests_note("fogforest",
        	"終於可以知道通過迷霧森林的方法了，快去拜訪瑟琳娜吧。\n");
               	me->set_temp("sdoquest/step2",2);
        }
        return 1;
}
