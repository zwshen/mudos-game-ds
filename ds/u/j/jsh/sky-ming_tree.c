#include <ansi.h>
#define IN_ROOM "/open/world1/baal/ming_club/saintming"

inherit ITEM;
void create()
{
    set_name(HIW"天地明桐"NOR,({"sky-ming tree","tree"}));
        set("unit", "顆");
        set("long",@LONG
此樹是連接天地會總部，跟天地會分部『明教』的神奇之樹，
這顆樹散發著神聖白光，讓你忍不住想摸(touch)它一下。
LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        string place;
        me=this_player();
        
        if(arg!="sky-ming tree" && arg!="tree" )
        {
                notify_fail("你要摸什麼?\n");
                return 0;
        }

        message_vision(HIW"$N輕輕摸了$n一下。\n"NOR,me, this_object());

        if(CLUB_D->check_member("sky",getuid(me)) > 2 ||CLUB_D->check_member("ming",getuid(me)) > 3 || wizardp(me))
        {
                        tell_room(environment(me),me->name()+"漸漸消失的無影無蹤了。\n",({me}));
                        me->move(IN_ROOM);
                        write(HIY"頓時一陣強光將你帶到天地分會•『明教』。\n"NOR);
                        tell_room(environment(me),HIC"突然間一陣刺眼光芒，"+me->name()+HIC"隨著光芒出現於此地。\n"NOR,({me}));
                        return 1;
                }
         else
        {
                write(this_object()->name()+""HIC"似乎閃動了一下，隨即又回復了原狀。\n"NOR);
                return 1;
        }
}

