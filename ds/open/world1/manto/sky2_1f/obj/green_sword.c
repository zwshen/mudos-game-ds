#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"碧綠長劍"NOR,({"green sword","greensword","sword"}));
        set("unit", "個");
        set("long",@LONG
一把碧綠色的長劍，劍身直插入地臺直至沒柄。如果你向它虔誠
祈禱(pray)的話，說不定會有甚麼奇妙的事情發生。

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
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="green sword" && arg!="greensword" && arg!="sword" )
        {
                notify_fail("你要對什麼禱告?\n");
                return 0;
        }

                message_vision(HIG"$N誠心的向碧綠色長劍祈禱，一片碧綠色的光芒圍繞著$N。\n"NOR,me);
        return 1;
}

