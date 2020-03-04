#include <ansi.h>
inherit NPC; 
void create() 
{ 
       set_name(HIR"血蛟"NOR,({"blood snake","snake"}));
       set("gender","野獸");
       set("level",52);
       set("max_hp",33333); 
       set("age",432+random(32));      
       set("attitude","unfriendly");
       set("devil",40); 
       set("limbs", ({ "頭部", "身體", "腹部","背部","腰部" }) );
       set("verbs", ({ "bite","claw"}) ); 
       set("long",@LONG        
渾身通紅的蛟龍，與點液算是同出一徹，但比點液更加兇猛！

LONG
); 
        setup();
}  
void die()
{
   object ob,obj;
   obj=new(__DIR__"obj/snake-waist");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",4);
        message("world:world1:vision",
   HIR"\n\t"+ob->name(1)+"怒道：仆街吧！！與點液同出一徹的血蛟！！\n\n"+NOR
        ,users());
       obj->move(environment(this_object() ) );
       obj=new(__DIR__"obj/snake-liver");
       obj->move(environment(this_object() ) );
        ::die();
        return;
}
void special()
{
        object me=this_object();
        object* target; 
        int dam = 400 + random(me->query_skill("unarmed"));   
        if(me->is_busy() ) return;
        target=query_enemy();
       {
message_vision(HIW"\n一股巨大的"HIB"藍色能量"HIW"在$N口內不斷壓縮！！"HIR"噴出！！"HIW"疾向措手不及的$n！！\n"NOR,me,target);
        target->receive_damage("hp",dam,me);
        message_vision("造成$N" +dam+ "點的燒傷。\n",target); 
        }
    return;
}

