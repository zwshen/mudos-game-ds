#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("電擊棒",({"electric shock stick","stick" }) );
    set("long",@LONG
這是一枝造價不便宜的電擊棒，雖然短小，但是常人要是被它的
勇猛的電力接觸到，想不昏也難。電擊棒背後貼著一小張說使用方法
，上面寫著：
                電        擊   shock
                調整電力大小   adjust
而上頭的電力大小調整在：
LONG
        );
        if(!clonep() )
        {
                set("value",12000);
                set("unit","枝");
        }
        set("electric",1000);   //電力
        set("adjust","low");            //低壓電力
        set("long",query("long")+query("adjust")+"\n");
        setup();
}

void init()
{
        add_action("do_shock","shock");
        add_action("do_adjust","adjust");
}

int do_shock(string arg)
{
        object me,target;
        me=this_player();
        if(!arg) return notify_fail("你要電擊誰呢？？\n");
        target=present(arg,environment(me));
        if(me->is_busy() )
                return notify_fail("你正忙著，沒有空做這動作。\n");
        if(!objectp(target) )
                return notify_fail("這附近沒有這個東西。\n");
        if(userp(target) && target!=me )
                return notify_fail("你不能對其他玩家出手。\n");
        if(query("electric") <= 0)
                return notify_fail("這枝電擊棒已經用光電力了。\n");
        if(target==me) {
                if( me->query_stat("hp") < 50)
                        return notify_fail("你的生命垂危，無法做這種危險的動作。\n");
                if( me->query_stat("nina") < 50)
                        return notify_fail("你體內的念力不足，做此動作會引發生命危險。\n");
                message_vision("$N拿起手中的電擊棒往自已身上一戳...\n",me);
                switch(query("adjust") )
                {
                        case "high":
                                message_vision(HIB "一陣焦臭味從$N身上傳了出來.....\n" NOR,me);
                                add("electric",-(10*random(3)));
                                /* 變-電性念力 技能經驗*/
                                if( me->query_learn("electric nina") ) {
                                        me->improve_skill("electric nina",2+random(me->query_attr("int")));
                                        me->improve_skill("psychical",random(3) );
                                }
                                me->consume_stat("hp",10);
                                me->start_busy(1);
                                break;
                        case "middle":
                                message_vision(HIB "$N禁不住呻吟了一聲，似乎被電痛了.....\n" NOR,me);
                                add("electric",-(5*random(3)));
                                /* 變-電性念力 技能經驗*/
                                if( me->query_learn("electric nina") ) {
                                        me->improve_skill("electric nina",1+random(me->query_attr("int")/2));
                                                me->improve_skill("psychical",random(3) );
                                }
                                me->consume_stat("hp",5);
                                me->start_busy(1);
                                break;
                        case "low":
                                message_vision(HIB "$N臉上一陣青一陣白，似乎有點難忍耐被電的感覺....\n" NOR,me);
                                add("electric",-(3*random(3)));
                                /* 變-電性念力 技能經驗*/
                                if( me->query_learn("electric nina") ) {
                                        me->improve_skill("electric nina",1+random(5));
                                        me->improve_skill("psychical",random(3) );
                                }
                                me->consume_stat("hp",2);
                                me->start_busy(1);
                                break;
                }
        } else {
                return notify_fail("目前不開放攻擊其他人的行為。\n");
        }
        return 1;
}

int do_adjust(string arg)
{

        if(!arg)
                return notify_fail("你要調整電力大小到多少呢？(high,middle,low )\n");
        switch(arg)
        {
                case "high":
                        set("adjust","high");
                        return notify_fail("你將電擊棒上的電力大小調整至「高電力」的位置。\n");
                        break;
                case "middle":
                        set("adjust","middle");
                        return notify_fail("你將電擊棒上的電力大小調整至「中電力」的位置。\n");
                        break;
                case "low":
                        set("adjust","low");
                        return notify_fail("你將電擊棒上的電力大小調整至「低電力」的位置。\n");
                        break;
                default:
                return notify_fail("你要調整電力大小到多少呢？(high,middle,low )\n");
        }
}



