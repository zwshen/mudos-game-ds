#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"抓狂時空隧道");
        set("long", @LONG
你被門吸到這個地方後發現這裡的一切事物都是抓狂的....
什麼不可能的事這裡都發生了..如果不快點離開這裡....
連你也可能會抓狂的......
LONG
        );
        set("item_desc",([
        "抓狂時空隧道":"一個會令人抓狂的隧道..你已快抓狂了∼。\n",
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
void init()
{
add_action("do_fly","fly");
}

int do_fly(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIY"$N突然拍了拍屁股放個屁就飛走了，！！。\n"NOR,me);
        me->move(__DIR__"workroom4.c");
        me->set_temp("the-door",1);
        return 1;
}

