#include <ansi2.h>
inherit NPC;
inherit SSERVER;

void init();
void combat_ai();
void eat_corpse();
void npc_check();

void create()
{
 switch( random(5) )
 {
 case 0: set_name(HIC"西鬼"NOR, ({"nishiki"}) ); break;
 case 1: set_name(HIY"煌鬼"NOR, ({"kirameki"}) ); break;
 case 2: set_name(HIB"凍鬼"NOR, ({"touki"}) ); break;
 case 3: set_name(HIR"朱鬼"NOR, ({"shuki"}) ); break;
 case 4: set_name(CYN"斬鬼"NOR, ({"zanki"}) ); break;
 case 5: set_name(HIW"蠻鬼"NOR, ({"banki"}) ); break;
 }
  set("limbs", ({ "頭部", "身體","腹部","背部","手部" }) );
  set("verbs", ({ "bite", "claw"}) );
  set("race", "beast");
  set("unit","隻");
  set("age",random(50)+50);
  set("gender", "雄性" );
  set("level",45+random(3));
  set("title",RED"端午鬼怪"NOR);
  set("evil",-50);
  set("dodge",100+random(100)); 
  set("unarmed",100+random(100));
  set("parry",100+random(100)); 
  set("max_hp",8000+random(3000));
  set("addition/hit",random(30)); 
  set("addition/dodge",random(30)); 
  
  set("addition/bar",random(5)); 
  set("addition/wit",random(5));

  set("addition/str",random(30)); 
  set("addition/dex",random(30)); 
 
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
       (:combat_ai():),                     
     }));
  set_temp("_DRAGON_FESTIVAL_NPC_",1);
  setup();
  set_living_name("_DRAGON_FESTIVAL_GHOST_");  
}

void eat_corpse()
{
     object ob=this_object(), me=this_player(), *inv;
     int x, y;
     inv = all_inventory(environment(ob));
     y = sizeof(inv);
     for(x=0;x<y;x++){
        if( inv[x]->is_corpse() ){
            if( !inv[x] || !ob ) break;
            message_vision("$N大口大口的把$n吃了下去..\n", ob, inv[x]);
            destruct(inv[x]);
            this_object()->receive_heal("hp", random(500));         
        }      
     }
     return;
}     

void die()
{
  object ob, ob1=this_object();
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    destruct(ob1);
    return;
  }
          switch(random(6)){
          case 0: new(__DIR__"obj/item21")->move(environment(ob)); break;
          case 1: new(__DIR__"obj/item22")->move(environment(ob)); break;
          case 2: new(__DIR__"obj/item23")->move(environment(ob)); break;
          case 3: new(__DIR__"obj/item24")->move(environment(ob)); break;
          case 4: new(__DIR__"obj/item25")->move(environment(ob)); break;
          case 5: new(__DIR__"obj/item26")->move(environment(ob)); break;
          case 6: new(__DIR__"obj/ticket")->move(environment(ob)); break;
          }
//        ob->add("popularity",1);
//        tell_object(ob,HIG"因為你殺死了端午特別鬼怪，你得到了１點聲望\n"NOR);
  message_vision("$N抵擋不了$n強烈的攻勢，魂飛魄散了。\n",this_object(),ob);   
  destruct(this_object());
  return;
}

void init()
{
     ::init();
     npc_check();
     return;
}

void combat_ai()
{
     int w, x, y, z;
     object ob=this_object(), me=this_player();
     x = me->query_bar();
     y = ob->query_bar();
     z = x - y;
     if( z < 0 ) z = 1;
     if( ob->query("hp") < ob->query("max_hp")/3 )
         random_move();

     message_vision("吼吼吼~~\n",ob,me);
         for(w=0;w<z;w++){
         ob->add_temp("apply/bar",z);
         COMBAT_D->do_attack(me,ob,me->query_temp("weapon"),4);
         COMBAT_D->report_statue(ob);
         ob->add_temp("apply/bar",z);
         }
     return;    
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        int val;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                                damage/=4;
                                message_vision(HIY"$N咩咩咩咩咩咩咩\n" NOR,this_object());
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

void npc_check()
{
     object ob=this_object(), me=this_player(), *inv;
     int x, y;
     inv = all_inventory(environment(ob));
     y = sizeof(inv);
      
     for(x=0;x<y;x++){
     if( !inv[x] || !ob ) break;                     
     if( !userp(inv[x]) && inv[x]->is_character() ){
        if( !inv[x]->query("no_fight") && !inv[x]->query_temp("_DRAGON_FESTIVAL_NPC_") )
        {
         message_vision("$N把$n殺死了!!\n", ob, inv[x]);
         inv[x]->die();
         eat_corpse();
        }
     }
     }   
}
