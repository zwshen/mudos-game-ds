#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
	set_name( "老船伕" , ({ "shipman" }) );
	set("long",@long
這是一位年老的船伕。
long
);

	set("age", 60);
	set("level", 5);
	
	set("str", 2);
	set("int", 2);
	set("con", 2);
	set("dex", 2);

	setup();
	call_out("do_ship",60,"west",0);
}

int accept_object(object who,object ob)
{
	
	if(ob->query("id")=="coin" && !this_object()->query_temp("do_ship") )
	{
	if (ob->query_amount() >= 50)
		{
		command("smile");
		command("say 這位客倌，來來來，請上船稍坐(enter ship)，即刻開船。");
		who->receive_money(- ob->query_amount() );
		who->set_temp("do_ship",1);	
		}
		else
		{
		command("say 渡河的船資是五十文錢，童叟無欺。");
		}
	return 1;
	}
	return 0;
}

void do_ship(string arg,int flag)
{
	object ob;
	ob=this_object();
if(flag==0)
{
	command("say 各位客倌少坐了，要開船了。");
	ob->set_temp("do_ship",arg);
	ob->move(__DIR__"ship");	
	command("say 各位客倌少坐了，要開船了。");
	tell_room(environment(ob),"老船伕拿起了一隻長竹竿往河底撐去，渡船緩緩地移動了。\n");
	environment(ob)->set("exits",([]) );
	call_out("do_ship",20,arg,1);
}
else
{
	message_vision("你忽然覺得渡船一陣陣碰撞，想必已靠岸了。\n",ob);
	command("say 各位客倌，已靠岸了，請收拾好隨身的行曩，準備下船了。");
	environment(ob)->set("exits",(["out":__DIR__+arg]) );
	ob->move(__DIR__+arg);
	if(arg=="east") arg="west";
	else arg="east";
	call_out("do_ship",60,arg,0);

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
	
	if(!arg || arg != "ship") return 0;
	if(!me->query_temp("do_ship") ) return 0;
	me->move(__DIR__"ship");
	me->delete_temp("do_ship");
	tell_room(environment(me),"$N走上了渡船。\n",me);
	return 1;
}


