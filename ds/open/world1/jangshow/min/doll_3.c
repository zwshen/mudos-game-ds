// green stone called master

#include <ansi.h>
inherit NPC;
void create()
{
  set_name("透明人偶", ({"bright doll","doll","bright"}) );
  set("long",@LONG 
一種透明的不明生物，外型就跟人一樣。
LONG
);
  set("race", "human");
  set("unit","隻");
  set("age",300);
  set("level",50+random(8));  
  set("attitude", "aggressive"); 
  set("evil",2000);
  set("chat_chance", 13);
  set("chat_msg",({  
  (:random_move():),
  "透明人偶扭來扭去的.....好Ｑ喔∼\n",  
        }));
  setup();
  add_money("coin",1000+random(500));
} 
void init()
{       
        object ob;
        ::init();
        if( environment(this_player())->query("no_kill") ) return;
        if( environment(this_player())->query("no_fight") ) return;
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        //object me=this_player(); 
        object obj;
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIR"\n透明人偶說道：嘿嘿嘿嘿！\n"+NOR,ob);
                        tell_object(ob,HIW"一種黏液突然覆蓋\在你的身上！使得你無法動彈！\n"NOR); 
                        this_object()->kill_object(environment(ob)); 
                        ob->receive_damage("hp",300);  
                        ob->start_busy(2); 
                        obj=new(__DIR__"magma")->move(this_object()); 
                        obj=new(__DIR__"magma")->move(this_object());              
        }
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIW"\n$N吐了一口黏液在"+target->name()+"，造成腐蝕傷害！\n"NOR,me,target);  
     target->receive_damage("hp",400+random(350), this_object());
      return 1; 
    }
}  
void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
  ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision", 
    HIY"\n【傳奇】"+HIW"奇異的透明人偶被"+ob->name()+"("+ob->query("id")+")給殺掉了！\n"+NOR,users());
   ob->add("popularity",5);
  switch( random(100) )
  {
    case 0..40: write("哇∼∼什麼都沒有耶！\n");
          break;
    case 41..81: write("哇∼∼差一點點！加油！\n");
          break;
        case 82..99: new(__DIR__"sword")->move(this_object());
                  write(HIY"一把怪異的東西從透明人偶的屍體裡浮現出來..\n"NOR);
          break;
  }
  ::die();
  return;
}

