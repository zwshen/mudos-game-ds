// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void call_help();
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "Äõ·æ´µ", ({ "rancus",}));
        
        //tmr, long§A¦Û¤v§ï§ï§a. °tÂIeq..
        set("long", "¤@­Ó¨­¬ï¨îªAªº¤u§@¤H­û, ±µ¬¢¨Ó©¹ªº«È¤H¡C\n\n"
        	    +"  ¬d¸ß±b¤á½Ð¥Î <balance> \n"
        	    +"  ¬Ý¦s¿ú½Ð¥Î <deposit °ò¥»ª÷ÃB> \n"
        	    +"  ­n´£¿ú½Ð¥Î <withdraw °ò¥»ª÷ÃB> \n\n"
        );
        
        set("level",3);
        set("title","[1;32m§U¤â[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 45);

        set("combat_exp",300);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
        
        set("evil",-20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("unarmed",20);		// §Þ¯à(¦Û©w)
	set_skill("parry",10);		//
	set_skill("dodge",10);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","·Q¦s¿ú(deposit)¶Ü? ±`±`¦s´Ú¥i¥HÁ×§K¿ò¥¢³á!!");

  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
(: command("smile") :),
}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
 HIR"Äõ·æ´µ¤j¥s : ¡u±Ï©R£«¡ã¡T¦³¤H·m§T£«¡T¡v\n"NOR,
     }) );
//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µÄõ·æ´µ.. ½Ð¦h«ü±Ð!![m
LONG );

        setup();

		//±aªº¿ú(coin¥j¥N,dollar²{¥N,¥¼¨Ó¨S¦³)
	add_money("silver", 25);
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

void call_help()
{
	object roken,target;
	target = offensive_target(this_object());
	if(!target) return ;

	roken=present("roken", environment(this_object()));
	if(!roken)
	{
		message_vision("Äõ·æ«ä¤j¥s: §Ö¨Ó¤H­þ~~ ±Ï©R£«!! \n",target);
		return ;
	}
	if(roken->is_fighting(target))
	{
		message_vision("¬¥ªÖ¬Ý°_¨Ó«Ü¥Í®ðªº¼Ë¤l!!\n",target);
		return ;
	}
	else
	{
	 roken->kill_ob(target);
	 say(HIW"¬¥ªÖ«ã½|¹D¡G¥ú¤Ñ¤Æ¤é¤§¤UÁx´±±þ¤H·m§T¡I§Ú­n´À¤Ñ¦æ¹D¡I¡I\n"NOR);
	 message_vision("¬¥ªÖ¤j³Ü¤@Án, ¶}©l¹ï$Nµo°Ê§ðÀ»!!\n",target);
	 return ;
	}
}

