inherit NPC;

#include <path.h>
#include <ansi.h>

void create()
{
  set_name("蜜糖", ({ "candy" }) );
  set("gender", "女性" );
  set("long",@long
可拉的貼心機械人。
long
);      
  set("age",20);
  set("level",200);

  set("race","human");

  set("chat_chance", 20);

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("hits") :),
(: command("bliz") :),

}) );
  setup();
  carry_object(__DIR__"icefist")->wield();
}


