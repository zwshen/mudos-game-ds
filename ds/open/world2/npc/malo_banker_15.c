// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name("»È¦æ§U²z", ({ "bank assistant","assistant"}));
        set("long",@LONG
        ¤@­Ó²M¨qªº¦~»´¤p©j¡M¦o¦b³o¸Ì´£¨ÑÅU«È¦s©ñ´ÚªºªA°È¡C
        	
        	¾lÃB¬d¸ß	<balance> 
        	¦s´Ú		<deposit ª÷ÃB> 
        	´£´Ú		<withdraw ª÷ÃB> 
LONG);
        set("level",15);
        set("title","[1;32m¦æ­û[m");
        set("gender", "¤k©Ê");
        set("race", "human");
        set("age", 26);
        
        //·sªº­×¥¿: ª`·N!! (wimpy)
        set("wimpy", 20);		//°k¶]wimpy (20%)
	set("evil",-20);		//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set("attitude", "peaceful");   //·Å©Mªº NPC¡C
	set("talk_reply","·Q¦s¿ú(deposit)¶Ü? ±`±`¦s´Ú¥i¥HÁ×§K¿ò¥¢³á!!");
	set("no_kill",1);

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ§õ±m¬Ã.. ½Ð¦h«ü±Ð!![0m
LONG );

        setup();
      add_money("dollar", 1670);		//±aªº¿ú(coin¥j¥N,dollar²{¥N,¥¼¨Ó¨S¦³)
	carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
}

void init()
{
 ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}
