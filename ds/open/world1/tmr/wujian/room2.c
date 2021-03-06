// Room: /open/world1/tmr/wujian/room2.c

inherit ROOM;

void create()
{
        set("short", "無間小道");
        set("long", @LONG
霧茫茫的一片，在此黑暗的洞穴內，似乎有種極為恐怖的生物，
沙沙的聲響不斷的發出。到這兒已經是盡頭了，你注意前方牆壁有道
暗梯，在濃霧中忽隱忽現，暗梯上口似乎有道火光。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1",
]));
        set("item_desc",([      
        "暗梯" : "一道天然形成的暗梯，你可以爬(climb)上去看看。\n",
        ])      );

        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
}



int do_climb(string arg)
{
        object me;
        if(!arg || arg != "暗梯") return notify_fail("你想要爬什麼？");
        me=this_player();
        if(me->is_busy()) return notify_fail("你上一個動作還沒完成。\n");
        message_vision("$N爬上暗梯，沒幾步就沒入濃霧之中了。\n",me);
        me->move("/open/world1/jangshow/flame_area/room");
        return 1;
}

void init()
{
 add_action("do_climb","climb");
}
