inherit ROOM;
 
void create()
{
        set("short", "迷霧");
        set("long", @LONG
你正走在一條小路，只見得四週盡是濃霧彌漫，伸手不見五指，往前
望去，隱隱約約只見勉強見到丈許小路.....
LONG
        );
	set("no_recall",1);
	set("outdoors","forest");
        setup();
}
void init()
{
	call_out("check_seal",0,this_player() );
	add_action("do_go","go");
}

int do_go(string dir)
{
	object me;
	me=this_player();
	if(me->query_temp("garea/road") == 5 && random(10) == 1 )
	{
		me->delete_temp("garea/road");
		me->move(__DIR__"forest16");
		tell_room(environment(me),"$N跌跌撞撞、汗流滿面地往這跑來。\n",me);
	}
	else
	{
		tell_object(me,"你走著走著...發現四周景色似乎沒有變...\n");
		me->add_temp("garea/road",1);
		if(me->query_temp("garea/road") == 6 ) me->set_temp("garea/road",1);
	}
	return 1;
}

int check_seal(object me)
{
	object obj;
	if(objectp(obj=present("seal",me) ) && obj->query("name")=="驅風符" )
	{
	tell_object(me,"忽然起了一陣疾風，把你四週的迷霧吹開了。\n");
	me->move(__DIR__"forest16");
	}
	return 1;

}
