#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("書架", ({ "book shelf", "shelf" }));
        set("long", "這是一個書架, 上面有零零落落的幾本書, 你可以找找看有沒有什麼書可以用. \n");
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "個");
                set("value", 1);
                set("no_sell", 1);
                set("no_sac", 1);
                set("no_get", 1);
        }
        setup();
}

void init()
{
        add_action("do_search", "search");
}

int do_search(string arg)
{
        object me = this_player(), book = new(__DIR__"oldman_book.c");

        if( !me->query_temp("get_book") )
                return 0;
        if( !this_object()->id(arg) )
                return 0;
        else if( me->query_temp("get_book") && this_object()->id(arg) && !this_object()->query_temp("no_book") )
        {
                message_vision(YEL"$N在書架上找了找, 似乎略有所獲.. \n"NOR, me);
                tell_object(me, HIC"你找到了一本小冊子！\n"NOR);
                book->move(me);
                me->delete_temp("get_book");
                me->set_temp("got_book", 1);
                set_temp("no_book", 1);
                set("long", "這是一個書架, 上面有零零落落的幾本書, 似乎最近有人翻過. \n");
                call_out("delay", 600, this_object());
                return 1;
        }
        else if( me->query_temp("get_book") && this_object()->id(arg) && this_object()->query_temp("no_book") )
        {
                message_vision(YEL"$N在書架上找了找, 似乎沒有所獲.. \n"NOR, me);
                return 1;
        }
        return 0;
}

void delay(object obj)
{
        delete_temp("no_book");
        set("long", "這是一個書架, 上面有零零落落的幾本書, 你可以找找看有沒有什麼書可以用. \n");
        return;
}
