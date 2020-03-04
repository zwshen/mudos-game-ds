#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED "犬妖" NOR ,({"quan evil","evil"}) );
        set("long",@LONG
四絕妖之一，白鬼四幽中的魎湟幽鬼的手下。
LONG
);
        set("age",100);
        set("race","人類");
        set("title",HIC"四絕妖"NOR);
        set("level",30);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance_combat",10);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("sword",100);
setup();
     carry_object(__DIR__"wp/sword")->wield();
       
}

void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  if( random(500) )
    eqp=new(__DIR__"wp/sword");
  else
    eqp=new(__DIR__"eq/quan-evil-pin");
  eqp->move(this_object());
  ::die();
  return;
}

