#include <ansi2.h>

inherit ITEM;

void create()
{
        set_name(HIC"天梟聖泉"NOR, ({ "holy pool","pool" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long",
                "一個遼闊無邊的天然水池，其內的水乃是來自於十萬大山\n"
                "眾多溪河的灌溉，大自然規率的調節，以至於四周並沒有\n"
                "任何的人工圍籬，水也不會過滿而溢出•水池中還傳來陣\n"
                "陣撲鼻的藥味，也是因為這座靈山中的各種藥材，隨著溪\n"
                "水漂流至此，以巧妙的比例混合而成，這實在是造物者的\n"
                "完美傑作•\n");
                set("unit", "潭");
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me=this_player(),ob=this_object();
        int m_hp,m_ap,m_mp;

        m_hp=me->query("max_hp"); 
        m_mp=me->query("max_mp");
        m_ap=me->query("max_ap");

        if( arg != "pool") return notify_fail("你要喝什麼??\n");
        if( me->is_busy()) return notify_fail("你還在忙耶\n");
        message_vision("$N用手掬了一口池中的清水，一口飲了下去……\n",me);
        tell_object(me,HIG"一股暖暖的感覺從你的口中傳到了丹田，這股暖暖的氣息又從丹田流竄到全身各處……\n"NOR);
        me->receive_heal("hp",m_hp); 
        me->receive_heal("ap",m_ap);
        me->receive_heal("mp",m_mp);
        me->receive_curing("all",100); 
        me->start_busy(3);
        ob->add_temp("drinking",1);
           if( ob->query_temp("drinking") > 18 ) {
         destruct(ob);
        } 
        return 0;}
