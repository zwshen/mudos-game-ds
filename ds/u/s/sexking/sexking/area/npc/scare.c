#include <ansi.h>
inherit NPC;
void create()
{
        set_name("稻草人", ({ "scarecrow" ,"scarecrow"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "它是用稻草做的人。\n");
        set("level",3);
        set("mobhp",50);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        setup();
}
void heart_beat()
{
  object obj,corpse;
  obj=this_object();
  if( obj->query("mobhp") < 0 )
  {
   corpse=new(__DIR__"ccopper");
    message_vision("\n稻草人突然「碰」的一聲應聲碎掉了。\n",obj); 
     this_player()->remove_all_killer();
corpse->move(environment(this_object()));
    destruct(this_object());
    //::die();
  } else obj->add_block(2);

  return; 
}

int receive_damage(string type,int damage,object who)
{
  int j,mobhp;
  object obj;
  obj=this_object();
  j=random(15)+1;
  who->add("exp", j);
  tell_object(who,"\n你得到了"+j+"點的經驗值。\n");
  mobhp=obj->query("mobhp");
  obj->set("mobhp",mobhp-1);  
  if(who->query("ap")>0)
  {
    who->receive_damage("ap",3);
  }
  else {
who->receive_damage("hp",10);
  }
}

