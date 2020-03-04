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
        	    +"  ¬Ý¦s³f½Ð¥Î <list> \n"
        	    +"  ­n¶RªF¦è¥Î <buy ª««~> <buy ¼Æ¶q ª««~> \n\n"
        );
        set("level",20);
        set("title","[1;32m¤p³c[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 42);
        set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
//        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",-20);		//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
   set("talk_reply","¦h¶RÂIªF¦è´NºâÀ°¤F¤j¦£Åo..¨þ¨þ..");

//ª`·N. ­n³]©w³f«~²M³æ

   set("sell_list",([	
           "/u/l/luky/npc/item/bag"    : 25, //ªí¥Ü¨C¶R¤@­Ó³U¤l·|¦©15ÂI¸Éµ¹ÂI¼Æ
           "/u/l/luky/npc/item/dump"   : 10, //°£«D¦³¯S®í²z¥Ñ§_«h¤£¥i³]¬°0 (µL­­¶q¨ÑÀ³)
       ]) );				     //ª±®a°ò¥»¦³40ÂI, ¨C¤@µ¥¯Å¦A¥[20ÂI. Lv25=540ÂI

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
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}


