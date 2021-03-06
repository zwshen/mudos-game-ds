#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "院子");
        set("long", @LONG
這裡堆放著上百堆的石頭。這些石頭有大有小，大如一間房屋，小如
一個鴨蛋，形狀大多都呈圓柱形。你發現從有些石頭之間的縫隙(chink)
中飄出一股股的腥臭味，使你快要做嘔了。
LONG);
        set("exits", ([
              "southeast" : __DIR__"backyard07",
              "northwest" : __DIR__"backyard09",
        ]));
         set("item_desc", ([                    
                "chink": "\n縫隙裡面漆黑一片，隱隱約約有沙沙的聲響。\n",
        ]));
        setup(); 
}

void init()
{   
		  	object me = this_player();
		  	if(me->query_skill("anti_poison", 1) < 50)
//            me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
      		if(me->query_temp("move_stone") > 2)
      		{
      		me->delete_temp("move_stone");
      		me->set_temp("move_wait", 1);
      		me->start_busy(3);
      		call_out("do_wait", 3, me);
        	}     
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me = this_player();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙著呢。\n");
        if( !arg || arg=="" ) return 0;

        if (arg == "chink" ){   
        	      message_vision("$N刨開縫隙口的亂石子，一彎腰往縫隙裡鑽了進去。\n",me);
                me->move(__DIR__"chink02");
                message("vision",me->name() + "從外面鑽了進來。\n",environment(me), ({me}) );
                return 1;
        }     
}

void do_wait(object me)
{
	object room;
	if(!me || environment(me) != this_object()
	|| !living(me) || !me->query_temp("move_wait")) 
		return;
        message("vision","\n石柱忽然發出軋軋的聲音，向一側緩緩移開，向下露出一個黑洞洞的入口。\n\n", this_object() );
        set("exits/down", __DIR__"lane01");
        if( room = load_object(__DIR__"lane01") ) {
                room->set("exits/up", __FILE__);
                message("vision","\n頭頂上的石柱忽然發出軋軋的聲音，露出一個光亮亮的洞口。\n\n",room );
                } 
        remove_call_out("close_door");
        call_out("close_door", 5);
}


void close_door()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision","\n石柱發出軋軋的聲音，緩緩地移回原處，將向下的洞口蓋\住了。\n\n", this_object() );
        if( room = load_object(__DIR__"lane01") ) {
                room->delete("exits/up");
                message("vision", "\n頭頂上發出軋軋的聲音，石柱又緩緩地收了回去，階梯消失了。\n\n", room );
                }
        delete("exits/down");
}

int valid_leave(object me)
{        
       me->delete_temp("move_wait");
       return ::valid_leave(me);
}
