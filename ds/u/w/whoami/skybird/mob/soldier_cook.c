#include <ansi.h>
inherit NPC;
void uncovered();

void create()
{
        set_name("軍中主廚",({"soldier's cook","cook"}) );
        set("long","\n");
        set("age",40);
        set("race","人類");
        set("level",25);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("class","thief");
        set_skill("unarmed",80); 
        set_skill("dodge",80);
        set_skill("parry",80); 
        set_skill("dagger",80);
        set_skill("aerial-dagger", 100);
        set_skill("money-dart", 100);
        set_skill("reachcloud-steps", 100);
        map_skill("unarmed","money-dart");
        map_skill("dodge","reachcloud-steps");
        map_skill("dagger","aerial-dagger");
        set("no_fight",1);
        set_temp("soldier",1);
        setup();
        add_money("coin", 1000);
        carry_object("/open/world1/wilfred/sand/npc/wp/wp7");
}
void init()
{ 
  object me=this_player(),ob=this_object(),obj,env;
  env = environment(ob);
  ::init();
  if( env->query("Ten-mount_soldier") ){
      command("say 被發現了..快逃..");
      command("south");
      destruct(ob);
      return;
  }  
  if( !me->query_temp("kill_cook") ) return;
  command("say 可惡..你這多嘴的傢伙..");
  command("wield dagger");
  ob->set("no_fight",0);
  ob->kill_ob(me);
  me->kill_ob(ob); 
  ob->set_temp("apply/armor",150);
  ob->set_temp("apply/dodge",50);
  return;
}
 
int accept_object(object who, object ob)
{ 
  object obj;
  if( ob->query("id") == "secret bottle" && who->query_temp("can_give_bottle") )
  { 
    who->delete_temp("can_give_bottle"); 
    who->add_temp("ask_general",1);
    message_vision(YEL"$N驚慌的說道：這..這東西不是我的呀..\n"NOR,this_object()); 
    obj=new(__DIR__"obj/bottle");
    obj->move(who);
    tell_object(who,"軍中主廚似乎對"+ob->query("name")+"並不感興趣。\n");
    return 1;
  }  
  command("say 給我這作啥?");
  tell_object(who,this_object()->name(1)+"似乎對"+ob->name(1)+"並不感興趣•\n");
  return notify_fail("");
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"白色粉末") != -1 && me->query_temp("bottle_checked") && ob->query_temp("uncovered"))
  {
      command("?");
      command("dunno "+me->query("id") );
      me->delete_temp("bottle_checked");
      me->add_temp("can_give_bottle",1);
  } else {
      command("?");
  }
  return;
}

int talk_action()
{
  object me=this_player(),ob=this_object(),obj;
  if( me->is_fighting() || ob->is_fighting() || me->is_busy() || ob->is_busy() 
   || ob->query_temp("uncovered") || ob->query_temp("ready_poison") ) return 0;
  if( me->query_int() > ob->query_int() ){
      message_vision(HIC"似乎有什麼東西從$N身上掉下來了……\n"NOR,ob); 
      ob->add_temp("uncovered",1);
      obj=new(__DIR__"obj/bottle");
      obj->move(environment(ob));
  } else {
      ob->add_temp("ready_poison",1);
      call_out("ready_poison",0,ob);
  } 
  command("say 快滾！這可不是像你這種外行人能來的地方！！");
  return 1;
}

void ready_poison()
{
  object me=this_player(),ob=this_object(),*target,env;
  int x;
  target = all_inventory(environment(ob));
 
  switch( ob->query_temp("ready_poison") ){
         case 1:
            for(x=0;x<sizeof(target);x++){
               if( target[x] -> query_temp("soldier") ) continue;
               if( !living(target[x]))continue; 
               message_vision(YEL"$N揮了揮手，突然兩個壯漢就從$n身後走了出來，$n馬上就被拖到外頭去了•\n"NOR,ob,target[x]);               
               target[x]->move(__DIR__"../camp019"); 
               env = environment(target[x]);
               env->add_temp("cannot_north",1);
               env->del_temp();

            } 
            ob->add_temp("ready_poison",1);
            call_out("ready_poison",6,ob);
         break;
         case 2:
            command("hehe");
            command("say 那個笨蛋終於走了..好險沒被發現..");
            command("lick");
            ob->delete_temp("ready_poison");
            call_out("poison",1);
         break;                     
  }
  return;
}

void poison()
{
   object me=this_player(),ob=this_object(),target,tar; 
   int x;
   for(x=0;x<15;x++){
   target = find_living("Ten_Mount_Soldier");
   if( !target || !objectp(target) || !environment(target) ) continue;
   target->set_temp("temp/death_type","["HIR"毒發身亡"NOR"]"); 
   target->die();
   }

   message("world:world1:vision",
CYN"\n\t十萬大山山腰上的"HIY"討伐軍軍營"CYN"中傳來陣陣慘呼，淡淡的"HIG"綠霧"CYN"在軍營上空聚而不散，不久後山頭便一片寂靜...\n"NOR
HIR"\n\n\t【東北戰報】"CYN"討伐軍駐地遭受不明毒氣侵襲，將士死傷慘重•\n\t"NOR
        ,users() );

   command("say 任務完成, 快離開這是非之地吧..");
   command("south");
   destruct(ob);
   return;   
} 
 
void die()
{
        object ob,env,npc;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        env=environment(this_object());
        if(!objectp(npc=find_living("Ten-mount_soldier") ) && env->query("Ten-mount_soldier")==1 )
           env->delete("Ten-mount_soldier");
        if( env && env->query("Ten-mount_soldier")!=1 )
        {
          env->start_war(1);
          env->set("Ten-mount_soldier",1);
        }
        ob->add("popularity",1);  
        ob->delete_temp("kill_cook");

        tell_object(ob,HIW"\n(因為你殺死了"+this_object()->query("name")+HIW"，所以得到了 1 點聲望。)\n"NOR); 
        ::die();
        return;
}


