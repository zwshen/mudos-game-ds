// 2001.7.25 version
// 新增horse->setting(id) 以識別馬主身分
// 設定為每人只限買一匹馬
// alickyuen@ds 2003.1.12
#include <dbase.h>
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("周詳連", ({ "horse seller" , "seller" }) );
        set("long", @LONG

在步靈城中連詳馬廄的主人，他正用心的照顧各種類的馬匹中。
你可以問問他有賣那種馬(list)，或是向他購買各種品種的馬(buy)。
    
LONG
        );
        set("level", 10);
        set("no_fight",1);
        set("age",   50);
        set("chat_chance", 1);
        set("chat_msg", ({
  (: command("say 最近真是閒呀..") :),
  (: command("sigh") :),
  (: command("say 不知道還會有客人上門否 ?") :),
}) );
        set("sell_list",([      
                    "/open/world1/horse/horse1": 5,
                    "/open/world1/horse/horse2": 5,
                    "/open/world1/horse/horse3": 5,

]));
        setup();
        add_money("coin",50);
}

void init()
{
     ::init();
        add_action("do_buy","buy");
        add_action("do_list","list");
}
