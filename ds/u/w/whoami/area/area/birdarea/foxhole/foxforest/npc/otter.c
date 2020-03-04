#include <ansi2.h> 
inherit NPC;

void create() 
{
        set_name("水獺",({"otter"}));   
        set("long","身長三尺的一隻野獸，善游水，穴居河邊，補食魚群而生•\n");         
        set("level",23+random(5));
        set("attitude", "peaceful");
        set("race", "野獸");
        set("max_hp",3500+random(4000));
        set("str",40+random(2));  
        set("dex",40+random(2));   
        set("addition_damage",75+random(20));  
        set("addition_shield",50);  
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
}

void die()
{
        object me=this_object(),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(3) ){
         case 0:
           new(__DIR__"eq/fresh_fish")->move(me); 
         break;
         case 1:
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me);  
         break;
         case 2:
           new(__DIR__"eq/fresh_fish")->move(me);
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
         break;
         }

        if(!random(15)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"你得到 1 點聲望。"NOR);  
        }     
        ::die();
        return;
}        

