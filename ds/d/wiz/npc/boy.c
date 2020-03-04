// ¥ô°È½d¨Ò¤Hª« 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "¤p©ú", ({ "boy"}));
        set("long", "¤@­Ó¥i·R¤S½Õ¥Öªº¤p¨k«Ä, ¤£Â_ªºª±§ËµÛ¥Lªº¤â«ü¡C\n"
        );
        set("level",2);
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 6);
        set("exp",300);			//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
        set("str",5);			//³]©wÄÝ©Ê(¥i§K)
        set("dex",6);			//¤]¥i¥H¥u³]©w level
        set("con",5);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
        set("int",6);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
        set("combat_exp",200);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
        set("env/wimpy", 10);		//°k¶]wimpy (10%)
        set("evil",-30);		//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",20);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",20);		//

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ¤p©ú.. ½Ð¦h«ü±Ð!![m
LONG );

      setup();

      add_money("coin", 20);		//±aªº¿ú
      carry_object("/u/l/luky/npc/item/dump");
}


