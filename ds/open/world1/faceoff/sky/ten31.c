#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"龍脊峰-西北邊"NOR);
 set("long",@LONG
你到了龍脊峰的西北邊, 這裡跟其他地方一樣的崎嶇, 
唯一不一樣的是你的正下方就是東北澤林囉, 一片翠綠的
東北澤林有讓你想跳下去的衝動....
LONG
    );
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb"); 
        add_action("do_jump","jump"); 
}
int do_climb(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1= load_object(__DIR__"ten32.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式： climb <方向> .\n");
        if( a!="south" )
                return notify_fail("這個方向你爬不過去\n");
     if (a = "south")
    {
        message_vision(HIW"$N從山壁上沿著南邊戰戰兢兢的爬去....。\n"NOR,me);
        me->move(where1);
    }
        return 1;
}
int do_jump(string arg)
{        
        object me; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要往那跳？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "down") return 0;
        message_vision(HIR"$N自認輕功\了得便不顧一切的往下一跳！！\n"NOR ,me); 
        me->move("/open/world1/whoami/birdarea/en1.c");
        message_vision(HIW"$N施展絕世輕功\，從"NOR+YEL"龍脊峰"NOR+HIW"跳下，$N居然毫髮無傷..\n"NOR ,me); 
        return 1;
}

