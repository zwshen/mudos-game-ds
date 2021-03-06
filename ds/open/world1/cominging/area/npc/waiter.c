#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("店小二" , ({ "waiter" }));
        set("long",
        "他是這一家店的店小二，他正忙著幫忙照顧客人。\n"
        "你可以用訂(bespeak)來向他訂一些東西．\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  "店小二對你說: 客倌請進請進 !\n",
  (: command,"smile" :),
  (: command,"bow" :),
  (: command,"say 客倌您好∼" :),
  (: command,"say 請問是要歇息還是要住宿呢？" :),
}));
        set("inquiry",([
  "歇息" : "歇息(bespeak)一次 100 文錢∼！\n",
  "住宿" : "住宿一次共要 300 文錢喔∼！\n",
]));
        set("sell_list",([
  "/obj/example/dumpling" : 6,
  __DIR__"obj/bag": 6,
  __DIR__"obj/winebag": 6,
        "/open/world1/tmr/wujian/npc/obj/iron-hoe.c": 30,
]));
        set("no_fight",1);
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
    if( this_player()->query("id") == "phoenix" && !userp(this_player()) )
    {
        command("kick "+this_player()->query("id"));
        this_player()->move("/open/world1/cominging/area/bnorth.c");
    } 
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑笑對你說: 客倌請進請進  !\n");
                        break;
                case 1:
                        say( "店小二向你介紹說：本店的酒是全鎮有名的。\n");
                        break;
        }
}

int do_bespeak(string arg) // rest & sleep
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || sscanf(arg,"for %s",c)!=1 )
                return notify_fail("你要跟小二訂那種類型呢？(bespeak for {rest|sleep})\n");

        switch(c) {
        case "rest":
                if( !me->can_afford(100) )
                        return notify_fail("你身上的錢不夠。(100文錢)\n");
                me->add_temp("rest",1);
                me->receive_money(-100);
                message_vision("$N付給了$n歇息的費用，總共約一百多文錢。\n",me,ob);
                command("nod "+me->query("id"));
        break;

        case "sleep":
                if( !me->can_afford(300) )
                        return notify_fail("你身上的錢不夠喔。(300文錢)\n");
                me->receive_money(-300);
                me->add_temp("sleep",1);
                message_vision("$N付給了$n住宿一次的費用，總共三百多文錢。\n",me,ob);
                command("nod "+me->query("id"));
        break;

        default:
                write("你要歇息(rest)還是住宿(sleep)呢？\n");
        break;
        }
        return 1;
}

