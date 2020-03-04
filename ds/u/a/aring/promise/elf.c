#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("备腳弘", ({ "dig-treasure earth_elf","elf" }) );
  set("race", "beast" );
  set("gender", "动┦" );
  set("limbs", ({ "ō砰","も场","竲场","繷场" }) );
  set("verbs", ({ "bite","claw" }) );
  set("age", "???");
  set("long","ō阀へ厚︹窯羪骸琌のō︾璵瘆瘆年年\n"                   "琌ō玱璉独︹ガぃ笵杆ㄇぐ或狥﹁\n");
  set("level",1); 
  set("no_kill",1);     
  set("attitude", "friendly");
  set("sell_list",([
       __DIR__"obj/shield" : 50, 
       __DIR__"obj/ten-sword": 50,
       __DIR__"obj/scroll":50,       
       __DIR__"obj/lbg":50,
     ]) );

  setup();
}
void init()
{        
  object ob,el;
  el = this_object();  
  ::init();   
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 10+random(30), ob); //1->10+random(30)  by ksj
  }   
  add_action("do_buy","buy");
  add_action("do_list","list");  
}

