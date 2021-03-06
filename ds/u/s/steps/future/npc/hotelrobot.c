#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
          set_name("酒館機械人",({"hotel robot","robot"}));
          set("long","酒館的主人自己在多年前製造的機械人，由於已經很舊了，\n"
                         "所以現在只能做一些簡單的買賣工作。\n"
          );
          set("age",50);
          set("level",1);
          set("sell_list",([
                 __DIR__"obj/alcohol"        : 50, 
                 __DIR__"obj/groundnuts"        : 50, 
                 __DIR__"obj/meat"        : 50,
        ]));
        set("chat_msg", ({
                "機械人將飲品和食物送到客人的桌上。\n",
                "機械人到處在清理桌上的垃圾。\n",
        }));
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
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "機械人走過來說道﹕歡迎光臨﹐來試試我們的酒吧。\n");
                        break;
                case 1:
                        say( "機械人說﹕這位採礦工人﹐剛工作完就來歇歇吧。\n");
                        break;
        }
}