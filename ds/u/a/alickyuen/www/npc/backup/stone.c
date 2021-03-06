#include <ansi.h>
inherit NPC;

void create()
{
        set_name("士兵俑", ({"antiquity guard","guard"}) );
        set("long", @LONG
    古代皇陵內的護衛大軍，被古老神秘的法術賦予永恆的生命與職責，
永無止息的在古墓裡執行守護工作，殺盡任何敢擅闖古墓的活物。士兵俑
全是泥塑成型的高大人像，沒有知覺不會疲憊，堅硬的身軀不太畏懼尋常
兵器的攻擊。
LONG);
        set("age", 100);
        set("level",20);
        set("attitude", "aggressive");
        set_temp("apply/armor", 300);
        setup();
}

void init()
{       
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{ 
        //object me=this_player();
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIR"士兵俑喊道：膽敢擅闖皇陵！納命來！\n"+NOR,ob);
                        this_object()->kill_object(environment(ob));
        }
}

