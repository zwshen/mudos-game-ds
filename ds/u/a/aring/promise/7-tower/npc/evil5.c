#include <ansi.h>
#include <combat.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N揮著剛猛的"HIY"巨斧"NOR"狠狠的往的$n身體砍去！",
                "attact_type":  "bar",
                "damage_type":  "砍傷",
        ]),
        ([  "action":       "$n眼前一黑，被穿著"HIW+BLK"鐵甲"NOR"的$N狠狠撞了一下，當場暈眩！",
                "attact_type":  "tec",
                "damage_type":  "撞傷",
        ]),
        
});
void do_clean(); 
void summon();
void create()
{
  set_name(WHT"子兒"NOR, ({"zi er","er"}) );
  set("long",@LONG
名字看似柔弱，其實不然，此人體型剛猛無比，手中的斧其重無比
，身穿的護身盔甲也十分笨重。
LONG
);
  set("gender", "男生");  
  set("race", "人類");
  set("age",42);
  set("level",51);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIG"芞妖俠"NOR); 
  set("Merits/bar",10);
  set("Merits/bio",10);
  set("Merits/wit",3);
  set("Merits/tec",3);
  add("addition_damage",210);
  add("addition_armor",100);
  set("max_hp",11100);  
  set("chat_chance_combat",3);
  set("chat_msg_combat",({ 
      (: summon :), 
})); 

  setup(); 
  set("actions", (: call_other, __FILE__, "query_action" :));
  //carry_object(__DIR__"eq/eq5")->wear();
  //carry_object(__DIR__"wp/wp5")->wield();
 }
 mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
}
  
void summon()
{
     object me=this_player(),a,b;
     if(this_object()->is_busy()) return;
     else{ message_vision(HIW"\n子兒雙手放置胸前，靜靜的唸著咒文，頃刻間此地出現 "HIG"2 "HIW"個"NOR"子兒"HIW"的替身來助陣！！\n\n"NOR,me);
           a=new(__DIR__"shadow");
           b=new(__DIR__"shadow2");

          a->move(environment(me));
           b->move(environment(me));
           a->kill_object(me);
           b->kill_object(me);
         }
      return;
 }
void die()
{
  object ob,env;
   int temp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  env = environment(ob);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision", "\n\t"HIW"就在" +NATURE_D->game_time(temp)+"       
  "NOR+CYN"\n\n\t七邪塔傳來哀號....縱橫七邪塔第五層 "WHT"子兒 "HIW"敗在"HIY+ob->query("name")+HIW"手上\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"消滅了妖邪，佛祖大開法恩賞賜你五點聲望以此嘉獎。"NOR);
    switch( random(50) )

  {
    case  0..25: new(__DIR__"obj/book")->move(ob);
          break;
    case  26..50: new(__DIR__"obj/fakebook")->move(this_object());

          break;
    }
  
   ::die();
  return;
}



