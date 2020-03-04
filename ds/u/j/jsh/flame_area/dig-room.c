#include <ansi.h> 
inherit ROOM;
void create()
{
        set("short", "古坑內");
        set("long", @LONG 
你身處在一坑地洞裡，深數十尺深，幾乎九十度的轉角，讓光線
隔離在外，此坑的正中央比其他的地方還要軟，不知道是否有什麼東
西？！ 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "up" : "/open/world1/wilfred/sand/room27",
]));
     set("item_desc", ([ /* sizeof() == 1 */
       "坑中央" : "軟軟的，不知道藏了什麼東西？好像可以挖吧(dig)。\n",
     ]));
         set("no_recall",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{ 
         add_action("do_dig","dig");
}

int do_dig(string arg)
{
        object me,item;
        me=this_player(); 
        if(this_object()->query_temp("DIGED")==1) return notify_fail("剛剛有人挖過了。\n");
        if(arg != "坑中央") return 0;
        if( me->is_busy() ) return notify_fail("你的動作還沒有完成。\n");
        else {
                message_vision("$N用力的翻動坑中央的軟泥土••\n",me); 
                message_vision("挖到了！挖到一面鏡子了！\n",me); 
     item=new(__DIR__"npc/obj/mirror");
     item->move(environment(me)); 
                me->start_busy(2);  
                this_object()->add_temp("DIGED",1);
                //call_out("DIG_OUT",5,me); 
                call_out("DIG_TEMP",1000,this_object());
                return 1;
        }
}  
/*
void DIG_OUT()
{
     object me=this_player(),ob=this_object(),item; 
     switch(random(4))     { 
     case 0:
     message_vision("挖到了！挖到一面鏡子了！\n",me); 
     item=new(__DIR__"npc/obj/mirror2");
     item->move(environment(me));
     break; 
     case 1:
     message_vision("挖到了！挖到一面鏡子了！\n",me);
     item=new(__DIR__"npc/obj/mirror");
     item->move(environment(me)); 
     break;
     }
     return;
} 
*/
void DIG_TEMP()
{
     this_object()->delete_temp("DIGED",1);
     return;
}

