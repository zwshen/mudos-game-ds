#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－山坳");
        set("long", @LONG
這裡位於山壁間的一處凹陷，山凹裡面竟然是一大片冰壁，透過
冰壁約略可以看見冰壁後面是一個大山洞，從山坳裡面源源流出清澈
冰涼的水，匯聚成一條小溪，流向草原。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room19",

]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("item_desc",([
        "冰壁":"可以試著打碎它(hit)。\n",
        ]));

        setup();
}

void init()
{
        add_action("hit_wall","hit");
}

int hit_wall(string str)
{
        if(this_object()->query_temp("opened") != 0) return 0;
        
        if(str=="冰壁")
        {
        object me;
        me=this_player();
        if(me->query_str()<50 ){
        message_vision(HIR"\n$N一拳擊向冰壁，--叩-- 一聲響，冰壁絲豪無損，只留下淡淡血跡。\n"NOR,me);
        me->receive_damage("hp",30,this_object());
        return 1;}
        message_vision(
        HIW"\n$N猛力一拳擊向冰壁，--乓-- 一聲響，冰壁頓時成碎裂一地的冰塊。\n"NOR,me);
        set("long", @LONG
這裡位於山壁間的一處凹陷，山凹裡面是一個大山洞，從山洞中
傳出不絕的寒氣，從山坳裡面源源流出清澈冰涼的水，匯聚成一條小
溪，流向草原。
LONG
        );
        
        set("item_desc",([
        "冰壁":"冰壁已經被打碎了。\n",
        ]));

        set("exits", ([
        "east" : __DIR__"room19",
        "enter" : __DIR__"room21",
   
        ]));
        
        set_temp("opened",1);
        return 1;
        }
}

void reset()
{
        set("long", @LONG
這裡位於山壁間的一處凹陷，山凹裡面竟然是一大片冰壁，透過
冰壁約略可以看見冰壁後面是一個大山洞，從山坳裡面源源流出清澈
冰涼的水，匯聚成一條小溪，流向草原。
LONG
        );
        set("exits", ([
        "east" : __DIR__"room19",
        ]));
        set("item_desc",([
        "冰壁":"可以試著打碎它(hit)。\n",
        ]));
        delete_temp("opened");
        ::reset();
}
