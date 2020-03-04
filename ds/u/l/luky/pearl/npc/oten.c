#include <ansi.h>
inherit NPC;
void create()
{
set_name("[1;30m¼Ú©Z[m",({"swordsoul oten","oten"}));
set("title","[1;34m¼C»î[m");
set("level",65);
set("age",500);
set("war",1);
set("evil",200+random(200));
set("long","§A¬Ý¨ì¤@¨ã¶Â¦âªºñZ¥ÒÃM¦b¤@¤ÇÂ@°¨¤W¡Aµ·²@¨S¦³¥Í©Rªº¸ñ¶H¡C\n\n");
set("chat_chance",10);
set("attitude", "aggressive");
set("chat_msg",({
(:command,"say":) ,
"¼C»î ¼Ú©Zµo¥X¤@°}°}§C¨Iªº©D§u.....¶ã..°Ú°Ú°Ú........\n",
}) );
add_temp("apply/armor",700);
add_temp("apply/damage",500);
        setup();
        set_heart_beat(1);
}
void heart_beat()
{
 object *enemy,me,ob,ot,eme;
 int damage,damage2;
 int i;
 me = this_object();
 if(me)
 if( me->is_fighting() )
 {
  enemy = me->query_enemy();
  if(!enemy) return;
//  i=random(sizeof(enemy));
  if(sizeof(enemy)==0) return;
//  eme=present(enemy[random(sizeof(enemy))]->query("id"),environment(me));
  eme=query_temp("last_damage_from");
  if(!eme) return;
  if(! present(eme->query("id"), environment(me) ) ) return ;
  if(random(540-eme->query("lck"))>400 || random(18)<2)
  {
   damage=200+random(400);
   damage2=enemy[i]->query("hp")/5;
   if(eme->query_temp("slash")<1)
   {
   message_vision(HIR"\n\n ¡@ µ¹..µ¹§Ú¡ã¡ã¡ã¦å¡ã°Ú¡ã¡ã«¢¡ã«¢¡ã¡ã«¢¡ã¡ã«¢¡ã¡ã¡ã\n",me);
   message_vision(@DIE
                       ______
                    .-"      "-.
                   /            \
       _          |              |          _
      ( \         |,  .-.  .-.  ,|         / )
       > "=._     | )(__/  \__)( |     _.=" <
      (_/"=._"=._ \/     /\     \/ _.="_.="\_)
             "=._"(_     ^^     _)"_.="
                 "=\__|IIIIII|__/="
                _.="| \IIIIII/ |"=._
      _     _.="_.="\          /"=._"=._     _
     ( \_.="_.="     `--------`     "=._"=._/ )
      > _.="                            "=._ <
     (_/                                    \_)
DIE
,me);
   message_vision("\n[1;30m¼C»î ¼Ú©Z°ªÁ|ªø¼C¦V$Nªº¤è¦Vµ¦°¨½Ä¥h!![m\n",eme);
   message_vision(HIW"¡ãÀþ¶¡¶Â·t¤¤¹º¹L¤@¹D¥ú¨~¡ã $NªºÁy¦â¤@¤ùºG¥Õ!! "HIR"("+damage2+")\n"NOR,eme);
   eme->receive_damage("hp",damage2,me);
   eme->set_temp("slash",3);
   } else
    {
     message_vision(HIB"\n\n¼C»î¨g¯º¹D: µ¹..µ¹§Ú¡ã¡ã¡ã"HIR"¦å¡ã°Ú¡ã¡ã«¢¡ã«¢¡ã¡ã«¢¡ã¡ã«¢¡ã¡ã¡ã\n",me);
     message_vision(HIR"$N¨­¤Wªº¼C²ª¤£Â_ªº¬y¥X¤@ªiªiÂA¦å..("+damage+")\n"NOR,eme);
     eme->receive_damage("hp",damage,me);
     eme->add_temp("slash",-1);
    }
   } 
 }
 ::heart_beat();
 if(me)
 {
  if( me->query("hp") < 0 ) me->die();
 }
}

void die()
{
 object ob,ob1,a,ob2;
 int expp;
 string owner;
 ob = query_temp("last_damage_from");
 if(!ob) ob = this_player();
 owner=ob->query_temp("owner");
 if(owner)
 {
  ob=find_player(owner);
  if(!ob) ::die();
 } 
 if(ob)
 {
  a=environment(ob);
  a->delete("objects");
  if( !ob ) return;
  message_vision("\n[1;37m¼C»î ¼Ú©Zªº¨­§Î³vº¥¤Æ¬°¤@§â¼Cªº§Îª¬..[m\n",ob);
  shout(HIC"\n\nîh¥ñ¤F¤­­Ó¥@¬öªº ¼C»î ¼Ú©Z ²×©ó³Q"+ob->query("name")+HIC"«Ê¦L©óÅ]¼C¤§¤¤¤F!!\n\n"NOR);
  ob1=new(__DIR__"wp/otensword.c");
  ob1->move(a);
  expp=400000-(ob->query("level")*(3000+random(500)));
  if(expp<1) expp=random(17000);
  ob->add("exp",expp);
  tell_object(ob,"\n§A±o¨ì¤F"+expp+"ÂI¸gÅç­È.\n");
  ob->set("killoten",1);
  ob->save();
  tell_object(ob,"\n©Î³\\§A¸Ó§ä°|ªø¬Ý¬Ý¦³¨S¦³¼úÀy..\n");
  //   ::die();
  //ob2 = present("corpse", environment(ob));
  //if(!ob2) message_vision("§ä¤£¨ìcorpse..\n",ob);
  //else message_vision("§ä¨ìcorpse¤F!!\n",ob);
  //destruct(ob2);
  destruct(this_object());
 }
}
