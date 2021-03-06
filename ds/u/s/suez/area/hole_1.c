#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short","洞中小室");
        set("long",@LONG
一盞昏暗的油燈和一張破舊的木桌，搖曳的燈光偶而掃到你的臉上，
不知從哪兒跑進來的雨蛙在靠牆的書架上嘓嘓的叫，兩三張小凳凌亂的擺
著，順著這裡的擺設看下去，赫然發現你的腳下竟有一個大石門﹗門上的
兩個大鐵環靜靜閃耀著赤紅的光輝，好像訴說著門下的神秘及危機，突然
一陣寒風吹入，讓你不禁毛骨悚然。
LONG
        );

         set("exits", ([
  "south": __DIR__"hole_out",
  "down":__DIR__"hole_2",
]));

        set("objects",([
          __DIR__"npc/pan-en" : 1,
]));
        set("light", 1);
        setup();
          create_door("down","石門","up",DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        object obj = this_object(), pan = present("pan-en", this_object());
        if( !objectp(pan) || !pan->visible(me) )
        {
                me->delete_temp("pan-en");
                return ::valid_leave(me, dir);
        }
        if( (dir=="down") && obj->query_temp("pan-en") > 0 && pan )
        {
                write("潘英大手一張，擋住你的去路。\n");
                return 1;
        }
        else if( (dir=="down") && objectp(pan) )
        {
                message_vision("$N說﹕生死禁地，有進無出，快快離去！\n", pan);
                call_out("kill_1", 7, me, this_object(), pan);
                me->set_temp("pan-en", 1);
        }
        else if( (dir=="down") && !objectp(pan) )
        {
                return ::valid_leave(me, dir);
        }
        else return ::valid_leave(me, dir);
}

void kill_1(object me, object obj, object pan)
{
        if( !me )return;
        if( !objectp(environment(me)) ) return;
        if( environment(me)!=obj ) return;
        else
        {
                message_vision("$N說﹕還不速離！莫怪在下手中兵刃！\n", pan);
                call_out("kill_2", 7 , me, obj, pan);
        }
        return;
}

void kill_2(object me, object obj, object pan)
{
        if( !me ) return;
        if( !objectp(environment(me)) ) return;
        if( environment(me)!=obj ) return;
        else
        {
                message_vision("$N說﹕再三警告還不離去！是看輕潘某否！\n", pan);
                call_out("kill_3", 7 , me, obj, pan);
        }
        return;
}

void kill_3(object me, object obj, object pan)
{
        if( !me )return;
        if( !objectp(environment(me)) ) return;
        if( environment(me)!=obj ) return;
        if( environment(me)==obj )
        {
                message_vision("$N說﹕留連不去！警告不聽！汝必有企圖！\n", pan);
                pan->kill_ob(me);
                return;
        }
//      this_object()->delete_temp("pan-en");
}
