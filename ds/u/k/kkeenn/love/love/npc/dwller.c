#include <ansi.h>
inherit NPC;
void create()
{
        set_name("城民",({ "dwller" }));
        set("long","一個無憂無慮的城民。\n");
        set("level",5);
        set("title",HIM"《情城池》"NOR);
        set("age",15);
        set("gender","女性");
        setup();
        add_money("coin",300);
      carry_object(__DIR__"obj/whip1")->wield();
}
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
}

