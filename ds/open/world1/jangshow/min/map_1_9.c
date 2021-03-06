#include <ansi.h>
inherit ROOM;
//簡單方式之鑲嵌 room,可補充
void create()
{
        set("short", "石板路");
        set("long", @LONG

LONG
);
        set("exits",([
        "south" : __DIR__"map_2_9",
        "east" : __DIR__"map_1_10",
        "west" : __DIR__"map_1_8",
        ]));
        set("item_desc",([
        "白牆":"一面白牆，上面寫著『宣讀(account)』，不知道蘊含著什麼意思？\n", 
        "石牆":"一面石牆，上面刻著 [godcome + xxx] 的咒文，不知道是作什麼用的？\n",
        ]));
        setup();
        set("map_long",1);     //show map as long
}
void init()
{
add_action("do_account","account");
add_action("do_godcome","godcome");
}


/***********************以下為可補充的************************/   
int do_account(string arg)
{ 
    object me=this_player(),obj; 
    if(arg=="red") 
    { 
    if(this_object()->query_temp("inlay/red")==8) return notify_fail("已經足夠了.\n");
    if(!objectp(obj=present("red stone",me)) ) return 0;
    else{   
    message_vision("$N宣讀了寶石名稱："HIR"紅寶\n"NOR,me); 
    message_vision(HIR"紅寶"HIW"幻化為一道紅光，消失在牆壁內。\n"NOR,me); 
    this_object()->add_temp("inlay/red",1);
    this_object()->delete_temp("inlay/blue"); 
    this_object()->delete_temp("inlay/white");
    this_object()->delete_temp("inlay/green");     
    destruct(obj); 
    }
    return 1;
    }
    if(arg=="blue")
    {  
    if(this_object()->query_temp("inlay/blue")==10) return notify_fail("已經足夠了.\n");
    if(!objectp(obj=present("blue stone",me)) ) return 0;
    else{
    message_vision("$N宣讀了寶石名稱："BLU"藍寶\n"NOR,me); 
    message_vision(BLU"藍寶"HIW"幻化為一道藍光，消失在牆壁內。\n"NOR,me); 
    this_object()->add_temp("inlay/blue",1);
    this_object()->delete_temp("inlay/white");
    this_object()->delete_temp("inlay/red");
    this_object()->delete_temp("inlay/green");   
    destruct(obj); 
    }
    return 1;
    } 
    if(arg=="green")
    {  
    if(this_object()->query_temp("inlay/green")==6) return notify_fail("已經足夠了.\n");
    if(!objectp(obj=present("green stone",me)) ) return 0;
    else{
    message_vision("$N宣讀了寶石名稱："HIG"綠寶\n"NOR,me); 
    message_vision(HIG"綠寶"HIW"幻化為一道綠光，消失在牆壁內。\n"NOR,me); 
    this_object()->add_temp("inlay/green",1);
    this_object()->delete_temp("inlay/red"); 
    this_object()->delete_temp("inlay/white"); 
    this_object()->delete_temp("inlay/blue");    
    destruct(obj); 
    }
    return 1;
    }
    if(arg=="white")
    {  
    if(this_object()->query_temp("inlay/white")==4) return notify_fail("已經足夠了.\n");
    if(!objectp(obj=present("white stone",me)) ) return 0;
    else{
    message_vision("$N宣讀了寶石名稱："HIW"白寶\n"NOR,me); 
    message_vision(HIW"白寶"HIW"幻化為一道白光，消失在牆壁內。\n"NOR,me);  
    this_object()->add_temp("inlay/white",1);
    this_object()->delete_temp("inlay/blue");   
    this_object()->delete_temp("inlay/red");  
    this_object()->delete_temp("inlay/green");    
    destruct(obj); 
    }
    return 1;
    }
}  
int do_godcome(string arg)
{
    object me=this_player(),ppl;
    if(arg=="blue")
    { 
     if(this_object()->query_temp("inlay/blue") !=10) return 0;
     else     message_vision("\n$N大喊：萬能的天神啊！請降臨在我的面前！\n",me);  
     ppl=new(__DIR__"doll_1")->move(environment(me)); 
     this_object()->delete_temp("inlay/blue");
     return 1;
    } 
    if(arg=="red")
    { 
     if(this_object()->query_temp("inlay/red") !=8) return 0;
     else     message_vision("\n$N大喊：萬能的天神啊！請降臨在我的面前！\n",me); 
     ppl=new(__DIR__"doll_2")->move(environment(me)); 
     this_object()->delete_temp("inlay/red");
     return 1;
    } 
    if(arg=="green")
    { 
     if(this_object()->query_temp("inlay/green") !=6) return 0;
     else     message_vision("\n$N大喊：萬能的天神啊！請降臨在我的面前！\n",me); 
     ppl=new(__DIR__"doll_3")->move(environment(me)); 
     this_object()->delete_temp("inlay/green");
     return 1;
    }     
     if(arg=="white")
    { 
     if(this_object()->query_temp("inlay/white") !=4) return 0;
     else     message_vision("\n$N大喊：萬能的天神啊！請降臨在我的面前！\n",me); 
     ppl=new(__DIR__"doll_4")->move(environment(me)); 
     this_object()->delete_temp("inlay/white");
     return 1;
    } 
}
/*
int do_inlay(string str)
{
    object obj,me; 
    me=this_player(); 
    if(this_object()->query_temp("inlay/blue") == 10) 
       return notify_fail("裡面已經鑲了十顆藍寶，你沒看到嗎？\n");     
    if(this_object()->query_temp("inlay/red") == 8) 
       return notify_fail("裡面已經鑲了八顆紅寶，你沒看到嗎？\n");    
    if(this_object()->query_temp("inlay/green") == 6) 
       return notify_fail("裡面已經鑲了六顆綠寶，你沒看到嗎？\n");    
    if(this_object()->query_temp("inlay/white") == 4) 
       return notify_fail("裡面已經鑲了四顆白寶，你沒看到嗎？\n");     
    if(!objectp(obj=present("blue stone",me)) ) 
*/


