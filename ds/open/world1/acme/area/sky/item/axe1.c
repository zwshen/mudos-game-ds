#include <ansi.h>
#define IN_ROOM "/open/world1/acme/area/sky/secret"

inherit ITEM;
void create()
{
    set_name(HIR"血紅鐵斧"NOR,({"red axe","axe"}));
        set("unit", "把");
        set("long",@LONG
這是一把沾滿著天地各堂主及護法們鮮血的鐵斧，它象徵著各堂主及護法們
以鮮血悍衛天地會的忠心不二，更代表著他們為天地所付出的辛勞及努力。
你默然地注視著，不由自主地深感到由斧中傳來那莊嚴豪邁的氣勢，且也替
為了天地打拚而努力下了一計強心計。

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
        add_action("do_blood","blood");
}

int do_blood(string arg)
{
        object me;
        string place;
        me=this_player();
        
        if(arg!="red axe" && arg!="axe" )
        {
                notify_fail("你要對什麼滴血?\n");
                return 0;
        }

        message_vision(HIW"$N滴下一滴鮮血在$n上面。\n"NOR,me, this_object());

        if(CLUB_D->check_member("sky",getuid(me)) > 2 ||CLUB_D->check_member("ming",getuid(me)) > 3 || wizardp(me))
        {
                        tell_room(environment(me),me->name()+"漸漸消失的無影無蹤了。\n",({me}));
                        me->move(IN_ROOM);
                        write(HIG"  頓時一陣強光將你引入天地祕室。\n"NOR);
                        tell_room(environment(me),HIC"突然間一陣刺眼光芒，"+me->name()+HIC"隨著光芒出現於此地。\n"NOR,({me}));
                        return 1;
                }
         else
        {
                write(this_object()->name()+""HIC"似乎閃動了一下，隨即又回復了原狀。\n"NOR);
                return 1;
        }
}

