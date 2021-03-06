#include <ansi.h>
inherit ROOM;
string look_well(object me);
static int water=1;
void create()
{
	set("short", "水井");
        set("long", @LONG
          這裡有個破舊的水井(well)。
LONG
);
	set("exits",([
	"east" : __DIR__"map_5_7",
	"south" : __DIR__"map_6_6",
	"north" : __DIR__"map_4_6",
	"west" : __DIR__"map_5_5",
	]));
        set("item_desc",([      
        "well" : (:look_well:),
        ])      );

    set("objects", ([
       __DIR__"../npc/beast_butterfly_1" : 2,
    ]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long

}

string look_well(object me)
{
	if(water) return "這口水井的水位很高。\n";
	else return "這口井似乎已經乾了很久了。由於井並不深，跳(jump)下去也不會受傷。\n";
}

int query_well()
{
	return water;
}

void set_water(int full)
{
	string waterlong,nowaterlong;
	object *inv=({}),room;
	waterlong=@HAVEWATER
這個井的水似乎取之不盡，井底長了許多水草。
HAVEWATER;
	nowaterlong=@NOWATER
這個井似乎乾了很久，井底長了許多長長的雜草。
NOWATER;
	if(full==0)
	{
		if(water==1)
		{
			water = 0;
			inv = all_inventory(this_object());
			if(sizeof(inv)) inv->move(this_object(), 1);	
			this_object()->set("no_clean_up",1);
			if(room=find_object(__DIR__"well1"))
			{
				room->set("long",nowaterlong);
				room->delete("no_recall");
				tell_room(room,HIC+"\n\t突然間一陣空間扭曲，井水突然消失了！！\n\n"+NOR);
			}
			if(room=find_object(__DIR__"well2"))
			{
				room->set("long",nowaterlong);
				room->delete("no_recall");
				tell_room(room,HIC+"\n\t突然間一陣空間扭曲，井水突然消失了！！\n\n"+NOR);
			}
		}
	}
	else
	{
		if(water==0)
		{
			water = 1;
			this_object()->set("no_clean_up",0);
			inv = all_inventory(this_object());
			if(sizeof(inv)) inv->move(this_object(), 1);
			if(room=find_object(__DIR__"well1"))
			{
				room->set("no_recall",HIC"你被水嗆的無法專心請求神助"NOR);
				room->set("long",waterlong);
				tell_room(room,HIC+"\n\t突然間一陣空間扭曲，井水從四面八方湧入你的口鼻之中！！\n\n"+NOR);
				inv = all_inventory(room);
				if(sizeof(inv)) inv->water_effect();
			}
			if(room=find_object(__DIR__"well2"))
			{
				room->set("long",waterlong);
				room->set("no_recall",HIC"你被水嗆的無法專心請求神助"NOR);
				tell_room(room,HIC+"\n\t突然間一陣空間扭曲，井水從四面八方湧入你的口鼻之中！！\n\n"+NOR);
				inv = all_inventory(room);
				if(sizeof(inv)) inv->water_effect();
			}
		}
	}
}

void init()
{
	if(water) return;
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	if(!arg)
	{
		write("你想跳(jump into)到哪裡?\n");
		return 1;
	}
	if(arg=="into well")
	{
		message_vision("$N往井裡跳了下去。\n",this_player());
		this_player()->move(__DIR__"well1");
		if(!this_player()->query_temp("invis"))
			tell_room(environment(this_player()),this_player()->name()+"從上面跳了下來。\n",({this_player()}));
		return 1;
	}
	write("你想跳(jump into)到哪裡?\n");
	return 1;
}

void reset()
{
	if(this_object()->query("no_clean_up")) return;
	::reset();
}

int handle_well_effect(object me)
{
	if(!water) return 1;
	if(random(me->query_skill("swim"))<20)
	{
		message_vision("$N因為無法呼吸顯得很痛苦。\n",me);
		me->set_temp("temp/death_type","[[1;36m溺斃身亡[0m]");
		me->receive_damage("hp",me->query("max_hp")/10);
	}
	return 1;
}
