// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "§õ¤p©j", ({ "miss lee","lee"}));
        set("long", "¤@­Ó²M¨qªº¦~»´¤p©j¡M¦o¦b³o¸Ìªº¤u§@¬O´£¨Ñ®È«È¦s©ñ´ÚªºªA°È¡C\n\n"
        	    +"  ¬d¸ß±b¤á½Ð¥Î <balance> \n"
        	    +"  ¬Ý¦s¿ú½Ð¥Î <deposit ª÷ÃB> \n"
                +"  ­n´£´Ú½Ð¥Î <withdraw ª÷ÃB> \n\n"
        );
        set("level",20);
        set("title","[1;32mª÷¿Ä¤H­û[m");
        set("gender", "¤k©Ê");
        set("race", "¤HÃþ");
        set("age", 42);
        set("exp",1000);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
        set("str",31);			//³]©wÄÝ©Ê(¥i§K)
        set("dex",21);			//¤]¥i¥H¥u³]©w level
        set("con",33);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
        set("int",18);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
        set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
        
        //·sªº­×¥¿: ª`·N!! (wimpy)
        set("wimpy", 20);		//°k¶]wimpy (20%)
        
        set("evil",-20);		//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","·Q¦s¿ú(deposit)¶Ü? ±`±`¦s´Ú¥i¥HÁ×§K¿ò¥¢³á!!");

  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
(:command("smile"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ§õÆA¬Ã.. ½Ð¦h«ü±Ð!![m
LONG );

        setup();

      add_money("dollar", 120);		//±aªº¿ú(coin¥j¥N,dollar²{¥N,¥¼¨Ó¨S¦³)

}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


