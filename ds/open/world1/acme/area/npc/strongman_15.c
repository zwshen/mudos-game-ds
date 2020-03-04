// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name("§§º~", ({"strong man","man"}));
        set("long",@LONG
¤@­Ó¤Q¤À±j§§ªº¨k¤H¡A¬Ý¨Ó¥~®aµw¥\¦³¤£¿ùªº©³¤l¡AÀ³¸Ó´¿¸g«ô
©ó¦W®vªù¤U¡C¤£ª¾¬°¦ó·|²_¸¨¨ì¦¹ªíºt¯Ý¤f¸H¤j¥Ûµ¥ÂøÃÀïM¤f¡A¬Ý¤F
Åý¦P¬°½mªZªÌªº§A¦³ÂI¤ß»Ä¡C

LONG
        );
        set("gender", "¨k©Ê");
        set("race", "human");
 	set("level",15);
        set("age", 30);
        //set("exp",300);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
			
//        set("env/wimpy", 10);		//°k¶]wimpy (10%)
        set("evil",-20);		//¨¸´c«× -20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("unarmed",99);	// §Þ¯à(¦Û©w)
	set_skill("combat",90);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
set("inquiry/name", @NAME
  [1;36m §Ú¥s°µÀs¤Ñ¥Õ.. ½Ð¦h«ü±Ð!![m
NAME );
set("inquiry/Às¤Ñ¥Õ", "³o¬O§Úªº¦W¦r, ¦³°ÝÃD¶Ü¡H");
//set("talk_reply","«ç»ò¿ì!?§Ú¤£¤p¤ß§â¤p©úÂê¦b¯µ±K°ò¦a(base)¤F.. §A¥i¥HÀ°§Ú±Ï±Ï¥L¶Ü?");
      setup();
//      set_element("ground");    //¦V©Ê: none,metal,plant,wind,ground,water,fire
      add_money("coin", 320);		//±aªº¿ú ¥j¥N:coin ²{¥N:dollar ¥¼¨Ó«h¥Îset("bank/future",¼Æ¶q);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/hammer_16")->wield();
}


