#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "ªA°È¤p©j", ({ "bar lady","lady"}));
        set("long",@LONG
        ¤@­Ó°s©±ªºªA°È¤p©j¡A¥¿¦b¹ïµÛ§A«¢¸y¡C
	==============================================
	¥Ø¿ý <list>
	¶RªF¦è <buy ª««~> <buy ¼Æ¶q ª««~>
	==============================================
LONG);
        set("level",17);
        set("gender", "¤k©Ê");
        set("race", "human");
        set("age", 33);
        set("evil",-10);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set("attitude", "peaceful");   //·Å©Mªº NPC¡C
	set("talk_reply","§Ú­Ì½æªº°s¥i¬O«Ü¨üÅwªïªº³á!!");
	set("sell_list",([
  __DIR__"../obj/bloodmarry_wine" : 15,
  __DIR__"../obj/bluegimi_wine" : 20,
  __DIR__"../obj/beer" : 5,
  __DIR__"../obj/greentea" : 10,
]));

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ¤p¬ü.. ½Ð¦h«ü±Ð!![m
LONG );
        setup();
      add_money("dollar", 780);		//±aªº¿ú
      carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
      carry_object(__DIR__"../eq/gem_ring_1")->wear();
      carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
      carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

