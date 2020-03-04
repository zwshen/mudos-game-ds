#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石間");
        set("long", @LONG
有ball。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
]));
        set("item_desc", ([
  "石頭" : "一顆圓滾滾的鐵球, 由紫陽山上溪流所沖積下的所形成的\n",
]));
        set("world", "past");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_take", "take");
}


int do_take(string arg)
{
        object me = this_player(),  
        if( arg != "ball" && arg != "鐵球" );     
        ball = new(__DIR__"iron_ball");
        if( arg != "ball" )
                return 0;
        if( query_temp("use_take") )
                return 0;        message_vision(HIG"$N從溪裡撈出了一顆鐵球！\n"NOR, me);
        ball->move(me);
        me->set_temp("take_ball", 1);
        set_temp("use_take", 1);
        this_object()->close_take(this_object());
        return 1;
}

void close_take(object obj)
{
        set("long",@LONG
沒ball。

LONG
        );
        obj->delete("item_desc/鐵球");
        call_out("delay", 600, this_object());
}

void delay(object obj)
{
        set("long", @LONG
有ball。

LONG
        );
        set("item_desc/鐵球" ,"一顆圓滾滾的鐵球, 由紫陽山上溪流所沖積下的所形成的. \n");
        delete_temp("use_take");
}

