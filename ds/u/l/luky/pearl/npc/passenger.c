#include <ansi.h>
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "®È«È", ({ "passenger","®È«È","passenger",}));
        set("level",30);
        set("title","[1;33m¥~¦a¤H[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 42);
        set("evil",40);
        set("coin", 1400+random(300));
        set("long", @LONG
¤@­Óº¡Áy¾î¦×ªº®È«È¡M¥¿¦b³Q¦w¥þÄµ½Ã½L°ÝµÛ¡C
LONG
        );

//========================ºA«×Ãþ§O=================================
   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C

//=============================¦Û°Ê°Ê§@=================================
  set("chat_chance", 3 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"®È«È¥Î¤Oªº½ð¤FÀð¾À¤@¸}!! ¦ü¥G«D±`¥Í®ð..\n",
(:command("say «z¾a!! ³o¬O¤°»òªA°ÈºA«×¹À!!!"):),
(:command("say ¨ì©³­n§Ú»¡´X¦¸°Ú~~ ³o§â¶}¤s¤M¬O§Ú­è­è¾ß¨ìªº.."):),
(:command("sigh"):),
(:command("angry"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m§Ú¥s°µ¤û¹L...§A°Ý³o­Ó·F¤°»ò?? µL²á!![m
LONG );


//=========================¾Ô°«°T®§===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("chair "+this_player()->query("id")):),
 HIR"®È«È¯}¤f¤j½| : ¡u¥i´cªº³Ã¥ë¡ã¡T§Ú¥´¦º§A¡T¡v\n"NOR,
     }) );

        setup();

//==========================¸Ë³Æ¹D¨ã=============================
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
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

void reset()
{
        delete("memory");
}
