#include <ansi2.h>

inherit ROOM;

void create()
{
        set("short", HIY"月亮桂樹[頂層]"NOR);
	set("long", @long
你現正在月亮桂樹之上，在這裡你可以好清楚看到天空上幾千百
萬個太陽，不知為何會突然發生這個異像，或許你可以在這試著用你
撿到的樹枝當成箭般射向太陽，把多出來的太陽們一一射下，為民除
害。
long);
	set("no_fight", 1);
	set("no_exert", 1);
	set("no_cast", 1);
	set("no_recall",1 );
	set("exits", ([
                "down" : __DIR__"tree3",
	]));

	setup();
}

void init()
{
//        add_action("do_search", "search");
	add_action("do_shoot", "shoot");
//        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();

        if( arg != "tree" && arg != "moon tree" ) return 0;

        if( me->is_busy() || me->is_block() )
                return notify_fail("你正在忙中！\n");

        message_vision("$N慢慢地往"HIY"月亮桂樹"NOR"上爬了上去。\n",me);
        me->move(__DIR__"tree3");
        me->start_busy(2);
        me->receive_wound("right_arm", 3+random(5));
        me->receive_wound("left_arm", 3+random(5));
        me->receive_wound("right_leg", 3+random(5));
        me->receive_wound("left_leg", 3+random(5));
	me->start_busy(2);
	return 1;
}

int do_search(string arg)
{
	object me, bow;
	me = this_player();

	if( arg == "tree" || arg == "moon tree" )
	{
		message_vision("$N開始仔細的檢查這個地方...\n", me);
		me->start_busy(2);
		if( objectp(present("wood bow", me)) )
		{
			tell_object(me, "經過仔細的搜查之後, 你沒有發現什麼可疑的東西。\n");
			return 1;
		}
		bow = new(__DIR__"bow");
		if( bow->move(me) )
		{
			tell_object(me, HIW"你發現地上有一把木做的弓！\n"NOR);
			return 1;
		}
	}
}

int do_shoot()
{
	object me, weapon;
	int power;

	me = this_player();
	weapon = me->query_temp("weapon");

        if( me->query("hp") < 51 )
	{
		write("你的體力不足以射箭到太陽那裡。\n");
		return 1;
	}
	if( !weapon || !objectp(weapon) || weapon->query("id") != "wood bow" )
		return notify_fail("請先裝備好木弓才能射太陽呀！\n");

	if( !weapon->query_temp("shooting") )
	{
		if( me->is_busy() ) { write("你正在忙著！\n"); return 1; }
                message_vision(HIW"$N隨地撿起一支樹枝當成箭，舉起了$n大力一拉向天空描準著其中之一個太陽....\n"NOR,me , weapon);
		tell_object(me, HIW"(若你認為描準完畢的話，想向發箭射太陽時就請再按一次[shoot]。\n"NOR);
		weapon->set("no_steal", 1);
		weapon->set("no_drop", 1);
		weapon->set_temp("shooting" ,1);
		me->receive_damage("hp", 50);
		call_out("add_power", 1, me, 1);
		return 1;
	}
	power = weapon->query_temp("shooting");
	message_vision(HIW"$N突然放手，弓中之箭在手中迅速飛向了天空...\n"NOR, me);
	tell_object(me , RED"射完此箭後,你感到體力盡失。\n"NOR);
        if( random(20) < power )
	{
		__DIR__"tree"->do_record(me);
	}
	else {
		tell_object(me, HIR"看來這次落空,射不中了....\n"NOR);
	}
	weapon->delete("no_steal");
	weapon->delete("no_drop");
	weapon->delete_temp("shooting");
	if( !random(5) )
	{
		message_vision(YEL"$N一不小心跌到樹下面去了....\n"NOR, me);
		me->move("/open/world1/cominging/area/boo-lin");
	}
	me->start_busy(2);
	return 1;
}

void add_power(object me, int power)
{
	object weapon = me->query_temp("weapon");
	
	if( !weapon || !objectp(weapon) || weapon->query("id") != "wood bow" )
		return;

	if( !weapon->query("no_drop") ) return;

	if( power > 20 || random(25-power) < 5 )
	{
                this_object()->fail(weapon);
		return;
	}
	weapon->set_temp("shooting", power);
	me->add_busy(1);
	call_out("add_power", 1, me, power+1);
	return;
}

void fail(object weapon)
{
        message_vision(HIR"因$N受不住你這麼大的拉力而被你拉斷了。\n"NOR, weapon);
	destruct(weapon);
	return;
}
