#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("白粉末",({"egg powder","powder"}) );
        set("long",@long
這是一堆由鬼鵰蛋所磨化的粉末，雪白之中隱隱帶著一股惡臭，名列
天下異物百名之列，不少武林中人都知，只要把這種粉末塗抹（daub）在
武器上頭，會提升該武器的功能，為一不可多得的寶物。
long
);
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1000);
        set("unit","堆");
        }
        setup();
}

void init()
{
        add_action("do_daub","daub");
}

int do_daub(string arg)
{
        object wp,me,ob;
        int roll;
        me=this_player();
        ob=this_object();

        if(!arg ) return 
                notify_fail("你要把白粉末塗抹在那樣武器上？？\n");
        if(!objectp(wp=present(arg,me) ) )
                return notify_fail("你身上沒有這樣東西。\n");
        if(!wp->query("skill_type") )
                return notify_fail("這樣東西不是武器類。\n");
        if( wp->query("equipped") )
                return notify_fail("你必須先放下這個武器。\n");

        if( wp->query_temp("egg_daub") >= 10) {

                tell_object(me,"看樣子，"+wp->query("name")+NOR "已經不能再塗白粉末了。\n");
                return 1;
        }

        message_vision("$N把一堆白粉末均勻地塗抹在$n"+NOR "表面。\n",me,wp);    
        roll = random(100);
        if( roll < 50 ) {
                string attr, c_attr;
                attr = "armor";
                c_attr = "防禦力";
                if( roll < 2 )        { attr = "str"; c_attr = "力量"; }
                else if( roll < 6 )  { attr = "con"; c_attr = "體質"; }
                else if( roll < 8 )  { attr = "int"; c_attr = "智慧"; }
                else if( roll < 18 )  { attr = "dex"; c_attr = "敏捷"; }
                else if( roll < 30 ) { attr = "hit"; c_attr = "命中率"; }
                wp->add( "weapon_prop/"+attr,1);
                tell_object(me, HIY "你覺得"+wp->query("name")+HIY"的"+ c_attr +"值提高了﹗\n" NOR);
                wp->add_temp("egg_daub", 1);         //塗過次數
        }
        else tell_object(me,"你並沒有覺得"+wp->query("name")+NOR "和先前有何不同。\n");
        destruct(ob);

        return 1;
}


