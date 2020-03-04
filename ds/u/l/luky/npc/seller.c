// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "¤ý¤jµo", ({ "dar far wang","wang"}));
        set("long", "¤@­Ó¥´¤uªº¦~»´¤H¡M¥¿¦b³o¸ÌÂ\\Åu¦ìÁÈ¨ú¾Ç¶O¡C\n\n"
        	    +"  ¬Ý¦s³f½Ð¥Î <show> \n"
        	    +"  ­n¶RªF¦è¥Î <take ª««~> <take ¼Æ¶q ª««~> \n\n"
        );
        set("level",20);
        set("title","[1;32m¤p³c[m");
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
        set("evil",-20);		//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","¦h¶RÂIªF¦è´NºâÀ°¤F¤j¦£Åo..¨þ¨þ..");
	//ª`·N. ­n³]©w³f«~²M³æ
   set("sell_list",([	
           "/u/l/luky/npc/item/bag"    : 25, //ªí¥Ü¨C¶R¤@­Ó³U¤l·|¦©15ÂI¸Éµ¹ÂI¼Æ
           "/u/l/luky/npc/item/dump"   : 10, //°£«D¦³¯S®í²z¥Ñ§_«h¤£¥i³]¬°0 (µL­­¶q¨ÑÀ³)
       ]) );

  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"¤ý¤jµo¯º¯ºªº»¡: ¤j¦ÑÁó, ­n¤£­n¶RÂIªF¦è<take>°Ú? §Ú½æªºªF¦è<show>¬Oªþªñ³Ì«K©yªº³á!\n",
(:command("dance master"):),
(:command("coffee wang"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ¤ý¤jµo.. ½Ð¦h«ü±Ð!![m
LONG );

        setup();

      add_money("coin", 120);		//±aªº¿ú
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
add_action("do_list","show");
add_action("do_buy","take");
}


