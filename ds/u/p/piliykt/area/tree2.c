inherit ROOM;
void create()
{
set("short","樹枝");
set("long", @LONG
你走到這裡, 發現四周都是佈滿了藤蔓和樹枝, 這裡似乎是沒路可以
走了, 讓你不竟覺得自己是迷路了.
LONG
);
set("outdoors", "desert");
set("exits", ([ 
                "west"  : __DIR__"tree1.c",
                           ]));
 set("item_desc",([
        "樹洞":"一個可以讓人爬進去的小樹洞。\n",
        ]) );
 
setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
       me=this_player();
        if (!arg || arg!="樹洞" ) return 0;
        message_vision("$N趴在地上很努力的鑽進樹洞。\n",me);
        me->move(__DIR__"llll");
        tell_room(environment(me),me->query("name")+"有一個人從樹洞外爬了過來。\n",me);
        return 1;
}

