#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("店小二", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 12);
        set("long","這位店小二正笑咪咪地忙著。\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "跑 堂");
        set("sell_list",([
                __DIR__"obj/mountain_vegetable" : 8,
                __DIR__"obj/tea" : 10,
                __DIR__"obj/tea1":10,
          __DIR__"obj/manto":10,
              __DIR__"obj/wine":18,
        ]) );
        setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
}

