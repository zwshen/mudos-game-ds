#include <ansi.h>
inherit NPC;
void create()
{
        set_name("木人", ({ "wood's man" ,"man"}) );
        set("race", "robot");
        set("age", 1);
        set("long", "它是木頭做的假人，雕塑的栩栩如生，跟真的一樣。\n");
        set("level",5);
        set("mobhp",15);
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
    corpse=new(__DIR__"corpse");
    message_vision("\n突然木人發出一陣『喀∼啦∼』數聲，木人已經毀壞了。\n",obj); 
    corpse->move(environment(this_object()));
    destruct(this_object());
    //::die();
  }  

  obj->add_block(2);
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
 who->receive_damage("ap",6);
}
