// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name("§õªZ¹F", ({"lee wu da","lee","da"}));
        set("long",@LONG
¤@­Ó­è«ô¤J¤K·¥ªùªº¦~»´¤H¡A¥¿¦b³o¸Ì¹ïµÛ½_¯ó¤H½m²ß¤jºj³Z¡A
¬Ý°_¨Ó¦ü¥GÁÙ¤£¤Ó¼ô½m¡C

LONG
        );
        set("gender", "¨k©Ê");
        set("race", "human");
 	set("level",13);
        set("age", 19);
        //set("exp",300);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
			
//        set("env/wimpy", 10);		//°k¶]wimpy (10%)
        set("evil",-20);		//¨¸´c«× -20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("unarmed",99);	// §Þ¯à(¦Û©w)
	set_skill("combat",90);		//
	set_skill("fork",70);		//
	set_skill("da-fork",30);	//
	map_skill("fork","da-fork");
//	set("chat_chance_combat", 50);
//       set("chat_msg_combat", ({
//                (:command("exert da-fork"):),
//         }) );

	
   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
set("inquiry/master", @NAME
  [1;36m §Úªº®v³Å¯«ºj§õ´N¦b¤p«Î(house)¸Ì­±¡A·Q¨£¥L´N¶i¥h(enter)§a¡C[m
NAME );
//set("talk_reply","«ç»ò¿ì!?§Ú¤£¤p¤ß§â¤p©úÂê¦b¯µ±K°ò¦a(base)¤F.. §A¥i¥HÀ°§Ú±Ï±Ï¥L¶Ü?");
      setup();
//      set_element("fire");  //¦V©Ê: none,metal,plant,wind,ground,water,fire
      add_money("coin", 120);		//±aªº¿ú ¥j¥N:coin ²{¥N:dollar ¥¼¨Ó«h¥Îset("bank/future",¼Æ¶q);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/pike_13")->wield();
}


