inherit NPC;

void create()
{
  set_name("小螃蟹",({"small crab","crab"}) );
  set("long","一隻比約一半掌心大小的螃蟹，正在岩石上覓食。\n");
  set("race", "野獸");    
  set("unit","隻");
  set("age",1);
  set("level",3);
  set("attitude", "heroism");  
  set("limbs", ({ "頭部", "身體", "右螯", "左螯" }) ); 
  set("verbs", ({ "bite" }) );         
  set("chat_chance", 5);
  set("chat_msg", ({
      "螃蟹邊揮舞雙螯一邊吐著泡沫。\n",
     }));              
  setup();
}