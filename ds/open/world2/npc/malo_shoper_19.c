// °Ó¤H½d¨Ò(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "°Ó©±¦ÑÁó", ({ "shop boss","boss"}));
        set("long",@LONG
        ¤@­Ó­D­Dªº¤¤¦~¨k¤H¡A¥¿¦b²M¼ä³f¬[¡C
	==============================================
	¬d¸ß¦s³f 	<list> <list wp> <list eq>
	¶RªF¦è 		<buy ª««~> <buy ¼Æ¶q ª««~>
	½æªF¦è 		<sell ª««~> <sell all> <sell ¼Æ¶q ª««~>
	¸Õ¥ÎªF¦è 	<try ª««~>
	==============================================
LONG);
        set("level",19);
        set("title","[1;32m°Ó¤H[m");
        set("gender", "¨k©Ê");
        set("race", "human");
        set("age", 42);
        set("evil",10);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set("attitude", "peaceful");   //·Å©Mªº NPC¡C
	set("talk_reply","¦n°Ú.. ¦h¤¶²Ð¤@¨ÇªB¤Í¨Ó¶RªF¦è§a!!");
	set("storeroom",__DIR__"shop1");	//ª`·N. ­n«Ø¥ß¤@­Óroom©ñªF¦è

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µªL©_.. ½Ð¦h«ü±Ð!![m
LONG );
        setup();
      add_money("dollar", 1100);		//±aªº¿ú
      carry_object(__DIR__"../eq/cloth_pants_5")->wear();
      carry_object(__DIR__"../eq/leather_boots_3")->wear();
      carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_sell","sell");
	add_action("do_try","try");
}


