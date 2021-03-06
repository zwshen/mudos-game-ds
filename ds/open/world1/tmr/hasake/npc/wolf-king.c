inherit NPC;
#include <ansi.h>

void create()
{
    set_name(HBK"灰狼王" NOR, ({ "wolf king", "wolf", "king"}) );
	set("race", "野獸");
	set("age", 70);
	set("level", 35);
    set("unique", 2);
    set("long", "狼以群居，這只帶頭的大灰狼比其它的大一倍以上，低沉地吼著。\n");
    set("attitude", "aggressive");	
	set("limbs", ({ "頭部", "牙齒", "前腳", "後腳", "前爪" }) );
	set("verbs", ({ "bite", "claw" }) );
    set("chat_chance", 20);
	set("chat_msg", ({
         "灰狼王的雙目在黑暗中閃著紅光，緊緊地注視著你的一舉一動。\n",
         "灰狼王發出一聲嗥叫，好像隨時都要撲上來！\n",
	}) );
	set("skin", __DIR__"obj/langpi");

	setup();
}

void die()
{
        object ob, obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        
      	// 掉皮
      obj = new( query("skin") );
      if(objectp(obj))
	      obj->move( this_object() ); 

  	  if( ob->getToDo("/open/quest/hasake_q4.c") ) {
  	  	  // 有接殺白狼神的任務，才有機會叫出白狼神
		  // 記錄殺狼王的次數
			ob->add_temp("hasake_wolf", 1);
	      if( ob->query_temp("hasake_wolf") > 3 + random(3) ) {
			  ob->delete_temp("hasake_wolf");
	      	  message_vision(HIW"四週的氣溫忽然全降了下來..."NOR, this_object());
	      	  new(__DIR__"white-wolf")->move(environment(this_object()));
	      }
      }
        ::die();
}
