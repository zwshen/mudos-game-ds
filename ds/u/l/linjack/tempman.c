#include <ansi.h>
#include <dbase.h>
//award eq list
string *file=({"bestaxe","bestfork","bestneck","bestsword","doll",
              "moonshade","lightwaist","fairsword","fairring","fairfist",
              "poorboots","poorcloth","poordagger","superpill"});

inherit F_VENDOR;
inherit NPC;
void gotoinn();
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "¹Ú¹Ò¤Û¼v", ({ "dream illusion","illusion" }));
        set("long", "¥¦¬O¤@­Ó¨­Åé¼v¹³­Y¦³­YµL, ÅÜ¤Æ¸U¤dªº¤Û¼v...¬Ý°_¨Ó¬Û·í¯«¯µ¡C\n");
        set("level",60);
        set("title","¤C°ì¤§¼v");
        set("gender", "¨k©Ê");
        set("race","human");
        set("age",777);
//        set("exp",1000);		//ª±®a±þ¦º·|±o¨ìexp/10 (¥i§K)
        				//«ØÄ³¤£­n¦Û¤v³]exp. ¥Ñ¨t²Î¨M©w
        				//¥H§K¤£¦Pwiz¼gªºmob ·|¥X²{¤Ó¤jªº®t²§
        				
//        set("str",100);			//³]©wÄÝ©Ê(¥i§K)
//        set("dex",80);			//¤]¥i¥H¥u³]©w level
//        set("con",80);			//¨ä¥L¨S³]©wªºÄÝ©Ê¨t²Î´N·|¦Û°Ê²£¥Í,
//        set("int",80);			//§Y¨Ï¬O¬Û¦Pªºlevel¤]·|¦³¤£¦PÄÝ©Ê.
        
//        set("combat_exp",2000);		//¾Ô¼ô(¬ù¦bmob levelªº100­¿¥ª¥k¬°©y)
//        set("evil",20);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set_skill("unarmed",100);		// §Þ¯à(¦Û©w)

//========================ºA«×Ãþ§O=================================
   set("attitude", "friendly");   //¤Íµ½ªº NPC¡C
//   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
//   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C
//   set("attitude", "aggressive"); //¥D°Ê§ðÀ»,¥Í©Ê¦n°«ªºªº NPC¡C
//   set("attitude", "killer");     //¶Ý±þ¦¨©Êªº NPC¡C


//=============================¦Û°Ê°Ê§@=================================
  set("chat_chance",10);  //°Ê§@¾÷²v
  set("chat_msg", ({       //°Ê§@¤º®e
(:command("hmm"):),
(:command("say ¦³°ÝÃDªº¸Ü, ¥i¥H°Ý§Ú(talk with me)³á!"):),
}) );

//===========================°ÝÃD¦^µª==================================
//set("inquiry/name","§Ú¥s°µ§d¥Í¥|...§A¦n");


//=========================¾Ô°«°T®§===========================
//     set("chat_chance_combat", 17);
//     set("chat_msg_combat", ({
//(:command("kick "+this_player()->query("id")):),
// HIR"¤j¼L«Ü¤£²nªº»¡ : ¡u¥i´cªº³Ã¥ë¡ã¡TPK´NPK, ½Ö©È½Ö¡T¡v\n"NOR,
//     }) );


// ±Æµ{°Ê§@

set("schedule",
([
	"00" : (: gotoinn :),
	"06" : (: gotoinn :),
	"12" : (: gotoinn :),
	"18" : (: gotoinn :)
]));
        setup();

//==========================¸Ë³Æ¹D¨ã=============================
//      add_money("coin",200);		//±aªº¿ú
//      carry_object("/u/l/luky/npc/item/bag");
      //carry_object(__DIR__"wp/kaisan_b")->wield();
      //carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk ®É·|°õ¦æ¦¹¨ç¦¡.
{
 command("hmm "+me->query("id") );
 command("say ¦³¦ó¶Q·F? ®@, ¤j·§¬O·Q´«¼úÀy«~ªº§a.");
 command("say ¶â. §i¶D§Ú§A­n®³¦h¤Ö°^Äm­È¥X¨Ó´«, §Ú´N·|µ¹§A¤@¨ÇªF¦è.");
 command("say »ù¥Øªí¦Û¤v¥´ glist ¬Ý¬Ý§a.");
 return 1;
}

