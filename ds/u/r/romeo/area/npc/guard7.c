#include <ansi.h>
inherit NPC;
void create()
{
        set_name(MAG "魏國守衛兵"NOR, ({ "ghost guard","ghost","guard" }) );
        set("level",35);
           set("combat_exp",4000);
         set("exp",3000);
set("long","這是一隻驍勇善戰的衛兵，從生時就被灌輸不怕死的理念，
看它們的壯碩的體形，一附氣勢凌人的樣子真叫人佩服。\n");
;
        set("age",50);
        set("evil",60);
     set("title",CYN"冥兵"NOR);
        set("gender","男性");
        set("attitude","killer");
             set_skill("unarmed",65);
        set_skill("dodge",65);
                  set_skill("parry",65);
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
          object me;
          me=this_player();
          if( !ob || environment(ob) != environment() ) return;
          {
            command("hehe");
            command("pk");
            say("魏國衛兵狂喊：膽敢侵犯皇陵，留下命來。\n");
            message_vision("魏國衛兵趁$N不注意時，偷襲暗算$N，發招猛攻。\n",me);
            message_vision("你看見魏國衛兵右手一揮，一道勁風，往$N急衝而去。
\n",me);
            message_vision(HIR "\n勁風往$N的腳上擊去，看來$N已受傷不輕。\n"NOR,me);
            me->receive_damage("hp",60);
            me->receive_wound("foot",5);
            set("attitude","killer");
          setup();
}
}

