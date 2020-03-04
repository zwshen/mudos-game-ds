#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIW"白光門前"NOR);
        set("long", @LONG 
你正站在一扇白色的大門前，此大門透著淡淡白光，似乎有神
聖非常的東西在裡面，大門的上面，刻著白光之門的四個大字，鬼
斧神工的雕刻技巧，與微微的白光重疊在一起，形成一種說不出的
美感。
LONG
        ); 
        set("item_desc",([ 
        "白光之門":"一扇白色的大門，中間也一個[鑰匙孔(put x in x)]，旁邊有[白光之鑰]的圖案，是否有關聯？不得而知。\n",
        ]) );
        set("exits", ([ /* sizeof() ==  */ 
        "out" : __DIR__"room11",
]));
        set("light",1); 
        set("no_recall",1);
        setup();
}

void init()
{
     add_action("do_put","put");
}

int do_put(string arg)
{
             object me,x,key,z;           
             me = this_player();  
                             
        if(!arg || arg!="key in 鑰匙孔") return notify_fail("你要放什麼?\n");
        if(!objectp(z=present("white-light key",me) ) )
                return notify_fail("你沒有東西可以放啊 ? \n");
        message_vision(HIW"$N將白光之鑰放進了鑰匙孔，瞬間！！白光之鑰被吸了進去！不見了。\n"NOR,me); 
       {
        destruct(z);
    } 

        me->start_busy(5);
switch (random(2) ){
               case 0:
                     tell_object(me,"白門打開了.....\n"); 
                     message("world:world1:vision", 
                     HIW"\n\t白光之門在白光之鑰的消失之後•••打開了•••。\n"NOR,users()); 
                     write("竭達羅說：你跟巨鵰是同夥的對吧！！看你長的一臉鳥樣！\n");
                     x=new(__DIR__"npc/lou"); 
                     x->move(this_object());   
                     x->kill_object(this_object());                     break;
               case 1:
                     write("什麼事都沒發生••o.O\n");
                     break;
                 }  
        return 1;
}


