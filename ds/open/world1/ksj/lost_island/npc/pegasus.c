#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"飛馬"NOR, ({"pegasus"}) );
  set("long",@LONG
一隻長了一雙白色羽翼的駿馬，美麗的模樣有如天馬下凡。
LONG
);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",10);
  set("level",27+random(2));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","前腳","後腳","翅膀" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
  (: random_move :),
  }));
  set("ridable",1); 
  setup();
}

int ride_before_action(object me)    
{
        int s = me->query("str");
        if( s<40 || !s )
        {
                message_vision("由於$N的力量不夠，無法控制"+this_object()->name()+"，因而被"+this_object()->name()+"從馬背上摔了下來！\n",me);
                return 0;            
        }
        else 

        {
                message_vision("$N使出全身的蠻力準備征服這隻"+this_object()->name()+"。\n",me);
                return 1;            
        }
}

int ride_after_action(object me)    
{
        message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
        set("chat_chance",0);
        return 1;                
}


int ride_off_action(object me)        
{
        message_vision("$N已經離開"+this_object()->name()+"了。\n",me);
        return 1;                    
}

