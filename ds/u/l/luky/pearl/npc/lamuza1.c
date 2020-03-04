// ovelia.c
#include <ansi.h>

inherit NPC;
object gf;
int do_move(string dir);
int is_enemy(object player);

void create()
{
set_name("[1;37m©Ô¿p¥¾[m",({"lamuza","boss"}));
set("long",
"\n  ©Ô¿p¥¾­ì¬°¥ìªk¨½´µ¤ý°êªº¶Q±Ú¡C¥Ñ©ó¥ìªk¨½´µ©M¶ø¹F§Q¨È¤ý°êªø´Áªº\n"
"¯Éª§¡A¤Þµo¤FµÛ¦Wªº¤­¦~¾Ôª§¡C·í®É©Ô¿p¥¾«K¶i¤J¤F¥_¤ÑÃM¤h¹Î¤h©x¾Ç°|\n"
"¨ü°V¡A¦ý¥Ñ©ó¦P¤÷²§¥Àªº­ô­ô©Ôº¸¤Ú¥jªº³´®`¡A¨Ï±o¥L³Q­°¯Å¦¨¬°¶Ä§L¡A\n"
"¤]¦]¦¹¦Ó¦b¤@¦¸ªº§@¾Ô¤¤ÁÛ«¯¤F¶øÁ¨ÄR¶®¤½¥D¡C\n"
);
set("title","°h¥ð«iªÌ");
set("level",65);
set("age",38);
set("gander","¨k©Ê");
set("class","wufo");
set_skill("force",1100);
set_skill("rapid",200);
set_skill("stab",160);
set_skill("defend",800);
set("setforce","basic");
add_temp("apply/armor",random(250));
add_temp("apply/damage",random(250));
//set("max_mp",700000);
set("coin",random(2400)+1000);
set("chat_chance_combat",5);
set("chat_msg_combat",({
  (:command,"angry":),
  (:command,"rapid":),
}));
set("inquiry/name", @LONG
  §Úªº¦W¦r¥s©Ô¿p¥¾, ¬O³o¸Ìªº¦ÑÁó.
LONG );
set("inquiry/ovelia", @LONG
  ¶øÁ¨ÄR¶®? µ¥§Ú¬°§Ú¤÷¿Ë³ø¤³¤§«á§Ú·|¦V¦o¨D±Bªº. 
LONG );
set("inquiry/service", @LONG
  ¼Ó¤W´N¬O«È©Ð, ½Ð¤W¼Ó¥ð®§§a.
LONG );

set_temp("exforce",1);
set_heart_beat(1);
setup();
//add_money("coin",random(1000));
carry_object(__DIR__"eq/greenarmor")->wear();
carry_object(__DIR__"eq/greenarms")->wear();
//carry_object(__DIR__"eq/greenleg")->wear();
carry_object(__DIR__"eq/greenbelt")->wear();
carry_object(__DIR__"eq/greenboots")->wear();
carry_object(__DIR__"eq/greenhelm")->wear();
carry_object(__DIR__"eq/greenshield")->wear();
carry_object(__DIR__"wp/greensword")->wield();
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
}
void init()
{
 gf=find_living("ovelia");
 set_heart_beat(1);
 if( !gf && this_player()->query_temp("ovelia")==1)
 {
  write("©Ô¿p¥¾¤j¥s: ¥i´cªº³Ã¥ë~~ ©~µM±þ¤F§Ú³ßÅwªº¤H~~¯Ç©R¨Ó!!!\n");
  kill_ob(this_player());
 }
  add_action("do_move","go");
  is_enemy(this_player());
}

void east()
{
command("go east");
}

void west()
{
command("go west");
}

int do_move(string dir)
{
 object temp,player;
 player=this_player();
 call_out(dir,2);
/* if(player==query_temp("last_damage_from"))
 {
  if(temp=present(player->query("id"),environment(this_object()))) 
  {
   command("say «¢«¢.."+player->query("name")+"§A¶]¤£±¼¤F!!");
   return 0;
  } else
  command("go "+dir);
  return 0;
 }*/
 return 0;
}

void heart_beat()
{
 object me,opp,temp,opp1;
 string oppid;
 int gfhp;
 me = this_player();
// gf=find_living("ovelia");
// if(!gf) tell_room(environment(this_object()),"¨S§ä¨ì.. (1)\n");
 if(gf)
 {
  opp1=gf->query_temp("last_damage_from");
  if(opp1) opp1->set_temp("lamuza_k",1);
  gfhp=gf->query("hp");
  if(gfhp<20000 && !present("ovelia",environment(this_object())))
  {
   tell_room(environment(this_object()),"\n©Ô¿p¥¾»°¥h±Ï¶øÁ¨ÄR¶®¤F..\n",);
   this_object()->move(environment(gf));
   tell_room(environment(this_object()),"\n©Ô¿p¥¾«Ü¥Í®ðªº½Ä¤F¶i¨Ó!!\n\n",);
   if(opp1)
   if(opp1->query("hp")>1) kill_ob(opp1);
   set("chat_chance", 30);
   set("chat_msg", ({
   (:random_move:),
   }) );

  }

  if(opp1)
  if(gf->is_fighting() && opp1->query_temp("lamuza_k")!=1)
  {
   if(opp1->query("hp")>1) kill_ob(opp1);
  }
 }
 opp=query_temp("last_damage_from");
 if(!opp) opp=opp1;
 if(!opp) return;
 if(opp->query("hp")<1) return;
if( this_object()->is_fighting() )
{
 if ( !query_temp("body") && (random(5)>2))
 {
  command("exert body");
 } else
 if ( !query_temp("enforce") && (random(5)>3))
 {
  command("spank");
  command("exert force");
 } else
 if ( (random(7)>5))
 {
  command("hmm");
  command("say ¼K¼K...§Aªº¯}ºì´N¬O³o¸Ì!!");
  command("stab");
 }
}
 if ( query("hp")<30000 && (random(5)>2))
 {
  command("drink potion");
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
ob = this_player(1);
ob->delete_temp("ovelia");
a=environment(ob);
a->delete("objects");
if( !ob ) return;
shout(HIG"\n\n «¢«¢«¢...¦n­Ó"+ob->query("name")+"!!! "
+HIG"©~µM¯à°÷¥´±Ñ§Ú©Ô¿p¥¾...\n\n"
"                 ­Y¯à±N³o¤O¶q¥Î¦b¥¿³~, §Aªº«e³~±N¤£¥i­­¶q!!\n\n"NOR);
   ::die();
destruct(this_object());
}

int is_enemy(object player)
{
 object *enemy; 
 int i;
 enemy = query_enemy();
 if(player==query_temp("last_damage_from"))
 message_vision("¬O¼Ä¤H\n",player);
 if(present(player->query("id"),environment(this_object())))
  message_vision("§ä¨ì§A¤F\n",player);
/* for(i=0; i<sizeof(enemy); i++)
 {
  if(player==enemy[i])
  {
   message_vision("¬O¼Ä¤H\n",player);
   return 1;
  }
 }
 message_vision("¤£¬O¼Ä¤H\n",player);
*/
 return 1;
}