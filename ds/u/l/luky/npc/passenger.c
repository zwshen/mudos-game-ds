#include <ansi.h>
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "®È«È", ({ "passenger","®È«È","passenger",}));
        set("long", "¤@­Óº¡Áy¾î¦×ªº®È«È¡M¥¿¦b³Q¦w¥þÄµ½Ã½L°ÝµÛ¡C\n"
        );
        set("level",20);
        set("title","[1;33m¥~¦a¤H[m");
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
        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("blade",40);		// §Þ¯à(¦Û©w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================ºA«×Ãþ§O=================================
//   set("attitude", "friendly");   //¤Íµ½ªº NPC¡C
   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
//   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C
//   set("attitude", "aggressive"); //¥D°Ê§ðÀ»,¥Í©Ê¦n°«ªºªº NPC¡C
//   set("attitude", "killer");     //¶Ý±þ¦¨©Êªº NPC¡C


//=============================¦Û°Ê°Ê§@=================================
  set("chat_chance", 0 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"®È«È¥Î¤Oªº½ð¤FÀð¾À¤@¸}!! ¦ü¥G«D±`¥Í®ð..\n",
(:command("say «z¾a!! ³o¬O¤°»òªA°ÈºA«×¹À!!!"):),
(:command("say ¨ì©³­n§Ú»¡´X¦¸°Ú~~ ³o§â¶}¤s¤M¬O§Ú­è­è¾ß¨ìªº.."):),
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m§Ú¥s°µ¤û¹L...§A°Ý³o­Ó·F¤°»ò?? µL²á!![m
LONG );


//=========================¾Ô°«°T®§===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"®È«È¯}¤f¤j½| : ¡u¥i´cªº³Ã¥ë¡ã¡T§Ú¥´¦º§A¡T¡v\n"NOR,
     }) );

        setup();

//==========================¸Ë³Æ¹D¨ã=============================
      add_money("coin", 200);		//±aªº¿ú
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("smile "+me->query("id") );
 return 1;
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m¦w¥þÄµ½Ã°¨¤W¯¸¥X¨Ó¹ï$N[1;37m»¡: ½Ð¤£­n°Ê¤â, ¥æµ¹§Ú­Ì³B²z´N¦n¤F¡C[m\n",this_player());
 return 1;
 }
return 0;
}

//======================°Ê§@¤ÏÀ³======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")´dºGªº²Y²D§o³Û: ±Ï©Rªü!! ±Ï©Rªü!!!\n"
        	+"®È«È(passenger)·Q¿Ñ±þ§Ú!! ®È«È(passenger)¬O±þ¤H¥û¤â!![m\n");
                command("say ¥L@#$ªº, ¦Ñ¤l¥¿¦b®ðÀY¤W©~µM´±½ð§Ú!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")´dºGªº²Y²D§o³Û: ±Ï©Rªü!! ±Ï©Rªü!!!\n"
        	+"®È«È(passenger)·Q¿Ñ±þ§Ú!! ®È«È(passenger)¬O±þ¤H¥û¤â!![m\n");
                command("say ¥L@#$ªº, ¦Ñ¤l¥¿¦b®ðÀY¤W©~µM´±°½¥´§Ú!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say ºu»·¤@ÂI!!§O·Ð§Ú!!");
                break;
        }
}

//======================±µ¨ü¤ÏÀ³======================================
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("¥L¤£·Q¦¬§AªºªF¦è¡C\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "®È«È»¡¹D¡R¦hÁÂ³o¦ì" + RANK_D->query_respect(who)
                + "¡M¯«©ú¤@©w·|«O¦ö§Aªº¡C\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
