// ¼ú¨÷°Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "ÁÂªø§Ê", ({ "heish choun ting","ting"}));
        set("long", "¤@­ÓÀ¹µÛ²´Ãèªº¤¤¦~¤H¡M¥¿¦b³o¸ÌÂ\\Åu¦ì½æ±m¨÷¡C\n\n"
        	    +"  ¬Ý¦s³f½Ð¥Î <list> \n"
        	    +"  ­n¶RªF¦è¥Î <buy ª««~> <buy ¼Æ¶q ª««~> \n"
        	    +"  ­n¹ï¼ú¥Î <reward> \n\n"
        );
        set("level",20);
        set("title","[1;32m¼ú¨÷°Ó[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 42);
        set("exp",1000);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
       
        set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
//        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","¦h¶RÂI±m¨÷§a..¨þ¨þ..");
	//ª`·N. ­n³]©w³f«~²M³æ
   set("sell_list",([	
           TICKET    : 20, //ªí¥Ü¨C¶R¤@±i±m¨÷·|¦©20ÂI¸Éµ¹ÂI¼Æ
       ]) );
  set("no_kill",1);
  set("no_fight",1);
  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"ÁÂªø§Ê¯º¯ºªº»¡: ¤j¦ÑÁó, ­n¤£­n¶RÂI±m¨÷<buy>°Ú? §Ú½æªº±m¨÷<list>¤¤¼ú²v«Ü°ª³á!\n",
(:command("grin"):),
(:command("think"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µÁÂªø§Ê.. ½Ð¦h«ü±Ð!![m
LONG );

        setup();

      add_money("coin", 120);		//±aªº¿ú

}

void init()
{
::init();
add_action("do_list","list");
add_action("do_buy","buy");
add_action("do_reward","reward");
}


