#include <ansi.h>
#include <combat.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();
object master=this_object();

void create()
{
  set_name("柳生．星明" , ({ "yagyuu hoshiakari","hoshiakari","master" }) );
  set("long",@long
新陰流的師範，是一位刀術高手，徒手奪刀術達到出神入化的境界，
外表看起來氣宇軒昂、精光內斂，他正站在這裡指導弟子的刀術。
long
);
  create_family( HIC "新陰流" NOR ,2,"師範");
  set("level",47);
  set("race","人類");
  set("age",43);
  set("title",HIG"新陰流"NOR);
  set("adv_class",1);
  set("class1","新陰流");
  set("gender","男性");
  set("apeman_enemy",1);
  set("tengu_enemy",1);
  // 設定屬性分配表, 每一項的值在負9至正10之間
  // 而且四項的總和要剛好等於 20                  by shengsan
  //set("guild_gifts",({2,4,9,5}));
  set("str",110);
  set("con",126);
  set("int",53);
  set("dex",90);
  set_temp("apply/hit",60);
  set_temp("apply/dodge",60);
  //set("guild_skills",([
  //       "dodge" : ({120,3,70}),
  //       "parry" : ({130,2,60}),
  //       "sword" : ({130,3,70}),
  //       "godsword" : ({140,2,80}),
  //       "meditate" : ({120,3,80}),
  //       "mirage-steps" : ({140,3,80}),
  //       ])  );
  //set("guild_spells",([
  //       "god-fire" : ({130,3,90}),
  //       "god-benison":({170,2,50}),
  //       "summon_ghost" : ({130,3,90}),
  //         ]) );
  set_skill("shinin-ryuu-blade",100);
  //set_skill("parry_attack", 100);
  set_skill("blade", 100);
  set_skill("sword", 100);
  set_skill("parry", 100);
  set_skill("dodge",100);
  set_skill("unarmed",90);
  set_skill("monkey-dodge",100);
  map_skill("blade","shinin-ryuu-blade");
  map_skill("dodge","monkey-dodge");
  set("addition_damage",65);
  set("addition_armor",120);
//  set("no_check_class",1);
  set("talk_reply","你有什麼消息要告訴我嗎(say)？");
  set("inquiry/鬼人","就是秋川．旭，當年若不是他擊退天狗，也就沒有今天的村子了。\n");
  set("inquiry/日向．霧子","唉，當年一場誤會害死了她，我只能撫養朝霞長大來做為補償。\n");
  set("inquiry/天狗","天狗聚集櫻花林中，勢力強大，一直是村民的隱憂。\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  carry_object(__DIR__"eq/silver-waist")->wear();
  carry_object(__DIR__"eq/shouugan-katana")->wield();
  carry_object(__DIR__"eq/armor-design-page");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
}

void init()
{
  ::init();
  if( this_player()->query_temp("kill_cat") )  {
  remove_call_out("give_pill");
  call_out("give_pill",0,this_player());
  }
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu") ) this_object()->kill_ob(this_player());
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
}

void relay_say(object me, string str)
{
  object letter,ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if( strsrch(str,"主腦") != -1 )
  {
    command("say 你知道操縱山崽的主腦是誰？快告訴我！");
    me->set_temp("autarou_quest",1);
    return;
  }
  if( (strsrch(str,"貓妖") != -1) && (me->query_temp("autarou_quest") == 1) )
 {
    command("say 原來如此！你可願意替村民除了這個大害？");
    me->set_temp("autarou_quest",2);
    return;
  }
  if( (strsrch(str,"願意") != -1) && (me->query_temp("autarou_quest") == 2) )
  {
    if(ob->query_temp("autarou_ready"))
    {
      command("say 您真是俠義心腸！期待您為民除害。");
      me->delete_temp("autarou_quest");
    }
    else
    {
      command("say 您真是俠義心腸！我會通知我兒協助你討伐貓妖。");
      me->set_temp("go_with_autarou",1);
      me->delete_temp("autarou_quest");
      ob->set_temp("autarou_ready",1);
      call_out("delay_quest1",1200);
    }
    return;
  }
  if( (strsrch(str,"那件事") != -1) && (ob->query_temp("give_letter") == 0) )
 {
    command("say 轉眼已經快１０年啦，也該向朝霞說明清楚了。");
    command("say 說起來我難辭其疚，你願意幫我嗎？");
    me->set_temp("asaka_quest",1);
    return;
  }
  if( (strsrch(str,"願意") != -1) && (me->query_temp("asaka_quest") == 1) )
  {
    if(ob->query_temp("asaka_ready"))
    {
      command("say 嗯，我看還是再過幾天吧。");
      me->delete_temp("asaka_quest");
    }
    else
    {
      command("say 好，這封信就請你拿給朝霞吧。");
      letter=new_ob(__DIR__"eq/letter");
      letter->move(ob);
      command("give letter to "+ me->query("id") );
      ob->set_temp("asaka_ready",1);
      me->delete_temp("asaka_quest");
      call_out("delay_quest2",1200);
    }
    return;
  }
  return;
}

void normal_ai()
{
  object me,target,ob1,ob2,ob3,z;
  me = this_object();
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
  {
    command("eat pill");
  }
  switch( random(15) )
  {
     case  0: 
           message_vision("$N嘆口氣說道：唉∼這麼多年了，那件事還是揮之不去。\n",me);
           break;
     case  1:
           message_vision("$N自語道：鬼人的刀術真是令人難以想像，到底他是怎麼練成的呢？\n",me);
           break;
     case  2:
           message_vision("$N自語道：朝霞也長大了，也許\該將"HIW"那件事"NOR"作個了結．．\n",me);
           break;
     case  3:
           message_vision("$N尋思道：山崽的行動似乎經過策畫，但是"HIW"主腦"NOR"是誰呢？\n",me);
           break;
     case  4:
           message_vision("$N自語道：山崽的行動似乎經過策畫，但是"HIW"主腦"NOR"是誰呢？\n",me);
           break;
  }
  return;
}

void combat_ai()
{
  object me,target,z;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
  {
    command("eat pill");
  }
  if(!random(4))
  {
    message_vision(HIR"$N大叫一聲，全身凝聚氣力。\n"NOR, this_object() );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<30)
  {
    damage=0;
    message_vision(HIW"\n$N身形幻化為數個幻影，閃開了攻擊。\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void delay_quest1()
{
  this_object()->delete_temp("autarou_ready");
}

void delay_quest2()
{
  this_object()->delete_temp("asaka_ready");
}
void give_pill(object ob)
{
  int i;
  message_vision("\n柳生．星明對著$N說道：您真是大英雄，我這裡有些傷藥給你補身。\n" NOR,ob);
  for(i=0;i<6;i++)
  {
    new(__DIR__"eq/genki-pill")->move(this_object());
    command("give pill to "+ ob->query("id") );
  }
  ob->delete_temp("kill_cat");
  return;
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
  message("world:world1:vision",
  HIC"\n\t【東方島】："+HIG" 新陰流的師範 "HIW"柳生．星明 敗在"HIY+ob->name(1)+HIW"之手，引起一陣騷動。\n\n"+NOR
    ,users());
  ob->add("popularity",3);      
  tell_object(ob,HIG"你得到 3 點聲望。"NOR);
  ::die();
  return;
}


