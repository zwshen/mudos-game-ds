// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", HIC"新芳鄰旅館"NOR);
        set("long", @LONG
你在一間旅社裡，這是全城中服務最好且設備最完善的旅社，出外旅
行的人一定都會投宿在這裡補充一日所消耗的精力。櫃臺小姐親切的笑容
讓你會感覺到賓至如歸的感覺。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"room068",
            "up"   : __DIR__"room104",
            ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/miss1.c" : 1,
                __DIR__"npc/h_boss.c" : 1,
        ]));

        set("no_clean_up", 0);
        set("valid_startroom",1);
        set("light", 1);
        set("no_fight",1);
        set("room_type","hotel");       // 旅館

        set("item_desc", ([
                "note": (: look_sign :),
                "告示": (: look_sign :),
        ]) );

        setup();
        call_other( "/obj/board/aovandis_b", "???" );
}
void init()
{
        add_action("do_dusting","dusting");
}

string look_sign(object me)
{
   if( file_size("/open/world2/shengsan/aovandis/note.txt") > 0 )
   {
    me->start_more( read_file("/open/world2/shengsan/aovandis/note.txt") );
    return "\n";
   } else return " SORRY. 說明建構中. \n";
}
int room_effect(object me)
{
     int i;
     me=this_player();
     i=me->query_temp("addmoney");
    if(me->query_temp("dusting")>1 && query_temp("dustok") < 59 ) 
     {
       if(me->query("ap")<5) return notify_fail("你的體力不夠了，無法再打掃了。\n");
       message_vision("$N努力的掃呀∼掃呀∼但地板似乎都掃不乾淨。\n",me);
       me->receive_damage("ap",5);
       me->set_temp("addmoney",i+1);
       set_temp("dustok",query_temp("dustok")+2);
     }
    if(me->query_temp("dusting") > 1 && query_temp("dustok") > 59)
    {
     tell_object(me,"你發覺地板乾乾淨淨，再也掃不到垃圾了，還是等一回再來吧。\n");
     call_out("delay",600,this_object());
            message_vision("旅館老板說道：掃乾淨了，不用再掃了！\n",me);
            message_vision("旅館老板從櫃檯拿出了"+ i*20 +"枚金幣給$N。\n",me);
            me->receive_money(i*20);
          me->delete_temp("addmoney");
          me->delete_temp("dusting");
    }
}

int valid_leave(object me, string dir)
{
if( dir=="west" && me->query_temp("dusting") >1 )
        {
          me->delete_temp("dusting");
          message_vision("$N將掃把往牆角一丟，停止了打掃的工作。\n",me);
          return 0;
} else return ::valid_leave();
}

int do_dusting(string arg)
{
        object me;
        me=this_player();
        if(me->query_temp("dusting") == 0)
        {
          tell_object(me,"旅館老板沒說要顧用你，你就幫忙打掃，難不成你要做白工？\n");
         return 1;
        }
        else {
         if(me->query_temp("dusting")>1 ) return notify_fail("你已經認真的在打掃了。\n");
          me->set_temp("dusting",2);
          message_vision("$N拿起了牆角的掃把，開始認真的打掃。\n",me);
            return 1;
        }
}
void delay(object room)
{
    object me;
    me=this_player();
   say("地板越來越髒了，你發覺旅館老板的臉色怪怪的。\n");
        delete_temp("dustok");
     return;
}

