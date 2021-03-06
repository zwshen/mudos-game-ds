// thousand-hair 三千煩惱絲
// 情城池 進階技能
// tmr 2006/10/07

#include <ansi.h>
#define THE_WHIP      "/open/always/thousand-hair.c"

inherit SSERVER;
inherit SKILL;

int clone_whip(object me);

int exert(object me, object target, string arg)
{
        int cost;

    if(me->is_fighting() )
        return notify_fail("你正在戰鬥中。\n");

    cost = 100 + me->query_skill("thousand-hair")*3 ;

    if( me->query("ap") < cost )
        return notify_fail("你的內勁不足，無法使用「三千煩惱絲」。\n");

    message_vision(
        GRN"$N輕柔地唱出一段歌聲：「剪斷三千煩惱絲 化作風語入耳眠」\n" NOR
        ,me);
    
    me->receive_damage("ap",cost );
    me->start_busy(2);
    call_out("clone_whip",3, me);
    return 1;
}

int clone_whip(object me)
{
    object whip, ob;
    int sk, dex,dmg;
    if( !me ) return 0;
    if( me->is_fighting() )
        return notify_fail("什麼事也沒發生...\n");
    
    sk = me->query_skill("thousand-hair");
    dex = me->query_dex();

    if( objectp(ob = present("thousand-hair", me) )  ) {
        message_vision("結果什麼事也沒發生.....\n",me);
            return 1;
    }
    
    // 一次只能有一條三千煩惱絲
    if( objectp(ob = present("THOUSAND_HAIR_WHIP", me) )  ) {
        message_vision("結果什麼事也沒發生.....\n",me);
        return 1;
    }
        
        // 找一條whip 來當基礎
    if( !objectp(ob = present("whip", me) )  ) {
        message_vision("結果什麼事也沒發生.....\n",me);
            return 1;
    }
    
    whip=new(THE_WHIP);
    
    if(!whip->move(me) ) {
            message_vision("似乎好像發生什麼大問題了，請快通知巫師解決，謝謝。\n",me);
            return 1;
    }

    if(!whip->move(me) ) {
                message_vision("結果什麼事也沒發生.....\n",me);
                return 1;
        }
        
        dmg = ob->query("weapon_prop/damage")*(1.0 + sk*0.005);
        whip->set("weapon_prop/damage", dmg);
        whip->set("weapon_prop/dex", sk/20);
         whip->set("weapon_prop/con", sk/20);
    message_vision(HIM "$N剪下一撮撮的頭髮，運用心法，將髮絲跟$n"HIM"搓揉在一起，最後竟形成一條長達七尺的長鞭！！\n" NOR, me, ob);
      me->improve_skill("thousand-hair", dex + random(dex) );
    ob->unequip();  // unwield whip
    destruct(ob);       // 刪掉舊的鞭子

    return 1;
}

int improve_limite(object ob)
{
    if(ob->query_dex() < 80) return 70;
    return 100;
}


