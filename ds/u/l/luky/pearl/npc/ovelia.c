// ovelia.c
#include <ansi.h>
#include <path.h>
inherit NPC;
object bf;
void create()
{
set_name("[1;33m¶øÁ¨ÄR¶®[0m",({"ovelia","princess"}));
set("gander","¤k©Ê");
set("long","¤@¦ì´¿¸g¶Q¬°¤½¥Dªº¬üÄR¤k­¦¡A¦b¤@¦¸¸j¬[¨Æ¥ó¬°©Ô¿p¥¾©Ò±Ï¡C\n"
+"·í©Ô¿p¥¾¨M©w¨Ó¨ì¦¹³BÁô©~®É¡A«K¤]·È¥X¬Ó®c³­¥L¤@°_¨Ó¦¹©w©~¡C\n"
);
set("level",52);
set("age",22);
set("class","caster");
set("evil",-300);
set("max_mp",700000);
set("coin",random(2000));
//set_skill("unarmed",50);
//set_skill("sixfinger",26);
//map_skill("unarmed","sixfinger");
set_skill("arrow",2000); // ­n¥Îmulti_arrow ¤@©w­n¥ý³] arrow 
set_skill("multi_arrow",400);
set_skill("arr",2000);
set_skill("mostlight",800);
set_skill("armor",900);
set_skill("aid",2400);
set_temp("apply/armor",80+random(160));
set_temp("apply/damage",80+random(160));
set("env/spellpower",5);
set("chat_chance_combat",40);
set("chat_msg_combat",({
(: cast_spell2, "arr":),
(: cast_spell2, "multi_arrow":),
(: cast_spell2, "mostlight":),
(: cast_spell2, "aid":),
})); 
set_heart_beat(1);
setup();
carry_object(__DIR__"eq/shield1")->wear();
carry_object(__DIR__"eq/greenglove")->wear();
carry_object(__DIR__"eq/greencloak")->wear();
carry_object(__DIR__"eq/greenwaist")->wear();
carry_object(__DIR__"eq/greensurcoat")->wear();
carry_object(__DIR__"eq/greenneck")->wear();
carry_object(__DIR__"eq/greenring")->wear();
carry_object(__DIR__"eq/greencloth")->wear();
carry_object(__DIR__"wp/greendagger")->wield();
}

void init()
{
if(this_player()->query_temp("ovelia")==1)
  this_player()->delete_temp("ovelia");
}

void heart_beat()
{
 object me,opp;
 string oppid;
 me = this_player();
 opp=query_temp("last_damage_from");
 if(opp)
 { 
  oppid=opp->query("id");
  if( this_object()->is_fighting() )
  {
  if(random(10)>7) 
   {
    command("sigh");
    command("c multi_arrow "+oppid);
//    command("c arr "+oppid);
//    command("c mostlight");
//    command("c arrow "+oppid);
//    command("say §Ú·Q¹ï"+oppid+"¬I¦h­«Å]½b³N.. ¥i¬O¬I¤£¥X¨Ó..sigh");
   }
  }
  if ( !query_temp("sarmor") && (random(5)>2))
  {
   command("c armor");
  }
 }
 if ( (query("hp")<30000) && (random(5)>2))
 {
  command("c aid");
 }
 if( query("hp")<25000 && query_temp("callbf")==0 )
 {
  bf=find_living("lamuza");
  if(bf)
  {
   if(environment(bf))
   {
    shout("\n\n[1;37m ©Ô¿p¥¾·PÄ±¨ì¶øÁ¨ÄR¶®ªº®ð¥¿¦b¤£Â_¦a´î®z.. ¥i´c!! ¬O­þ­ÓÃa³J!??[m\n\n"); 
    tell_room(environment(bf),"\n©Ô¿p¥¾¨M©w»°¥h±Ï¶øÁ¨ÄR¶®¤F..\n©Ô¿p¥¾©¹¥_Â÷¶}¡C\n",);
    bf->move(environment(this_object()));
    tell_room(environment(this_object()),"\n©Ô¿p¥¾«Ü¥Í®ðªº½Ä¤F¶i¨Ó!!\n\n",);
    bf->kill_ob(query_temp("last_damage_from"));
    set_temp("callbf",1);
   }
  }
 }
 ::heart_beat();
 if(!me) return;
 if (me->query("hp") < 0)
 me->die();
}

void die()
{
object ob;
object a;
if( !ob = query_temp("last_damage_from") )
ob = this_player();
if( !ob ) return;
ob->set_temp("ovelia",1);
ob->delete_temp("lamuza_k");
a=environment(ob);
a->delete("objects");
shout(HIR"§Ú¿Ë·Rªº"+ob->query("name")+"°Ú¡ã¡ã¡ã\n\n"
+"§A¤w¸g½ñ¤W¤F¤¿ÀIµL¤ñªº­×Ã¹¤§¹D¤F... §Æ±æ§Ú¶øÁ¨ÄR¶®ªºÂA¦å¯à°÷³ê¿ô§Aªº¨}ª¾!!\n\n"NOR);
   ::die();
destruct(this_object());
}