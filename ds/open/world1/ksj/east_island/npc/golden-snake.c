#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"赤眼"HIY"金鱗"NOR,({"golden snake","snake"}) );
        set("long",@LONG
一條碩大的毒蛇，長度足足七尺有餘，血紅色的眼睛，金黃色的
蛇鱗，兇猛敏捷而且毒性很強，經常掠食牲畜。
LONG);
        set("race", "野獸");    
        set("unit","條");
        set("age",8);
        set("level",23);
        set("attitude", "aggressive");  
        set("limbs", ({ "頭部", "身體","尾巴"}) ); 
        set("verbs", ({ "bite" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        HIR"赤眼"HIY"金鱗"NOR"紅色的雙眼直盯著你，好像隨時要撲過來似的。\n",
        }));                                
        setup();
        add_money("coin",500);
}

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(userp(this_player()) )
      this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
 {
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
    message_vision("$N如一條金光，迅速地咬向$n\n", this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(1)+1));
    target->receive_damage("hp",random(50)+30,target);
    target->apply_condition("blooding", target->query_condition("blooding")+random(2));
    return 1;
  }
  return 0;
 }

void die()
 {
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->add("popularity",1);
        tell_object(ob,HIG"你得到 1 點聲望。"NOR);      
        switch( random(99) ) {
case  0..4: new(__DIR__"eq/golden-snake-waist")->move(this_object()); //debug-js@ds
        break;}
        ::die();
        return;
 }
