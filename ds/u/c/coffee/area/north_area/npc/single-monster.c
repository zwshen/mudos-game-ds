#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIB"獨"HIW"眼獸"NOR, ({"single monster","monster"}) );
  set("long",@LONG
一隻只有一隻眼睛的奇異怪物。另一隻眼睛似乎是被挖掉的。表情十
分猙獰，身上不斷散發出邪惡之氣。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",70);
  set("attitude", "aggressive");
  set("gender", "雄性" );
  set("level",45+random(3));
  set("title",HIR"魂獸"NOR);
  set("limbs", ({ "頭部", "身體","尾巴","腹部","背部" }) );
  set("verbs", ({"bite","claw"}) );
        set("chat_chance",10);
        set("chat_msg",({
        (: random_move() :),
        }) );
  setup();
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
    message_vision(HIB"獨"HIW"眼"HIB"獸"NOR"發覺有人靠近，奮力的一跳，讓整個地面震動！！\n"NOR,this_player() );
    this_player()->add_busy(random(1)+1);
  }
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision("$N憤怒地用爪子瘋狂的爪向$n，讓$n的胸口出現數條血痕！！\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100),me);
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
  ::die();
  return;
}

