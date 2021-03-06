#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
	set_name( "鐵路車長" , ({ "driver" }) );
	set("long",@long
一個鐵路的車長，負責駕駛鐵路行駛。
long
);

	set("age", 50);
	set("level", 5);
	set("str", 2);
	set("int", 2);
	set("con", 2);
	set("dex", 2);
	setup();
	call_out("do_train",60,"train_station",0);
}

int accept_object(object who,object ob)
{
	
	if(ob->query("id")=="coin" && !this_object()->query_temp("do_train") )
	{
	if (ob->query_amount() >= 50)
		{
		command("smile");
		command("say 你好，請你現在進入車廂(enter train)，很快就會開出。");
		who->receive_money(- ob->query_amount() );
		who->set_temp("do_train",1);	
		}
		else
		{
		command("say 你要坐的話就給我一些錢吧。");
		}
	return 1;
	}
	return 0;
}
void do_train(string arg,int flag)
{
	object ob;
	ob=this_object();
if(flag==0)
{
	command("say 你們坐好，現在開車了。");
	ob->set_temp("do_train",arg);
	ob->move(__DIR__"train");	
	command("say 你們坐好，現在開車了。");
	tell_room(environment(ob),"車長按下一個按鈕，鐵路即時開動。\n");
	environment(ob)->set("exits",([]) );
	call_out("do_train",20,arg,1);
}
else
{
	message_vision("你感到車速開始變慢，看來快到達了。\n",ob);
	command("say 到達了，大家快下車吧。");
	environment(ob)->set("exits",(["out":__DIR__+arg]) );
	ob->move(__DIR__+arg);
	if(arg=="train_station1") arg="train_station";
	else arg="train_station1";
	call_out("do_train",60,arg,0);

}
	return;
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	
	if(!arg || arg != "train") return 0;
	if(!me->query_temp("do_train") ) return 0;
	me->move(__DIR__"train");
	me->delete_temp("do_train");
	tell_room(environment(me),"$N走上了車廂。\n",me);
	return 1;
}