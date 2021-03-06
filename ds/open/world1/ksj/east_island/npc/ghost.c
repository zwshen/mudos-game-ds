#include <ansi.h>
inherit NPC;

void create()
{
        set_name("邪鬼",({"ghost"}) );
        set("long",@LONG
一隻體形壯碩，齜牙裂嘴的惡鬼，長久以來被封印於石像之下。
LONG);
        set("race", "野獸");    
        set("unit","隻");
        set("age",150);
        set("level",35);
        set("attitude", "aggressive");  
        set("limbs", ({ "頭部", "身體","手部","腳部"}) ); 
        set("verbs", ({ "bite","claw" }) );     
        setup();
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
    case  0..1: new(__DIR__"eq/ghost-necklace")->move(this_object());
    break;}
   ::die();
   return;
 }
