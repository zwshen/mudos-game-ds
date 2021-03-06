//trans1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "夢幻傳送站");
	set("long", @LONG
在這個夢幻傳送站，你可以將你自己的身體結構重新分解組合，而將
自己傳送到未來的時空之中，牆壁上還一個公告(post)，在一旁有一台龐
大的機器(machine)，看來好像是傳送用的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
        "down"     :   __DIR__"tree.c",

	]));
	set("item_desc", ([
	  "post" : 
"
        ================================================
         	若要將自己傳送到過去的時空之中，請
		將你的通行證交給守衛(show)
		到未來  show card1
		到現在  show card2
		到過去  show card3
	================================================
",
	"machine" : "這是一台時光傳送機。\n",
	]) );
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_cast", 1);
	setup();
}

void init()
{
	add_action("do_show", "show");
}

int do_show(string arg)
{
	object me, ob;
	me = this_player();

	if( arg !="card1" && arg !="card2" && arg !="card3")
	return notify_fail("你要拿出什麼???\n");

	if( arg == "card1")
	{
	ob = present("feature card", me);
	if(objectp(ob)==1)
	{
	message_vision("\n"
+ HIW"		$N將"HIY"未來通行證"HIW"交給守衛...\n"NOR
+ HIW"			守衛在驗證後並啟動傳送機器...\n"NOR
+ HIW"		一到強烈的"HIC"藍光"HIW"將$N包住，\n"NOR
+ HIW"			光線消失後，$N也隨著不見了...\n\n\n"NOR,me);
	me->move("/open/world2/anfernee/start/login");
	destruct(ob);
	return 1;
	}
	else return notify_fail(HIW"未來通行證呢??\n"NOR);
	}
	else if ( arg == "card2")
	{
	ob = present("recent card", me);
	if(objectp(ob)==1)
	{
	message_vision("\n"
+ HIW"		$N將"HIY"現代通行證"HIW"交給守衛...\n"NOR
+ HIW"			守衛在驗證後並啟動傳送機器...\n"NOR
+ HIW"		一到強烈的"HIC"藍光"HIW"將$N包住，\n"NOR
+ HIW"			光線消失後，$N也隨著不見了...\n\n\n"NOR,me);
	me->move("/open/world2/anfernee/start/login");
	destruct(ob);
	return 1;
	}
	else return notify_fail(HIW"現代通行證呢??\n"NOR);
	}
	else if( arg == "card3")
	{
	ob = present("past card", me);
	if(objectp(ob)==1)
	{
	message_vision("\n"
+ HIW"		$N將"HIY"過去通行證"HIW"交給守衛...\n"NOR
+ HIW"			守衛在驗證後並啟動傳送機器...\n"NOR
+ HIW"		一到強烈的"HIC"藍光"HIW"將$N包住，\n"NOR
+ HIW"			光線消失後，$N也隨著不見了...\n\n\n"NOR,me);
	me->move("/open/world2/anfernee/start/login");
	destruct(ob);
	return 1;
	}
	else return notify_fail(HIW"過去通行證呢??\n"NOR);
	}
}
