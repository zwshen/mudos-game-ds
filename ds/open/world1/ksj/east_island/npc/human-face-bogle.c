#include <ansi.h>
inherit NPC;

void create()
{
  set_name("人面犬",({"human-face bogle","bogle"}) );
  set("long",@LONG
犬身人面的妖怪，面色猙獰四處襲擊民眾。
LONG
);
  set("race", "野獸");    
  set("unit","隻");
  set("age",47);
  set("attitude", "aggressive");
  set("level",25+random(4));
  set("limbs", ({ "臉部","身體","前腳","後腳"}) ); 
  set("verbs", ({ "bite","claw" }) );     
  set("chat_chance", 10);
  set("chat_msg", ({
      "人面犬吐著舌頭，用似狗似人的的笑容直盯著你。\n",
     }));                                
  setup();
  add_money("coin",400);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") < 26 && userp(this_player()) )
     this_object()->kill_ob(this_player());
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
  switch( random(100) )
  {
    case  0: 
          new(__DIR__"eq/hundred-bogle-necklace")->move(this_object());
          break;
    case  1..30: 
          new(__DIR__"eq/bogle-bead")->move(this_object());
          break;
  }
  ::die();
  return;
}
