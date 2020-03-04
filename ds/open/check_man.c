/* 
 * ´£¨Ñ½u¤Wª±®a¨¤¦âÄÝ©ÊÁ`©M¦Cªí
 *
 *
 */
#include <ansi.h>
inherit NPC;
int sort_atts(int at1, int at2);
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "Às¤@", ({ "ryu ichi","ryu","ichi"}));
        set("long", @LONG
¬M¤J²´Ã®ªº¬O¤@¦ì·L­Dªº¤¤¦~¨k¤l¡A¿Ë¤Áªº²´¯«¤¤³zµÛ¤@ªÑ·F½m
ªº¦¨¼ô·P¡C¦~»´®Éªº¥L¬O¤@¦ì«i´±ªº«_ÀI°Ó¤H¡A¦b¤@¦¸´X¥G³à©Rªº¨Æ
¥ó¤¤³Q¥¿¥©¸g¹Lªº«_ÀIªÌ©Ò·f±Ï¡A¦¹«á«K¾n¦u¦b¦¹¦aÀ°§U«_ÀIªÌ­Ì¸Ñ
¨M¤@¨ÇºÃÃøÂø¯g¡C

     checkclub	< À°·|¦WºÙ >	¸ÉµoÀ°·|«Hª« [§K¶O]
     checkuser	< ª±®aªºid >	½Õ¬d½u¤W¬Y¦ìª±®aÄÝ©Ê±j«× [200¤¸/¦¸]
          (PS. §Å®v¥i¨Ï¥Îuserdata«ü¥O¨ú±o½u¤Wª±®aÄÝ©ÊÁ`©M¦Cªí)

LONG
        );
        set("level",50);
        set("title","[1;33mªÀ¤u[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 42);
        set("exp",10);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
        set("str",73);			//³]©wÄÝ©Ê(¥i§K)
        set("dex",54);			//¤]¥i¥H¥u³]©w level
        set("con",67);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
        set("int",58);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
        set("evil",-20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

//========================ºA«×Ãþ§O=================================
//   set("attitude", "friendly");   //¤Íµ½ªº NPC¡C
   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
//   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C
//   set("attitude", "aggressive"); //¥D°Ê§ðÀ»,¥Í©Ê¦n°«ªºªº NPC¡C
//   set("attitude", "killer");     //¶Ý±þ¦¨©Êªº NPC¡C


//===========================°ÝÃD¦^µª==================================
set("inquiry", ([
"name":"¦b¤UÀs¤@¡A½Ð¦h¦h«ü±Ð¡C\n",
"club":"¾Ú§Ú©Òª¾¡A¥Ø«e¦³¥|¤jÀ°·|¡A¤À§O¬O¡y¯«±Ú¡z¡y¨gÀs¡z¡y¤ë±Ú¡zÁÙ¦³¡y¤Ñ¦a¡z¡C\n",

// add by alickyuen
"marry" : "§A³Ìªñªº±B«Ã¥Í¬¡¦p¦ó³á¡H\n",
]));
       setup();

//==========================¸Ë³Æ¹D¨ã=============================
//      add_money("coin", 200);		//±aªº¿ú
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}
/*
int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("say §A¦pªG±¼¤FÀ°·|«Hª«´N¨Ó§ä§Ú¥Ó½Ð(checkclub)§a!");
 return 1;
}
*/
void init()
{
	::init();
	add_action("do_checkclub","checkclub");
	add_action("do_checkuser","checkuser");
	add_action("do_checkmarry","checkmarry");
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
int do_checkuser(string arg)
{
	object me,target;
	string msg="",target_name="";
	int *atts;
	me=this_player();
// if(!arg || arg=="") return notify_fail("checkclub < ^@^P^W|^FW^Z^Y > ^H^R^Fp: checkclub moon ^AC\n");
 if(!arg || arg=="") return notify_fail("checkuser < ª±®aid > ¨Ò¦p: checkuser luky \n");
	
	if(!target=find_player(arg)) return notify_fail("¥Ø«e½u¤W§ä¤£¨ì³o¦ìª±®a¡C\n");
	if(wizardp(target) && !me->visible(target)) return notify_fail("¥Ø«e½u¤W§ä¤£¨ì³o¦ìª±®a¡C\n");
	if(!me->can_afford(200))
		return notify_fail("³o¶µªA°È»Ý­n200¤¸¡A¦Ó§A¨­¤Wªº¿ú¤£°÷¡C\n");
	 me->receive_money(-200);
	atts = ({ target->query("con"), target->query("int"), target->query("str"), target->query("dex") });
	atts = sort_array(atts, -1);
	target_name=target->query("name")+"(" + capitalize(target->query("id")) + ")";
        
    msg = sprintf("Às¤@®³¥X¤@¥»¶À¥Ö¤p¥U¤lÂ½¤F¤@¤U¡AµM«á»¡:\n\n"+
    	"\t%s ¥Ø«eªºµ¥¯Å¬O %d ¯Å¡A¦~ÄÖ¬O %d ·³¡A\n\tÄÝ©ÊÁ`©M¦³ %d ÂI¡A¨ä¤¤³Ì°ªªºÄÝ©Ê¬O %d ÂI¡C\n",
	target_name,target->query("level"),target->query("age"),target->query_total_gift(),atts[0]);
//    msg+=sprintf("%d,%d,%d,%d\n",atts[0],atts[1],atts[2],atts[3]);
    me->start_more(msg);
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
        say( "Às¤@»¡¡R¦hÁÂÅo¡M¯¬±zªº«_ÀI¤@¤Á¶¶§Q¡C\n");

        return 1;
}
/*	add by alickyuen	*/
int do_checkmarry()
{
}
