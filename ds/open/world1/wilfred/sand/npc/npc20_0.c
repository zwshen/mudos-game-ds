#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("¶À¨F¸é¹ÆÅo", ({ "desert robber","robber" }) );
  set("gender", "¨k©Ê" );
  set("long",@LONG
³o¬O¦¿´ò¤W´c¦W¬L¹üªº¸éÀ°¡Ð¡Ð¡y¶À¨FÀ°¡z¹ÆÅo¡C
LONG
);
  set("age",15);
  set("level",5);
  set("race","human");
  set_skill("dodge",30);
  set_skill("parry",20);

  setup();
  add_money("coin",500);
  carry_object(__DIR__"eq/eq10")->wear();
  carry_object(__DIR__"wp/wp5")->wield();
}

