#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "院子");
        set("long", @LONG
這個院子裡雖只有幾顆小樹，卻堆放著上百堆的石頭。這些石頭有大
有小，大如一間房屋，小如一個鴨蛋。你發現旁邊矮牆下有一條深溝，下
面水花盈盈看不清有什麼東西。身後有道鐵門(door)，不過已經關上了。
一股股的腥臭味飄來，使你快要做嘔了。
LONG);
        set("exits", ([
              "northwest" : __DIR__"backyard07",
              "jumpdown" : __DIR__"lake01",
        ]));

        setup(); 
}

void init()
{
     	object me = this_player();
        add_action("do_climb", "climb");
        add_action("do_push", "push");
               
}

int do_climb(string arg)
{
        int dex;
        object me = this_player();

        dex = me->query_dex();

        if (me->is_busy() || me->is_fighting() )
        	return notify_fail("你正忙著呢。\n");
        	
       	if (dex < 18 )
        	return notify_fail("這矮牆雖矮，你卻怎麼也翻不過去。\n");
       	if (dex > 17 ){  
           	message_vision("$N雙手在矮牆上一按，一翻身便縱了過去。\n", me);
           	me->move(__DIR__"backyard05");
           	message("vision", me->name() + "從院子裡面翻了過來。\n",environment(me), ({me}) );
           	return 1;
           	}     
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        str = me->query_str();

       	if( !arg ) return 0;
       	if (arg == "door" ){        
       		if( (int)me->query_skill("anti_poison", 1)){
           		message_vision("$N蹲下身子，雙掌平伸推向鐵門。\n", me);
           		message_vision("鐵門突然打開，$N一沒留神滾了進去。鐵門卻又合上了。\n", me);
           		me->receive_damage("hp", 100);
           		me->receive_damage("mp", 50);
           		me->move(__DIR__"backyard05");
           		message("vision", "只聽啪的一聲，一個人影從鐵門出滾了過來！\n",environment(me), ({me}));
           		}
       		if (str < 21 )
               		return notify_fail("你使出了吃奶的力氣，可就是推不動這鐵門。\n");
      		else {  	
           		message_vision("$N使出全身力氣推向鐵門，可鐵門卻紋絲不動。\n", me);
           		me->receive_damage("hp", 300);
           		me->receive_damage("mp", 150);
           		}       
       		}
       return 1;        
}