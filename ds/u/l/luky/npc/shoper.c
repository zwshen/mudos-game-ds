// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "ªL¦ÑÁó", ({ "boss lin","lin","boss"}));
        set("long", "¤@­Ó­D­Dªº¤¤¦~¨k¤H¡MÀÇ¬Nªº¹ïµÛ§A¯ºµÛ¡C\n\n"
        	    +"  ¬Ý¦s³f½Ð¥Î <list> <list wp> <list eq>\n"
        	    +"  ­n¶RªF¦è¥Î <buy ª««~> <buy ¼Æ¶q ª««~> \n"
        	    +"  ­n½æªF¦è¥Î <sell ª««~> <sell all> <sell ¼Æ¶q ª««~>\n\n"
        );
        set("level",20);
        set("title","[1;32m°Ó¤H[m");
        set("gender", "¨k©Ê");
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
//        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","¦n°Ú.. ¦h¤¶²Ð¤@¨ÇªB¤Í¨Ó¶RªF¦è§a!!");
	set("storeroom","/u/l/luky/shop");	//ª`·N. ­n«Ø¥ß¤@­Óroom©ñªF¦è(°Ñ¦Ò/u/l/luky/shop.c)

  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"ªL¦ÑÁó¯º¯ºªº»¡: ¤p¥S§Ì, ­n¤£­n¶RÂIªF¦è°Ú? §Ú¥i¥Hºâ§A«K©y¤@ÂI³á..\n",
(:command("smile"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µªL¤jµo.. ½Ð¦h«ü±Ð!![m
LONG );

        setup();

      add_money("coin", 120);		//±aªº¿ú
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
add_action("do_list","list");
add_action("do_buy","buy");
add_action("do_sell","sell");
}


