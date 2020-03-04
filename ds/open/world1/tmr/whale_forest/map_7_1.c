inherit ROOM;
void create()
{
        set("short", "林中草地");
        set("long", @LONG
林中小徑到了這裡，就消失在一叢雜草堆中。
LONG
);
        set("exits",([
        "east" : __DIR__"map_7_2",
        ]));
        set("detail",([
        	"雜草":"一堆高可及腰的雜草，不知是否能穿越(pass)過去..\n"
        ]));
        set("map_long",1);     //show map as long
        set("outdoors","forest");
                set("objects", ([ /* sizeof() == 1 */
                          __DIR__"npc/bear" : 3,
                ]));

        setup();
}

void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me=this_player();        if(!arg || arg!="雜草")
                return notify_fail("你要穿越那裡？\n");
        if(me->is_busy())               return notify_fail("你現在沒有空。\n");        message_vision("$N撥開雜草走了進去...\n",me);   me->move("/d/whale_river/map_5_19");                    tell_room(environment(me),me->name()+"從雜草堆裡走了過來。\n",me);
        return 1;
}

