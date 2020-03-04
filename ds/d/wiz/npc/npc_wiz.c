#include <ansi.h>
inherit NPC;
void goto_1();
void goto_2();
void goto_3();
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "¤j¼L", ({ "bigmouth" }));
        set("long", "¤@¦ì«Ü¥Î¥\\ªº·s¤â§Å®v¡M¥¿¦b¨ì³B¬Ý¤å³¹¾ÇªF¦è¡C\n");
        set("level",20);
        set("title","[1;32m¨£²ß§Å®v[m");
        set("gender", "¨k©Ê");
        set("race", "human");
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
  set("chat_chance", 1 );  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
"§AÄ±±o¦³ÂI¤£¤Ó¹ï«l¡C\n",
(:command("look board"):),
(:command("say can you help me?"):),
(:command("hmm"):),
(:command("lick"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m§Ú¥s°µ§d¥Í¥|...§A¦n!![m
LONG );


//=========================¾Ô°«°T®§===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"¤j¼L«Ü¤£²nªº»¡ : ¡u¥i´cªº³Ã¥ë¡ã¡TPK´NPK, ½Ö©È½Ö¡T¡v\n"NOR,
     }) );


// ±Æµ{°Ê§@

set("schedule",
([
	"00" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº0ÂI¾ã¤F³á!!") :),
	"01" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº1ÂI¾ã¤F³á!!") :),
	"02" : (: command("go up") :),
	"02" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº3ÂI¾ã¤F³á!!") :),
	"04" : (: command("go down") :),
	"05" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº5ÂI¾ã¤F³á!!") :),
	"06" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº6ÂI¾ã¤F³á!!") :),
	"07" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº7ÂI¾ã¤F³á!!") :),
	"08" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº8ÂI¾ã¤F³á!!") :),
	"09" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº9ÂI¾ã¤F³á!!") :),
	"10" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº10ÂI¾ã¤F³á!!") :),
	"11" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº11ÂI¾ã¤F³á!!") :),
	"12" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº12ÂI¾ã¤F³á!!") :),
	"13" : (: goto_1 :),
	"14" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº14ÂI¾ã¤F³á!!") :),
	"15" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº15ÂI¾ã¤F³á!!") :),
	"16" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº16ÂI¾ã¤F³á!!") :),
	"17" : (: goto_2 :),
	"18" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº18ÂI¾ã¤F³á!!") :),
	"19" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº19ÂI¾ã¤F³á!!") :),
	"20" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº20ÂI¾ã¤F³á!!") :),
	"21" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº21ÂI¾ã¤F³á!!") :),
	"22" : (: command("say ²{¦b¬O¹CÀ¸¤¤ªº22ÂI¾ã¤F³á!!") :),
	"23" : (: goto_3 :),
]));


        setup();

//==========================¸Ë³Æ¹D¨ã=============================
      add_money("coin", 200);		//±aªº¿ú
      carry_object("/u/l/luky/npc/item/bag");
      //carry_object(__DIR__"wp/kaisan_b")->wield();
      //carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("smile "+me->query("id") );
 command("say §Ú·|§V¤O¾Ç²ßªº!");
 return 1;
}

void goto_1()
{
	if(!find_object("/u/l/luky/workroom")) return;
 message_vision(HIW" ¡y°{¤HÅo~ ¡z¥u¨£$N"HIW"©¹¤ÑªÅ¤@ÅD¡M¤Æ¨­¬°¤@°¦¤p½¿½»¡M°Ô°Ô°Ô~ªº­¸¨«¤F¡C\n"NOR, this_object());
 this_object()->move("/u/l/luky/workroom");
 message_vision(HIW"¡yÅF~~¡z$N"HIW"¬ðµM¥X²{¦b¤@°}·ÏÃú¤§¤¤¡C\n"NOR, this_object());
}

void goto_2()
{
	if(!find_object("/u/s/shengsan/workroom")) return;
 message_vision(HIW" ¡y°{¤HÅo~ ¡z¥u¨£$N"HIW"©¹¤ÑªÅ¤@ÅD¡M¤Æ¨­¬°¤@°¦¤p½¿½»¡M°Ô°Ô°Ô~ªº­¸¨«¤F¡C\n"NOR, this_object());
 this_object()->move("/u/s/shengsan/workroom");
 message_vision(HIW"¡yÅF~~¡z$N"HIW"¬ðµM¥X²{¦b¤@°}·ÏÃú¤§¤¤¡C\n"NOR, this_object());
}

void goto_3()
{
	if(!find_object("/d/wiz/hall1")) return;
 message_vision(HIW" ¡y°{¤HÅo~ ¡z¥u¨£$N"HIW"©¹¤ÑªÅ¤@ÅD¡M¤Æ¨­¬°¤@°¦¤p½¿½»¡M°Ô°Ô°Ô~ªº­¸¨«¤F¡C\n"NOR, this_object());
 this_object()->move("/d/wiz/hall1");
 message_vision(HIW"¡yÅF~~¡z$N"HIW"¬ðµM¥X²{¦b¤@°}·ÏÃú¤§¤¤¡C\n"NOR, this_object());
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
 message_vision("[1;37m¤j¼L¹ï$N[1;37m»¡: ½Ð¤£­n°Ê²Ê, ¦³¨Æ¦n°Ó¶q¡C[m\n",this_player());
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
        	+"¤j¼L(bigmouth)·Q¿Ñ±þ§Ú!! ¤j¼L(bigmouth)¬O±þ¤H¥û¤â!![m\n");
                command("say ¥L@#$ªº, ¦Ñ¤l¥¿¦b¥Î¥\\©~µM´±½ð§Ú!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")´dºGªº²Y²D§o³Û: ±Ï©Rªü!! ±Ï©Rªü!!!\n"
        	+"¤j¼L(bigmouth)·Q¿Ñ±þ§Ú!! ¤j¼L(bigmouth)¬O±þ¤H¥û¤â!![m\n");
                command("say ¥L@#$ªº, ¦Ñ¤l¥¿¦b¥Î¥\\©~µM´±½ð§Ú!!");
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
