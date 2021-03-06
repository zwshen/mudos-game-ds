#include <ansi.h>
inherit ITEM;

void do_heal(object me);

void create()
{
    set_name("龍皮帳篷", ({"dragon-skin tent", "tent", "_TENT_"}));
    set_weight(500);
    set("long2", @LONG
這是一個很久很久以前的故事了，有兩個名叫艾尼斯戴爾瑪與傑克特斯
的年輕人，一起到一個農場應徵工作，兩人因此結識。此後兩人的世界立刻
天旋地轉，卻幾乎毫無進步。他們都很確定自己要有穩定收入、結婚生子，
卻又渴望另一種無法言語的感情。之後當他們到壯麗的斷背山牧羊時，艾尼
斯與傑克因此發展出革命情誼，甚至更親密的關係。而你，目前就正處在他
們曾經在山上使用過的帳篷中。

        每個人心裡都有一個斷背山，只是你沒有上去過。
    往往當你終於嘗到愛情滋味時，已經錯過了，這是最讓我悵然的。

使用方法: use tent
LONG
               );
        set("long", query("long2"));
    if( clonep())
        set_default_object(__FILE__);
    else
    {
        set("short","龍皮帳篷內");
        set("value", 10000);
    }
    set("no_recall",1);
    set("no_clean_up",1);
    set("no_goto", 1);
//    set_max_encumbrance(1);
    setup();

}

void init()
{
    add_action("do_sleep","use");
}

void sleep(int index, object me)
{
    object *obs;
    int i;

    if(!me)
                destruct(this_object());
    if(me->is_ghost() || !environment(me))  {
        obs = all_inventory(this_object());
        for(i=0;i<sizeof(obs);i++)
            obs[i]->move(environment(this_object()));
        delete("useing");
        delete("no_get");
        delete("no_sac");
        set("used",1);
        call_out("dest_obj",1);
        return;
    }

    if(environment(me) != this_object())
    {
        me->delete_temp("sleeping");
        call_out("dest_obj",1);
        return;
    }

    switch(index)
    {
    case 0 :
                tell_room(environment(this_object()),HIM+ name(1) + "裡傳來陣陣打呼聲。\n"NOR,me);
        write(HIR"\n[你覺得眼皮沉重，馬上就睡著了]\n\n"NOR);
        do_heal(me);
        break;

    case 1 :
                write(HIR"\n .......... ＺZｚzＺ\n\n"NOR);
        do_heal(me);
        break;

    case 2 :
                write(HIG"\n醒來後你覺得精神好了很多，打了個呵欠，從" + name(1)+ "裡走了出來。\n\n"NOR);
        tell_room(environment(this_object()),HIW+me->name(1)+"從"+ name(1)+"裡走了出來。\n"NOR,me);
        set("long","因使用過而變得破損不堪的"+ name(1)+"。");
        set_name("破損的帳篷",({"broken tent","tent"}));

        delete("useing");
        delete("no_get");
        delete("no_sac");

        set("used", 1);
        me->start_busy(0);
        me->delete_temp("sleeping");
        all_inventory(this_object())->move(environment(this_object()));
        break;
    }

    index++;
    if(index < 3) {
                if(!me->is_busy() )
                        me->add_busy(3);
                 call_out("sleep", 6,index,me);
        }
    else call_out("dest_obj", 2);
}

void do_heal(object me)
{
        me->receive_heal("hp", 1500);
        me->receive_heal("mp", 1500);
        me->receive_heal("ap", 1500);
}

void dest_obj()
{
    message_vision(HBK"\t一陣風吹來，將$N吹垮了。\n"NOR,this_object());
    destruct(this_object());
}

int do_sleep(string str)
{
    object ob = this_object(), me = this_player();
    if(!str || str != "tent") return 0;

    if(me->is_busy() || me->is_fighting())
        return notify_fail("你正在忙，沒空作其他事情。\n");
    if( !environment(me)->query("outdoors"))
        return notify_fail("你只能在戶外使用。\n"); // by -alickyuen@ds-
    if( query("used"))
        return notify_fail("這個帳篷已經正在使用了。\n");
    if(me->is_ghost())
                return notify_fail("你現在是鬼魂無法使用龍皮帳篷。\n");
    if(me->query_temp("killer"))
        return notify_fail("你殺了人暫時不可以使用龍皮帳篷。\n");
    if(me->query_temp("invader"))
        return notify_fail("你攻擊了玩家暫時無法使用龍皮帳篷。!\n");
    if(me->query("hp") < 0)     
                return notify_fail("你已經生命垂危了，沒法子搭帳篷。\n");

    set_max_encumbrance(999999);
    if(environment(ob) == me)
    {
        message_vision( HIG"$N從行李中拿出一個$n，很快的把$n搭好了。\n"NOR,me,ob);
        ob->move( environment(me) );
        ob->set("no_drop", 1);
    }
    message_vision(HIW"\n$N一個矮身，往$n鑽了進去，找了個好位置，舒舒服服的躺了下來。\n\n"NOR,me,ob);
        set("long", query("long2") +  "這個" +ob->name(1)+ "正被使用中。\n" );

    set("used",1);
    set("no_get", 1);
    set("no_sac", 1);

    me->move(ob);
    me->set_temp("sleeping",1);
    me->start_busy(16);
    call_out("sleep",5 , 0, me);
    return 1;
}
