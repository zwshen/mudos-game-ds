#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "側墓室");
        set("long",@LONG
走到這，發現好像走到了墳墓的盡頭。走到這裡，你心中不經有一
點點的疑惑，因為一路走來，除了剛剛的棺木和壁畫之外，連一樣東西
都沒有。別說是陪葬物，連傳說中無名英雄的戰甲也沒見到。難道，傳
說是騙人的？不過，怎麼連這裡的牆壁都感覺有點怪怪的....
LONG
        );
        set("exits", ([
        "north" : __DIR__"fere.c",
        ]));
        set("item_desc",([
	"牆壁":"看起來好像可以打(hit)穿...。\n",
        ]));
        set("no_clean_up", 0);
        set("light", 0);
        setup();
}

void init()
{
	add_action("hit_wall","hit");
}

int hit_wall(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="牆" || str=="牆壁")
	{
	object me;
	me=this_player();
	
	message_vision(
	HIG"\n$N沉穩的出拳擊向牆壁，兩邊的牆應聲而破。\n"NOR
	HIG"\n轟的一聲，牆倒了。\n"NOR,me);

        set("long",@LONG
走到這，發現好像走到了墳墓的盡頭。走到這裡，你心中不經有一
點點的疑惑，因為一路走來，除了剛剛的棺木和壁畫之外，連一樣東西
都沒有。別說是陪葬物，連傳說中無名英雄的戰甲也沒見到。難道，傳
說是騙人的？兩邊的牆被你打出個大洞了。
LONG
        );
	
	set("item_desc",([
        "牆壁":"左右兩邊的牆壁上都出現的一個大破洞。\n",
        ]));

	set("exits", ([
        "north" : __DIR__"fere.c",
	"west":__DIR__"grav5.c",
	"east":__DIR__"grav6.c",
        ]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
	set("long",@LONG
走到這，發現好像走到了墳墓的盡頭。走到這裡，你心中不經有一
點點的疑惑，因為一路走來，除了剛剛的棺木和壁畫之外，連一樣東西
都沒有。別說是陪葬物，連傳說中無名英雄的戰甲也沒見到。難道，傳
說是騙人的？不過，怎麼連這裡的牆壁都感覺有點怪怪的....
LONG
        );
	set("exits", ([
        "north" : __DIR__"fere.c",
        ]));
        set("item_desc",([
	"牆壁":"看起來好像可以打(hit)穿...。\n",
        ]));
	delete_temp("opened");
	::reset();
}