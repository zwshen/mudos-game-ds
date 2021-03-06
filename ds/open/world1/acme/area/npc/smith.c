#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "打鐵匠", ({ "smith"}));
        set("long", "這是一位辛勤工作的打鐵匠。\n\n"
                      + "  看存貨請用 <list> \n"
                     + "  要買東西用 <buy 物品> <buy 數量 物品> \n\n");
        set("level",3);
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("combat_exp",2000);         //戰熟(約在mob level的100倍左右為宜)
        set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set_skill("hammer",10); 
        set("attitude", "peaceful");   //溫和的 NPC。
        set("talk_reply","方圓百里之內，我這家店所賣的武器，可是數一數二的哦！");
        set("sell_list",([
           __DIR__"wp/sword":10,
           __DIR__"wp/dagger":10,
           __DIR__"wp/blade":10,
           __DIR__"wp/arrow":100,
           __DIR__"wp/axe2":10,
        ]) );
        setup();
          add_money("coin", 150);           //帶的錢
          carry_object(__DIR__"wp/hammer.c")->wield();
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
        switch( random(3) ) {
           case 0:
               say("打鐵匠說道：歡迎光臨，請問這位" + RANK_D->query_respect(ob)
                                + "﹐需要些什麼呢?\n");
               break;
           case 1:
               say("打鐵匠恭敬地說道﹕這位" + RANK_D->query_respect(ob)
                                + "﹐請進請進。\n");
               break;
           case 2:
               say("打鐵匠說道：這位" + RANK_D->query_respect(ob)
                                + "﹐來買把武器防身吧。\n");
               break;
        }
}
