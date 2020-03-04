// 2006.6.7 修改  by Jangshow// 增加機率性掉 EQ
// 2006/12/92 修改  by Tmr 提高心防
// npc/eq/dragon-boots.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM "點液" NOR,({"dab aqua dragon","dragon"}) );
      set("title",HIM "狡龍" NOR);
        set("long",@LONG
「狡龍  點液」為一太古生物，性喜花香，居於江、湖之中，通長二
十四尺，身略作淡紅色，瞧其兩目如炬，渾身散有淡淡不知名香味。
LONG    
        );
        set("race", "野獸");    
        set("unit","隻");
        set("age",300);
        set("level",40);
        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","龍尾","背鱗", "眼睛" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_armor",90);
        add("addition_shield",120);
        add("addition_damage",80);
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
        if( random(100) > 95) 
        carry_object(__DIR__"eq/dab-aqua-boots")->wear();
        carry_object(__DIR__"wp/dab-aqua-claw")->wield();
        carry_object(__DIR__"eq/dab-aqua-armor")->wear();
}
void die()
{
         object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }  

        message("world:world1:vision",
   HIG"\n【武林消息】"+HIW "太古生物「狡龍  點液」死在"+ob->name(1)+"的手中。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
       message_vision( "$N"+HIR "臨死前，狂吐了幾大口鮮血...." NOR ,this_object() );
      obj=new(__DIR__"obj/dragon-blood");
      obj->move(environment(this_object() ) );
      obj=new(__DIR__"obj/dragon-blood");
      obj->move(environment(this_object() ) ); 
/*
       if( random(100) > 95) {
                d=new(__DIR__"eq/dragon-boots");
                d->move(environment(this_object()));   
                message_vision("$N"+NOR"的身上掉下了一雙具足"NOR,this_object()); 
        }
*/
        ::die();
        return;
}

