#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name(HIM"嫦娥"NOR, ({ "the goddess of the moon","goddess","moon"}));
        set("long", "\n"
                    "他是住在月亮上頭的神仙，長得十分標緻，\n"
                    "且常常帶著笑容，在每年的中秋節，都能夠\n"
                    "見到他的蹤影哦。\n"
           );
        set("level",1);
        set("gender", "女性");
        set("race", "人類");
        set("age", 20);
        set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set("attitude", "peaceful");   //溫和的 NPC。
        set("no_fight",1);
        set("sell_list",([
            __DIR__"obj/pomelo" : 10,
            __DIR__"obj/cake1" : 10,
            __DIR__"obj/cake2" : 10,
            __DIR__"obj/cake3" : 10,
        ]) );
        setup();
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
{
       object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
           case 0:
               say("嫦娥說道：這位" + RANK_D->query_respect(ob)
                                + "﹐來買些月餅吃吃吧。\n");
               break;
           case 1:
               say("嫦娥說道﹕這位" + RANK_D->query_respect(ob)
                                + "﹐來買顆柚子吃吃吧。\n");
               break;
        }
}
