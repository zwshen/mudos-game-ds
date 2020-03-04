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
       
        set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

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
  [1;36m §Ú¥s°µªL³Ç§J.. ½Ð¦h«ü±Ð!![m
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
	add_action("do_sell","sell");
}

int accept_object(object who, object ob) //±µ¨üª««~®É
{
        int val;

        val = ob->value();
        if( !val ) //¤£¬O¿ú
        {
		command("say "+who->name()+", §A¥i¥H¥Îsell½æµ¹§Ú");       
                return notify_fail("¥L¤£¦n·N«äÀH«K¦¬§O¤HªºªF¦è¡C\n");
        }
        else
        {
		command("say "+who->name()+", µL¥\¤£¨ü¸S, §A¥i¥H¥Îlist¬Ý¬Ý§A·Q¶R(buy)¤°»ò..");       
                return notify_fail("¥L¤£¦n·N«äÀH«K¦¬§O¤Hªº¿ú¡C\n");
        }

}

/* /u/l/luky/shop.c ¤º®e¦p¤U


inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","ªL¦ÑÁóªº­Ü®w");
set("long","\n");
set("light",1);
set("no_clean_up",1);
set("objects",([
 "/u/l/luky/npc/item/bag":1,
 "/u/l/luky/npc/eq/blackjacket":3,
 "/u/l/luky/npc/wp/kaisan_b":1,
 ]));
set("exits", ([	//¥X¤f³]©óNPC¦ì¸m,¥i¥H¤£³]
"out":"/open/world2/anfernee/start/bug",
]));
setup();
}



*/