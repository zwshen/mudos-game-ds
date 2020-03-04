#include <ansi.h>
#define DRAGON_M "/open/always/dragon_mark"
#define MOON_M "/open/always/moon_mark"
inherit NPC;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "À°·|¨ÏªÌ", ({ "club messager","messager"}));
        set("long", "¤@­Ó¶Â¦ç¤H¡C\n§A¦pªG¿ò¥¢¤FÀ°·|«Hª«, ¥i¥H¥´(checkclub)¦V¥L¥Ó½Ð¤@­Ó·sªº«Hª«¡C\n"
        );
        set("level",1);
        set("title","[1;33m¸q¤u[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 1);
        set("exp",10);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
        set("str",1);			//³]©wÄÝ©Ê(¥i§K)
        set("dex",1);			//¤]¥i¥H¥u³]©w level
        set("con",1);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
        set("int",1);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
        set("combat_exp",1);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
//        set("env/wimpy", 20);		//°k¶]wimpy (20%)
        set("evil",-20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

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
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
§A°Ý³o­Ó·F¤°»ò?? µL²á!!
LONG );


//=========================¾Ô°«°T®§===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"®È«È¯}¤f¤j½| : ¡u¥i´cªº³Ã¥ë¡ã¡T§Ú¥´¦º§A¡T¡v\n"NOR,
     }) );

        setup();

//==========================¸Ë³Æ¹D¨ã=============================
//      add_money("coin", 200);		//±aªº¿ú
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("say §A¦pªG±¼¤FÀ°·|«Hª«´N¨Ó§ä§Ú¥Ó½Ð(checkclub)§a!");
 return 1;
}

void init()
{
	::init();
	add_action("do_checkclub","checkclub");
}

int do_checkclub(string arg)
{
	object me,mark,old_mark;
	string mark_file="";
	me=this_player();
	if(!arg) return notify_fail("checkclub < À°·|¦WºÙ > ¨Ò¦p: checkclub moon ¡C\n");
	if(CLUB_D->check_member(arg,getuid(me)) == 0 ) return notify_fail("¿ù»~ªºÀ°·|¦WºÙ©Î¬O§A¤£¦bÀ°·|¦W³æ¤¤¡C\n");
	mark_file=CLUB_D->query_club_mark(arg);
	if(mark_file=="") return notify_fail("À°·|«Hª«ÀÉ®×©|¥¼µn¿ý¡C\n");
	
	if(!mark=new(mark_file)) return notify_fail("À°·|«Hª«ÀÉ¿ù»~¡C\n");
	
	if(old_mark=present(mark->query("id"),me)) return notify_fail("§A¤w¸g¦³À°·|«Hª«¤F¡C\n");
	
	if(!mark->can_move(me))
	{
	 destruct(mark);
	 return notify_fail("§A­n¥ý¥á±¼¤@¨ÇªF¦è¤~®³ªº°ÊÀ°·|«Hª«¡C\n");
	}
	mark->move(me);
	message_vision("$N®³¤F¤@"+mark->query("unit")+mark->name()+"µ¹$n¡C\n",this_object(),me);
	me->save();
	return 1;

}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("¥L¤£·Q¦¬§AªºªF¦è¡C\n");
        else if( val > 1000 )
        {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/10000) );
        }
        say( "¨ÏªÌ»¡¹D¡R¦hÁÂ³o¦ì" + RANK_D->query_respect(who)
                + "¡M¯«©ú¤@©w·|«O¦ö§Aªº¡C\n");

        return 1;
}
