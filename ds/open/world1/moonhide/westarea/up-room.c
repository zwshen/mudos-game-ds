#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "木柱前");
        set("long", @LONG
這裡是一片寬廣的草原，不時還有牛叫聲，也有清脆的鳥鳴
聲，像是人間天堂似的，但是所有的動物都不敢靠近草原正中間
的那根「木柱」，地上還有幾個斷掉的柳戒，頗為怪異。
LONG
        );

        set("item_desc",([
                "木柱":"一條呈六十度傾斜的木頭柱子，上面還有一對小小的勾子，似乎有什麼作用。\n",
                 "勾子":"一對小小的勾子，上面還有磨擦過的痕跡，你可以試試套在自已上(hold 勾子)。\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "north" : "/open/world1/wilfred/meadow/room3",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_hold","hold");
}

int do_hold(string arg)
{
    object me;
        me=this_player();
 
        if(me->is_busy() || me->is_fighting()) 
                return notify_fail("你正忙著。\n");
        if(!arg || arg!="勾子") return notify_fail("你想要套住什麼？\n");
        message_vision(HIW "$N將牢牢的套住兩邊的勾子，並穩穩的抓緊。\n",me);
        message_vision(HIY "木柱忽然涌起一股旋風，將$N彈上無窮遠的天際！！！\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{
        tell_object(me,"你大叫一聲的摔在雲層上面。\n");
          me->move(__DIR__"way4");
        tell_room(environment(me),me->query("name")+"摔在軟軟的雲層上面。\n",me);
        return;
}

