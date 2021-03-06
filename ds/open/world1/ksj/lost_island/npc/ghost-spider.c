#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"魑"MAG"背蛛蠍"NOR, ({"ghost spider","spider"}) );
  set("long",@LONG
一隻巨大的蜘蛛，有著一條蠍子尾巴，牠的背上呈現不規則的隆起，
同時有一個像是鬼臉的白色紋路，頭上數條明顯的疤痕蓋去了幾顆眼
睛。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "雄性" );
  set("level",45+random(3));
  set("title",RED"  魔獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴","腹部","背部" }) );
  set("verbs", ({"bite","claw"}) );
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if(!random(2) )
  {
    message_vision(HIW"\n魑"MAG"背蛛蠍"NOR"察覺到有生物進來，迅速地朝$N吐出一張巨形蛛網！！\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision("$N高舉蠍尾，猛力刺向$n！\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100),me);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+5));
    return 1;
  }
  return 0;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",2);
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);      
  switch( random(99) )
  {
    case  0..2: new(__DIR__"eq/primeval-sword")->move(this_object());
          break;
    case 40..99: new(__DIR__"eq/primeval-dagger")->move(this_object());
          break;
  }
  ::die();
  return;
}
