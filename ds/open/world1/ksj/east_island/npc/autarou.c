#include <ansi.h>
#include <combat.h>
#include <path.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("柳生．奧太郎" , ({ "yagyuu autarou","autarou" }) );
  set("long",@long
柳生．星明的獨子，目前擔任村莊防衛的指揮，生性沉穩，新陰流刀
術相當熟練，志願是離開小島到大陸去遊歷。
long
);
  create_family( HIC "新陰流" NOR ,2,"弟子");
  set("level",40);
  set("race","人類");
  set("age",21);
  set("title",HIG"新陰流"NOR);
  set("class1","新陰流");
  set("gender","男性");
  set("apeman-enemy",1);
  set("tengu-enemy",1);
  set("str",100);
  set("con",100);
  set("int",40);
  set("dex",56);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  set_skill("blade", 80);
  set_skill("sword", 80);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("unarmed",70);
  set_skill("shinin-ryuu-blade",70);
  set_skill("monkey-dodge",70);
  set("addition_damage",35);
  set("addition_armor",90);
  set("talk_reply","您好，您是外地來的吧，北邊就是鬼之森了，可別冒險進入阿。");
  set("inquiry/山崽","聽說有個虛無僧在暗地探訪鬼之森，也許\他知道山崽是誰操控的。\n");
  set("inquiry/鬼之森","鬼之森裡經常有山崽成群出沒，已經有不少人死在森林中了。\n");
  set("inquiry/鬼人","聽說以前是他擊退天狗，不知道他是否仍在世。\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  map_skill("dodge","monkey-dodge");
  map_skill("blade","shinin-ryuu-blade");
  carry_object(__DIR__"eq/observe-necklace")->wear();
  carry_object(__DIR__"eq/silver-gloves")->wear();
  carry_object(__DIR__"eq/bizen-chousen-katana")->wield();
  carry_object(__DIR__"eq/boots-design-page");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/silver-shield")->wear();
}

void init()
{
  ::init();
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query_temp("go_with_autarou")) call_out("do_follow",0,this_player());
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
  if( this_player()->query("tengu") ) this_object()->kill_ob(this_player());
/*
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(已有防備)"NOR"柳生．奧太郎料敵機先，數道刀光快速襲向$N！！\n"NOR,this_player() );
    this_player()->add_busy(random(1)+1);
    this_player()->receive_damage("hp",random(50)+50,this_object());
  }
*/
}

void normal_ai()
{
  object me,target,ob1,ob2,ob3,leader,env,env2,z;
  me = this_object();
  leader=me->query_leader();
	if( !leader ) return; // alick
  env=environment(leader);
  env2=environment(me);

  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
    command("wield katana");
  if( !me->query_skill_mapped("blade") )
    command("exert shinin-ryuu-blade");
  if( !me->query_skill_mapped("dodge") )
    command("exert monkey-dodge");       
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
  if( env2->query("king-room") ) call_out("speaking",0);
  if( (leader) && (env != environment(me)) && !random(10))  me->set_leader(0);
  switch( random(20) )
  {
     case  0: 
           message_vision("$N說道：真希望快點消滅鬼之森的山崽，我就可以出發到大陸了。\n",me);
           break;
     case  1:
           message_vision("$N說道：最近山崽都沒什麼大動作，真是奇怪。\n",me);
           break;
     case  2:
           message_vision("$N說道：聽說有外來人進入到鬼之森修練武藝，希望他們別遇到山崽群。\n",me);
           break;
     case  3:
           message_vision("$N說道：到大陸去一定能見識更多的武學技藝。\n",me);
           break;
     case  4:
           message_vision("$N說道：聽村民說河對岸的櫻花林裡住著一位刀術超絕的\n"
            +"鬼人，可是向父親大人提起總是不講，聽說朝霞是父親大人從鬼人手\n"
            +"中救出的，不知道該不該問她。\n",me);
           break;
     case  5: 
           message_vision("$N說道：父親老是說要等到查出山崽的操縱者，再進攻鬼之森。\n",me);
           break;
     case  6: 
           message_vision("$N說道：上回到西方大陸買了不錯的盾牌，對付山崽又多了分勝算。\n",me);
           break;
  }
  return;
}

void speaking()
{
  command("hmm");
  command("say 看來貓妖就在這上面了，由我先上去探探。");
  this_object()->move(__DIR__"../room57.c");
  return;
}

void combat_ai()
{
  object me,target,z,s;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
    command("wield katana");
  if(!objectp(s=present("silver shield",me)) && me->query("leader") )
  {
    new(__DIR__"eq/silver-shield")->move(me);
    command("wear shield");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
  if(!random(10))
    command("exert shinin-ryuu-blade");
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<20)
  {
    damage/=3;
    message_vision(HIW"\n$N身形幻化為兩個幻影，險險避開了直接攻擊。\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

int do_follow(object me)
{
  message_vision(HIY"\n$N向奧太郎訴說事情的原委。\n" NOR,this_player());
  command("say 既是如此，就讓我與你同行吧。");
  this_object()->set_leader(me);
//  command("follow "+me->query("id"));
  me->delete_temp("go_with_autarou");
  call_out("no_follow",300);
  return 1;
}

int no_follow()
{
  command("say 怎麼還不見貓妖，算了我自己找吧。");
  this_object()->set_leader(0);
  return 1;
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
  ob->add("popularity",2);      
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);
  ::die();
  return;
}
