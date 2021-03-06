// Room: /open/world1/tmr/freezetaoism/temple7.c

inherit ROOM;

void create()
{
        set("short", "寒澈道觀-禪室");
        set("long", @LONG
這裡是道觀內的一座禪室，為道觀主持時常關閉修禪的房間，室內除
居中有個蒲團外，就再也沒有其他東西，可說是簡陋到極點，但也看得出
來在修禪時，可以大大減少外界的干擾。
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"temple4",
        ]));
        set("no_clean_up", 0);
        set("item_desc",([
        "蒲團":"一個坐起來很舒服的蒲團。\n",
        ]));

        setup();
}
void init()
{
        if( query_temp("have_down_road") ) {
                message_vision("只聽得一陣喀啦喀啦的聲響，祕道又關了起來。\n",this_player() );
                set("exits", ([ /* sizeof() == 1 */
                        "north" : __DIR__"temple4",
                ]));
		delete_temp("have_down_road");
        }
        add_action("do_move","move");
}
int do_move(string arg)
{
        if (arg != "蒲團")
                return 0;
        if( query_temp("have_down_road") ) return notify_fail("祕道已經開啟了。\n");
        message_vision("$N移走了蒲團，現出一條往地下的祕道。\n",this_player() );
                set("exits", ([ /* sizeof() == 1 */
                        "north" : __DIR__"temple4",
                        "down" : __DIR__"downroad1",
                ]));
        set_temp("have_down_road",1);
        return 1;
}

