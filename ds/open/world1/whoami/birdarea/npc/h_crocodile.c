#include <ansi2.h>
inherit NPC; 

void create()
{

 switch( random(3) )
 {
 case 1:
  set_name("斷"HIW+BLK"頭"NOR"小鱷魚",({"headless crocodile","crocodile"}));
  set("limbs", ({ "身體", "前足", "後足", "尾巴" }) );
  set("verbs", ({ "claw"}) );
  break;
 default:
  set_name("斷"HIW+BLK"腿"NOR"小鱷魚",({"footless crocodile","crocodile"}));
  set("limbs", ({ "頭部", "身體", "尾巴" }) ); 
  set("verbs", ({ "bite", "crash"}) );
  break;
 case 2:
  set_name("斷"HIW+BLK"尾"NOR"小鱷魚",({"tailless crocodile","crocodile"}));
  set("limbs", ({ "頭部", "身體", "前足", "後足" }) ); 
  set("verbs", ({ "bite", "crash", "claw"}) );
  break;
 }
 set("long","牠是一隻殘障的鱷魚，看到牠這個樣子你還忍心殺牠嗎？\n");
 set("age",10+random(10));
 set("race", "野獸");
 set("level",50+random(20));
 set("title",HIW"東北"NOR"澤林"); 
 set("nickname","先天殘障"); 
 set("evil",-50);
 set("dodge",100); 
 set("unarmed",100);
 set("parry",100); 
 set("max_hp",random(100000));
 set("addition/bar",-10); 
 set("addition/hit",random(30)); 
 set("addition/dodge",random(30)); 
 setup();
}

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        ob->add("popularity",1);
        tell_object(ob,HIG"因為你的殘忍，你得到了１點聲望\n"NOR);
        ::die();
        return;
}

