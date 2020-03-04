//u/c/chiaa/world2/blackly_forest/assembly_room.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "會議室");
        set("long", @LONG
這是忍者村的會議室,裡面有一張大桌子和幾個椅子,
桌上一本厚重的石書吸引你的注意力!
在這裡討論和決定的都是有關村裡的重大事項,
因此能進來這裡的人,不是身分較高的忍者就是村裡的長老!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"nivi_square1",  //廣場1

        ]));
        
    set("item_desc",([
        "石書":"一本奇怪的書,頗有重量。\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors","ninja_village");
        setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string str)  //系統會將玩家所輸入的"push"這個指令後的所有                             文字以字串型別的引數傳給 do_push()　 
                         //將 do_push 這個函數宣告為                                            //int do_push(string str)
                         //str指當玩家下達一些指令時,就會被存進字串
                         //變數str之中供你處理　
{
        object me;
       me=this_player();
        
          if(!str || str!="石書") return 0;
            message_vision(
"$N一股奇怪的吸力,將你吸了進去。\n",me );
             me->move(__DIR__"den");
        
        tell_room(environment(this_player()),
        me->query("name")+"被一股奇怪的吸力送到這裡。\n", me);
        return 1;
}
