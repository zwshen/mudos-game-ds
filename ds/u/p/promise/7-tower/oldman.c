#include <ansi.h>
inherit NPC;

void create()
{
  set_name("¦ÑªÌ", ({ "oldman" }) );
  set("gender", "¨k©Ê" );
  set("long",@LONG

´¿¸g¦bªZªL¤W¦³µÛ¤@®u¤§¦a¡A¤HºÙ¼C¬Pªº¥Õ¤¯Á÷¡A¦ý¬°¤°»ò¦¹®É
·|¸¨ªº¦p¦¹ªº¸¨¾z¡A¦ç¤£µÛ§ü¤£¾ãªº¡A·Q¥²¦³µÛ¤£¬°¤Hª¾ªº©¹¨Æ
§a¡C

LONG
);
  set("age",61);
  set("level",1);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"¦ÑªÌ¤£°±ªº¹Ä®ð¡A¦ü¥G¦³µÛ»¡¤£§¹ªº©¹¨Æ¡C\n",
(: command("stare") :),
}));
  set("talk_reply","³o¦ìªB¤Í¡A·Qª¾¹DÔ£½Ð»P§Ú¥æ½Í(Say)¡I\n");
  setup();
  add_money("coin",2000+random(1000));
  }

void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("½Ð¥Î say <¥æ½Íªº¤è¦¡> ¨Ó¨ú±o©Ò»Ý±¡³ø¡C\n");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  object player = this_player();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"©¹¨Æ") != -1)
  {
    command("hmm");
    command("say ³£©Ç§Ú¤@®É¤j·N¡A±Ñ¦b¥L¤â¤¤¡C");
    command("sigh");
  }
  if(strsrch(str,"¥L") !=-1)
  {
    command("say ¥L¡H­þ­Ó¥L¡A¬O§Ú¾Ô±Ñªº¨º­Ó¤H¡H");
    
  }
  if(strsrch(str,"¬Oªº") != -1)
  {
    command("say ¥L´N¬O¦¹¶ðªº¶ð¥D¡A¤HºÙ¬þ§¯¨¸ªº´Ý¦ü");
    command("say ·í¦~­n¤£¬O§Ú¤Ó¤j·N¡A¤Ó¬Ý»´¥Lªº¹ê¤O¡A§Ú¤]¤£·|¸¨±o¦p¦¹ªº¤U³õ¡C");
    command("say ²×¥Í³QÃö¦b¦¹¶ð¸Ì¡C");
    command("say ³o¦ìªB¤Í¡A§AÄ@·NÀ°§Ú¦£¶Ü¡H");
  }
  if(strsrch(str,"Ä@·N") != -1)
  {
    command("say ¨º§Úµ¹§A¨â¹D¿ï¾Ü¡A²Ä¤@±þ¤F§ÚÅý§Ú¸Ñ²æ¡A²Ä¤G±Ï§Ú¥X¥h¡I");
    command("say ¦pªG§A¿ï¾Ü«eªÌ¡A²{¦b´N°Ê¤â§a(kill oldman)¡C");
    command("say ­Õ­Y¬O«áªÌ¡A¨º§Ú¦b¦¹¦aµ¥§A¡A¶¶«KÀ°§Ú¨ú±o±w¤Q¸ÑÄñ¤Y¡I¡I");
    
  }
  if(strsrch(str,"±w¤Q¸ÑÄñ¤Y") != -1)
  {
    command("say ³o­Ó¦Ñ¸é¤£¦ý³n¸T§Ú¡AÁÙ¹G§Ú¦Y¤U¦¹¬rÃÄ¡I");
    command("say Å¥»¡¬O­n¦bªA¤@²É¤@¼ËªºÃÄª«¡A¤~¯à¸Ñ¬r¡C");
    command("say §Ö¡I§Ú¦b³o¨àµ¥§A¡A§Ö¥h§a¡I");
    command("say ¬°¤Fªí¹F§Úªº¤ß·N¡A§Ú¹B¥Î´Ý¦sªº¤º¤O¡A°e§A¨ì¦¹¨ÈªÅ¶¡³Ì¤º³¡¡I¡I");
    message_vision(HIW"\n¥u¨£¦ÑªÌ¹B°_¤º¤O¡A´§¤F¤@´x´ÂµÛ$N¥h¡A$N®ø¥¢µLÂÜ¡I¡I"NOR);
    player->move(__DIR__"4f_7");
  }

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
     message("world:world1:vision","\n"HIY"¡i¯³°²¥P§Ö³ø¡j¡G"HIM"¤Q´c¤£³jªº"+ob->query("name")+"¦]¿ù±þ¦ÑªÌ¡Aµ²ªG³Q¦ÑªÌªº» »î¾zµ¹À»ÀÅ¤F¡I¡I\n\n"NOR,users());
           ob->die();
                     ::die();
        return;
}

