#include <ansi.h>
inherit ROOM;
void show(object me);
void create()
{
        set("short", HIG"抓狂廁所"NOR);
        set("long",
"這裡是一間很臭的廁所..你得趕快逃跑才行ㄛ..\n"
"你突然看到馬桶裡有一個"HIY"金光閃閃"NOR"的東西...\n"

);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"workroom3",
        ]));
        set("item_desc",([
        "抓狂馬桶":"一個很臭的馬桶,似乎很久沒沖的樣子∼你看到裡面有一個金光閃閃的東西,讓你忍不住想挖(dig)出來。\n",
        "抓狂馬桶按鈕":"由於這裡實在太臭了∼你忍不住想按(push)下沖水(按鈕)。\n",
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
void init()
{
  object me;
  ::init();
  if( interactive(me = this_player()) && !me->is_fighting())
 {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
  add_action("do_push","push");
  add_action("do_dig","dig");
}
void hi(object me)
{
message_vision(HIC"哈哈哈"HIY + me->name(1) + NOR""HIC"大大你怎麼會摔到馬桶上面啊..好豬ㄛ.^^\n"NOR,me);
tell_object(this_player(),HIR"你突然哈哈哈的笑了起來..好像漸漸抓狂了..。\n"NOR);
return;
}
int do_push(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="按鈕") return 0;
        message_vision(HIY"$N的頭突然被吸到馬桶裡,好豬ㄛ！。\n"NOR,me);
        me->delete_temp("the-shit");
        me->move(__DIR__"shit");
        me->start_busy(4);
        call_out("flop",3,me);
        return 1;
}
void flop(object me)
{
        if(!me) return;
        if (me->query_temp("fly-sky")==1) return 0;
         tell_object(me,HIC"你從天空栽了下來，全身都是尿臭屎艘味，真的有夠ㄚ心的。\n");
        me->move("/d/wiz/hall1");
        tell_room(environment(me),me->query("name")+"從天空栽了下來，全身都是尿臭屎艘味，真的有夠ㄚ心的。\n"NOR,me);
        return;
}
int do_dig(string arg)
{
        object me,toy;
        me = this_player();
        toy = new(__DIR__"gold_shit");
        if( !arg ) return 0;
        if( arg!="抓狂馬桶" && arg!="馬桶" ) return 0;
if( query_temp("digshit") )
{
    return 0;
}
        message_vision(HIC"$N拼命的挖著抓狂馬桶,挖得全身是汗。\n"NOR,me);
        message_vision(HIY"$N終於在最臭的底層挖出了一沱黃金便便,臉不禁淫笑了起來。\n"NOR,me);
        toy->move(me);
        set_temp("digshit",1);
        this_object()->delete("item_desc");
        set("long",@LONG
這裡是一間很臭的廁所..你得趕快逃跑才行ㄛ..
LONG
        );
        call_out("delay",180,this_object());
        return 1;
        set("item_desc",([
        "抓狂馬桶":"一個很臭的馬桶,似乎很久沒沖的樣子∼。\n",
        "抓狂馬桶按鈕":"由於這裡實在太臭了∼你忍不住想按(push)下沖水(按鈕)。\n",
]));
}
void delay(object room)
{
        delete_temp("digshit");
        set("long",@LONG
這裡是一間很臭的廁所..你得趕快逃跑才行ㄛ..
LONG
        );
        set("item_desc",([
  "抓狂馬桶":"一個很臭的馬桶,似乎很久沒沖的樣子∼你看到裡面有一個金光閃閃的東西,讓你忍不住想挖(dig)出來。\n",
  "抓狂馬桶按鈕":"由於這裡實在太臭了∼你忍不住想按(push)下沖水(按鈕)。\n",
]));
        return;
}



