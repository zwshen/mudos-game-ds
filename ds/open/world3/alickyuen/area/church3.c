//updated 26/12
//debug -By Tmr- 2000/2/20

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"ST．Church＠God of moon"NOR);
        set("long", @long
來到這裡，又是一番新的景象，但最先要的就是要應付眼前的敵人吧
﹗你在打架途中看到這裡的中央也有一尊月影神像，但這尊的手卻沒有伸
出來。其次你又發現在靠牆的位置有一條繩索，你似乎可以靠他回到上面
了。
long
);
        set("item_desc", ([ /* sizeof() == 2 */
        "繩索" : "一條粗粗的繩，你可以利用它攀爬出去。\n",
        "月影神像" : "一座宏偉的石像,有一點不可思議....\n",
        ]));
        set("objects", ([ /* sizeof() == 4 */
        __DIR__"npc/goda" : 1,
        ]));
        set("light",1);
        setup();
}

void init()
{
        add_action("do_climb","climb");
        add_action("do_search","search");
}
int do_climb(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg != "繩索") 
                   return 0;
       message_vision(HIR"$N大力捉著繩索，慢慢地爬出這裡。\n"NOR ,me);
       me->move(__DIR__"church2");
       tell_room(environment(me),me->query("name")+"突然出現在你眼前。\n",me);
       return 1;
}

int do_search(string arg)
{
        object gun;
        object me;
        me=this_player();
        if( !arg || arg != "月影神像")          return 0;
        if( !me->query_temp("killgoda") )       return 0;
        message_vision("$N在月影神像的裂縫裡仔細仔細的搜尋...\n"  ,me);
        if( query_temp("get_gun") )
                 return notify_fail("找了又找，終究一無所獲...\n");
        message_vision("$N似乎在裂縫裡找到了一把槍？！\n" ,me);
        gun=new(__DIR__"obj/wp/moongun.c");
        gun->move(me);
        me->delete_temp("killgoda");
        set_temp("get_gun",1);      

        return 1;  
}

void reset()
{
        if( query_temp("get_gun") )
                delete_temp("get_gun");
::reset();
}