void gotoinn()
{
 int a=random(4);
	if(!find_object("/open/world1/tmr/area/hotel")) return;
	if(!find_object("/open/world1/cominging/area/hotel")) return;
	if(!find_object("/open/world1/acme/area/hotel")) return;
	if(!find_object("/open/world2/shengsan/aovandis/room079")) return;
 message_vision("¯«¯µªº¤Û¼v¤@­Ó°{¨­, ¬ðµM®ø¥¢¦b²³¤H¤§«e¡C\n", this_object());
 if( a == 0 ) {
   if( file_name(environment(this_object())) == "/open/world2/shengsan/aovandis/room079" ) a++;
   else this_object()->move("/open/world2/shengsan/aovandis/room079"); 
 }
 if( a == 1 ) {
   if( file_name(environment(this_object())) == "/open/world1/cominging/area/hotel" ) a++;
   else this_object()->move("/open/world1/cominging/area/hotel");
 } 
 if( a == 2 ) {
   if( file_name(environment(this_object())) == "/open/world1/acme/area/hotel" ) a++;
   else this_object()->move("/open/world1/acme/area/hotel");
 }
 if( a == 3 ) {
   if( file_name(environment(this_object())) == "/open/world1/tmr/area/hotel" ) a=0; 
   else this_object()->move("/open/world1/tmr/area/hotel");
 }
 message_vision("¬ðµM¤@­Ó¯«¯µªº¤Û¼v¯¸¦b§A²´«e, §A®Ú¥»¤£ª¾¹D¥¦¬O¦ó®É¥X²{ªº¡C\n", this_object());
}

void init()
{
	::init();
        add_action("do_glist","glist");
	add_action("do_change","change");
}
string item_desc(object ob)
{
	if(ob->query("skill_type")) return HIG+"ªZ¾¹"+NOR;
	else if(ob->query("armor_type")) return HIY+"¨¾¨ã"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"¦^´_"+NOR;
	else return "¹D¨ã";
}
int do_glist(string arg)
{
  string dir,list;
  object awardeq;
  int i,a,awardcost;
  dir = "/open/world1/award/";
  i = sizeof(file);
  list = "\n\n¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{\n";
  list +="¢x ©Ò»Ý°^Äm­È        ºØÃþ   ¥Ø«e¥i¥H§I´«ªºª««~          ¢x\n";   
  list +="¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}\n";
  for(a=0;a<i;a++) {
    if(load_object(dir+file[a])) {
      awardeq = load_object(dir+file[a]);
      awardcost = awardeq->query("needaward");
      list += sprintf("%6d ------------- %4s  %-30s",awardcost,item_desc(awardeq),awardeq->short()); }
    else break;
    list += "\n";
  }
  list +="\n";
  list +=" ª`·N¨Æ¶µ: §I´«¤§«áªºª««~¿ò¥¢°ÝÃD, ¦b¤U·§¤£­t³d. ¦Ó¦¹³B§I´«ªº\n";
  list +="           ª««~, °£¤F¥i¥H¥Ã¤[«O¦s¤§¥~, ¬Ò»P¤@¯ëª««~µL²§, °È¥²\n";
  list +="           ¤p¤ß¦¬ÂÃ! ­n§I´«½Ð¥Î change «ü¥O(©|¥¼§¹¦¨).\n";
  this_player()->start_more(list);
  return 1;
}
int do_change(string arg)
{
  return 0;
}

//======================°Ê§@¤ÏÀ³======================================
/*void relay_emote(object ob, string verb)
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
} */

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
        say("¹Ú¹Ò¤Û¼v»¡¹D¡R¦hÁÂ³o¦ì" + RANK_D->query_respect(who)
                + "¡M¯«©ú¤@©w·|«O¦ö§Aªº¡C\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
