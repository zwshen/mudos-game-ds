#include <ansi.h>
inherit ROOM;
void show(object me);
void create()
{
        set("short",HIR"抓狂之門"NOR);
        set("long",@LONG
這裡是sexking的家門口，據說sexking是一個很抓
狂的人，所以叫作抓狂之門，不過sexking為了怕
也有許多人抓狂所以設了機關讓人無法進來，以許
你可以搜搜(search)看機關在哪裡。
LONG
);

        set("item_desc",([
        "抓狂電鈴":"這是一個很可愛的電鈴，讓你忍不住想按(push)看看。\n",
        "抓狂之門":"這是一個很好笑的門，不知為什麼你看了就覺得好好笑，忍不住想碰(touch)看看。\n",
        ]) );
        set("outdoors","land");
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
setup();
}
void init()
{
        add_action("do_touch","touch");
        add_action("do_push","push");
        add_action("do_pupu","pupu");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
     if(!arg || arg!="抓狂之門") return 0;
     message_vision(HIR"$N抓狂的摸了一下門，突然抓狂之門張大了嘴巴將$N吸了進去。\n"NOR,me);
     me->delete_temp("the-door");
     me->move(__DIR__"door");
        me->start_busy(4);
        call_out("flop1",3,me);
        return 1;        
}

void flop1(object me)
{
        if(!me) return;
        if (me->query_temp("fly-sky")==1) return 0;

        tell_object(me,HIM"你突然從抓狂之門滾了出來，十分狼狽的樣子。\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"突然從抓狂之門滾了出來，十分狼狽的樣子。\n"NOR,me);
        return;
}
int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="抓狂電鈴") return 0;
     message_vision(HIG"$N抓狂的按了一下抓狂電鈴，突然冒出了一沱小麥草黏液將你$N包了起來將$N甩到了天上。\n"NOR,me);
     me->delete_temp("the-sky");
     me->move(__DIR__"sky");
        me->start_busy(4);
        call_out("flop2",3,me);
        return 1;        
}
void flop2(object me)
{
        if(!me) return;
        if (me->query_temp("fly-sky")==1) return 0;

        tell_object(me,HIW"你重重的摔到地上，跌個四腳朝天，屁股腫了一大塊起來。\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"重重的摔到地上，跌個四腳朝天，屁股腫了一大塊起來。\n"NOR,me);
        return;
}
int do_pupu(string arg)
{
        object me;
        me=this_player();
        if(arg!="屁")
        {
                notify_fail("你要放什麼ㄚ?\n");
                return 0;
        }
        if(this_player()->query("id") == "sexking")
        {
        if(me->can_move(__DIR__"workroom4"))
        message_vision(HIG"$N突然放了個屁，抓狂的大叫ㄚㄚㄚㄚㄚ...就化成一道光束不見了。\n"NOR,me);
             tell_room(environment(me),me->name()+"放的屁十分香讓你心情舒暢了起來。\n",({me}));
             tell_room(environment(me),me->name()+"利用屁的衝利像火箭一樣越衝越高....。\n",({me}));
                        me->move(__DIR__"workroom4");
                        write("你的屁屁用光了所以就掉了下來。\n");
                        tell_room(environment(me),me->name()+"突然從天上散怖清香降了下來。\n",({me}));
                        return 1;
                } 
                else
                {
                        write(HIC"不行..你放的屁太臭了..只有小麥草放的才是香的ㄛ...。\n"NOR);
                        return 1;
                }
        } 
// luky's code...
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 3:
         case 2:        tell_object(me,"你已經忍不住想要進入這個屋子裡了..但卻不知如何進入..。\n");
                        return 1;
         
         case 1:
         case 0:        tell_object(me,"你突然有一種奇特的感覺..好像全身飄飄欲仙。\n");
                        return 1;
default:       return 1;
        }
}

 
