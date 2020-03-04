#include <ansi.h>
inherit NPC;


void do_mucus()
{
        if( is_busy() ) return ;
        if( !objectp(query_enemy())) return ;
        message_vision(GRN "$N對著$n吐出了口黏稠的酸液...\n" NOR, this_object(), query_enemy() );;
        query_enemy()->add_busy(1);

}

void create()
{
  set_name( "黏液怪" , ({"mucus odd","odd"}) );
  set("long",@LONG
這是一團黏液形成的怪物，這種黏液具有強烈的腐蝕性，
通常被包住的生物都是死路一條。
LONG
);
  set("race", "beast");
  set("unit","團");
  set("age", 3);
  set("gender", "雄性" );
  set("level", 15 );
  set("limbs", ({ "黏液" }) );
  set("verbs", ({ "bite", "claw" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
      set("chat_chance_combat",20);
        set("chat_msg_combat",({
                (: do_mucus :),
        }) );
  setup();
}

